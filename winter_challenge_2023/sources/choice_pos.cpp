/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 16:34:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

u_tuple	give_ret_pos(Data &data, Stock &stock, int drone, int i);
u_tuple	ray_casting_pos(Data &data, u_tuple origin, u_tuple target);
void	pos_arround_origin(Data &data, u_tuple origin, int dist, vector<u_tuple> &safe_pos);

u_tuple choice_pos(Data &data, Stock &stock, int drone)
{
	u_tuple			ret;
	
	if (drone == 0)	
	{
		for (size_t i = 0; i < stock.list_pos.size(); i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				ret = give_ret_pos(data, stock, drone, i);

				if (ret.x != -1)
					return (ret);
				else
					continue ;
			}
		}
	}
	else
	{
		for (size_t i = 6; i < stock.list_pos.size(); i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				ret = give_ret_pos(data, stock, drone, i);

				if (ret.x != -1)
					return (ret);
				else
					continue ;
			}
		}
		for (size_t i = 0; i < 6; i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				ret = give_ret_pos(data, stock, drone, i);

				if (ret.x != -1)
					return (ret);
				else
					continue ;
			}
		}	
	}

	return ((u_tuple){{ 0, 0 }});
}

u_tuple	give_ret_pos(Data &data, Stock &stock, int drone, int i)
{
	u_tuple			ret;
	
	if (data.drones_player[drone]->pos.y >= stock.list_pos[i].pos.y - 300 && data.drones_player[drone]->pos.y <= stock.list_pos[i].pos.y + 300)
	{
		stock.list_pos[i].visited[drone] = true;
		return ((u_tuple){{ -1, -1}});	// to continue in parent "for"
	}

	cerr << "cible : " << stock.list_pos[i].pos.x << " " << stock.list_pos[i].pos.y << endl;

	ret = data.get_round_move(
		(u_tuple){{ data.drones_player[drone]->pos.x, data.drones_player[drone]->pos.y }},
		(u_tuple){{ stock.list_pos[i].pos.x, stock.list_pos[i].pos.y }},
		600
	);

	ret = ray_casting_pos(data, (u_tuple){{ data.drones_player[drone]->pos.x, data.drones_player[drone]->pos.y }}, ret);

	cerr << "real cible : " << ret.x << " " << ret.y << endl;

	return (ret);	
}

double distance(u_tuple a, u_tuple b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

u_tuple	round_tuple(u_tuple tuple)
{
	return ((u_tuple){{ round(tuple.x), round(tuple.y) }});
}

u_tuple	ray_casting_pos(Data &data, u_tuple origin, u_tuple target)
{
	vector<u_tuple>	safe_pos;
	u_tuple			closest_pos = {{}};
	double			min_dist;
	double			dist;

	pos_arround_origin(data, origin, 600, safe_pos);

	min_dist = numeric_limits<double>::max();

	for (size_t i = 0; i < safe_pos.size(); ++i)
	{
		dist = distance(safe_pos[i], target);

		if (dist < min_dist)
		{
			min_dist = dist;
			closest_pos = safe_pos[i];
		}
	}

	return (round_tuple(closest_pos));
}

void	pos_arround_origin(Data &data, u_tuple origin, int dist, vector<u_tuple> &safe_pos)
{
	double	angle_step = M_PI / 18;	// 18 = 37 steps
	u_tuple	pos;
	bool	is_safe;
	
	for (double angle = 0; angle < 2 * M_PI; angle += angle_step)
	{	
		pos.x = origin.x + dist * cos(angle);
		pos.y = origin.y + dist * sin(angle);

		is_safe = true;

		for (map<int, s_creature>::iterator it = data.creatures.begin(); it != data.creatures.end(); ++it)
		{
			if (it->second.type == -1 && it->second.visible)
			{
				if (distance(pos, (u_tuple){{ it->second.pos.x, it->second.pos.y }}) < 1041)
				{
					is_safe = false;
					break;
				}
			}
		}

		if (is_safe)
			safe_pos.push_back(pos);
	}	
}
