/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_pos.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:50:43 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/27 19:55:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	check_proximity_during_movement(u_tuple monster_pos, u_tuple monster_pos_next, u_tuple drone_pos, u_tuple drone_pos_next);
u_tuple	ray_casting_pos(Data &data, u_tuple origin, u_tuple target);
u_tuple	round_tuple(u_tuple tuple);
void	safe_pos_arround_origin(Data &data, u_tuple origin, int dist, vector<u_tuple> &safe_pos);

u_tuple	get_real_pos(Data &data, int player_drone_id, u_tuple pos)
{
	u_tuple	ret;
	s_drone	&drone_player = *data.drones_player[player_drone_id];

	cerr <<  drone_player.id << " : cible : " << pos.x << ", " << pos.y << "   ";

	ret = data.get_round_move(
		(u_tuple){{ drone_player.pos.x, drone_player.pos.y }},
		(u_tuple){{ pos.x, pos.y }},
		600
	);

	ret = ray_casting_pos(data, (u_tuple){{ drone_player.pos.x, drone_player.pos.y }}, ret);

	cerr << "real cible : " << ret.x << ", " << ret.y << endl;

	if (ret.y < 500)
		ret.y = 500;

	return (ret);	
}

u_tuple	ray_casting_pos(Data &data, u_tuple origin, u_tuple target)
{
	vector<u_tuple>	safe_pos;
	u_tuple			closest_pos = {{}};
	double			min_dist;
	double			dist;

	safe_pos_arround_origin(data, origin, 600, safe_pos);

	if (safe_pos.size() == 0)	// TODO: if safe_pos.size() == 0
		cerr << "NO SAFE ZONE ! " << origin.x << " " << origin.y << endl;

	min_dist = numeric_limits<double>::max();

	for (size_t i = 0; i < safe_pos.size(); ++i)
	{
		dist = distance_tuple(safe_pos[i], target);

		if (dist < min_dist)
		{
			min_dist = dist;
			closest_pos = safe_pos[i];
		}
	}

	return (round_tuple(closest_pos));
}

void	safe_pos_arround_origin(Data &data, u_tuple origin, int dist, vector<u_tuple> &safe_pos)
{
	double	angle_step = M_PI / 16;	// 18 = 37 steps
	u_tuple	pos;
	bool	is_safe;
	
	for (double angle = 0; angle < 2 * M_PI; angle += angle_step)
	{	
		pos.x = round(origin.x + dist * cos(angle));
		pos.y = round(origin.y + dist * sin(angle));

		is_safe = true;

		// cerr << "pos : " << pos.x << ", " << pos.y << " | ";

		for (map<int, s_creature>::iterator it = data.creatures.begin(); it != data.creatures.end(); ++it)
		{
			if (it->second.type != -1)	// ignore if is not a monster
				continue ;
			
			if (!check_proximity_during_movement(it->second.pos, it->second.next_pos, origin, pos))
			{
				// cerr << "check_proximity_during_movement";
				is_safe = false;
				break;				
			}

			if (!it->second.visible
				&& data.last_round_creatures[it->first].visible
				&& !data.last_round_creatures[it->first].in_light)	// dark
			{
				if (distance_tuple(pos, data.last_round_creatures[it->first].next_next_pos) < 1040 + 5)
				{
					// cerr << "2";
					is_safe = false;
					break;
				}
			}

			if (!it->second.visible
				&& data.last_round_creatures[it->first].visible
				&& data.last_round_creatures[it->first].in_light)	// flashed
			{
				if (distance_tuple(pos, data.last_round_creatures[it->first].next_next_pos) < 1040 + 5)
				{
					// cerr << "3";
					is_safe = false;
					break;
				}
			}
			
		}

		// cerr << endl;

		if (is_safe)
			safe_pos.push_back(pos);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*   L'interpolation des positions de deux objets à l'instant t est			  */
/*   une méthode pour estimer où se trouvent deux objets à un moment donné	  */
/*   pendant leur mouvement d'un point à un autre.							  */
/*   Cette méthode est particulièrement utile lorsque vous avez un point	  */
/*   de départ et un point d'arrivée et que vous voulez savoir où se trouve	  */
/*   l'objet à un moment intermédiaire de son trajet.						  */
/*                                                                            */
/* ************************************************************************** */
bool	check_proximity_during_movement(u_tuple monster_pos, u_tuple monster_pos_next, u_tuple drone_pos, u_tuple drone_pos_next)
{
	int		steps = 100;
	double	danger_dist = 540.0;

	for (int i = 0; i <= steps; i++)
	{
		double t = static_cast<double>(i) / steps;

		// Interpole les positions du monstre et du drone à l'instant t

		u_tuple interpolated_monster_pos = {{
			monster_pos.x + t * (monster_pos_next.x - monster_pos.x),
			monster_pos.y + t * (monster_pos_next.y - monster_pos.y)
		}};

		u_tuple interpolated_drone_pos = {{
			drone_pos.x + t * (drone_pos_next.x - drone_pos.x),
			drone_pos.y + t * (drone_pos_next.y - drone_pos.y)
		}};

		if (distance_tuple(interpolated_monster_pos, interpolated_drone_pos) <= danger_dist)
			return (false);
	}

	return (true);
}

u_tuple	round_tuple(u_tuple tuple)
{
	return ((u_tuple){{ round(tuple.x), round(tuple.y) }});
}
