/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/23 11:08:45 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::Data(void)
{
	s_creature	creature = {};

	cin >> creature_count; cin.ignore();

	for (int i = 0; i < creature_count; i++)
	{
		cin >> creature.id >> creature.color >> creature.type; cin.ignore();
		creatures[creature.id] = creature;
	}
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::~Data(void)
{
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	Data::show_creatures(void)
{
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.id == 16)
			cerr
				<< it->second.id << " : "
				<< "   color : " << it->second.color
				<< "   type : " << it->second.type
				<< "   x : " << it->second.pos.x
				<< "   y : " << it->second.pos.y
				<< "   vx : " << it->second.v.x
				<< "   vy : " << it->second.v.y
				<< "   next_x : " << it->second.next_pos.x
				<< "   next_y : " << it->second.next_pos.y
				<< "   next2_x : " << it->second.next_next_pos.x
				<< "   next2_y : " << it->second.next_next_pos.y
				// << "   my_scan : " << it->second.my_scan_saved
				// << "   foe_scan : " << it->second.foe_scan_saved
				// << "   dist : " << distance(0, it->second.id)
				<< ((it->second.visible) ? (" visible") : (""))
				<< ((it->second.in_light) ? (" flashed") : (" dark"))
				<< std::endl;
	}
	for (map<int, s_creature> :: iterator it = last_round_creatures.begin(); it != last_round_creatures.end(); it++)
	{
		if (it->second.id == 16)
		{
			cerr << "last round" << endl;
			cerr
				<< it->second.id << " : "
				<< "   color : " << it->second.color
				<< "   type : " << it->second.type
				<< "   x : " << it->second.pos.x
				<< "   y : " << it->second.pos.y
				<< "   vx : " << it->second.v.x
				<< "   vy : " << it->second.v.y
				<< "   next_x : " << it->second.next_pos.x
				<< "   next_y : " << it->second.next_pos.y
				<< "   next2_x : " << it->second.next_next_pos.x
				<< "   next2_y : " << it->second.next_next_pos.y
				// << "   my_scan : " << it->second.my_scan_saved
				// << "   foe_scan : " << it->second.foe_scan_saved
				// << "   dist : " << distance(0, it->second.id)
				<< ((it->second.visible) ? (" visible") : (""))
				<< ((it->second.in_light) ? (" flashed") : (" dark"))
				<< std::endl;
		}
	}
}

void	Data::update(void)
{
	int 	creature_id;
	int		drone_id;
	string	radar;

	cin >> my_score; cin.ignore();
	cin >> foe_score; cin.ignore();

/* ************************************************************************** */
/*                                                                            */
/*   Créature scaned														  */
/*                                                                            */
/* ************************************************************************** */

	cin >> my_scan_count; cin.ignore();

	for (int i = 0; i < my_scan_count; i++)
	{
		cin >> creature_id; cin.ignore();
		creatures[creature_id].my_scan_saved = true;
	}

	cin >> foe_scan_count; cin.ignore();

	for (int i = 0; i < foe_scan_count; i++)
	{
		cin >> creature_id; cin.ignore();
		creatures[creature_id].foe_scan_saved = true;
	}

/* ************************************************************************** */
/*                                                                            */
/*   Drone																	  */
/*                                                                            */
/* ************************************************************************** */

	cin >> my_drone_count; cin.ignore();

	for (int i = 0; i < my_drone_count; i++)
	{
		cin
			>> drone_id
			>> drones[drone_id].pos.x
			>> drones[drone_id].pos.y
			>> drones[drone_id].emergency
			>> drones[drone_id].battery;
		cin.ignore();
		drones[drone_id].id = drone_id;
		drones[drone_id].owner = PLAYER;
		if (g_round == 0)
			drones[drone_id].round_light[g_round] = 0;
	}

	cin >> foe_drone_count; cin.ignore();

	for (int i = 0; i < foe_drone_count; i++)
	{
		cin
			>> drone_id
			>> drones[drone_id].pos.x
			>> drones[drone_id].pos.y
			>> drones[drone_id].emergency
			>> drones[drone_id].battery;
		cin.ignore();
		drones[drone_id].id = drone_id;
		drones[drone_id].owner = FOE;
		drones[drone_id].round_light[g_round] = -1;
	}

/* ************************************************************************** */

	cin >> drone_scan_count; cin.ignore();

	for (int i = 0; i < drone_scan_count; i++)
	{
		cin >> drone_id >> creature_id; cin.ignore();

		if (drones[drone_id].owner == PLAYER)
		{
			creatures[creature_id].scan_no_saved[drone_id].my_scan_no_saved = true;
		}
		else // FOE
		{
			creatures[creature_id].scan_no_saved[drone_id].foe_scan_no_saved = true;
		}
	}

/* ************************************************************************** */

	cin >> visible_creature_count; cin.ignore();

	for (int i = 0; i < visible_creature_count; i++)
	{
		cin
			>> creature_id
			>> creatures[creature_id].pos.x
			>> creatures[creature_id].pos.y
			>> creatures[creature_id].v.x
			>> creatures[creature_id].v.y;
		cin.ignore();
		creatures[creature_id].id = creature_id;
		creatures[creature_id].visible = true;
		creatures[creature_id].in_light = is_in_light(creatures[creature_id].pos);
	}

	cin >> radar_blip_count; cin.ignore();

	for (int i = 0; i < radar_blip_count; i++)
	{
		cin
			>> drone_id
			>> creature_id
			>> radar;
		cin.ignore();
		if (radar == "TL")
			creatures[creature_id].radar[drone_id] = TL;
		else if (radar == "TR")
			creatures[creature_id].radar[drone_id] = TR;
		else if (radar == "BL")
			creatures[creature_id].radar[drone_id] = BL;
		else
			creatures[creature_id].radar[drone_id] = BR;
	}

/* ************************************************************************** */

	if (g_round == 0)
	{
		for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
		{
			if (it->second.owner == PLAYER)
				drones_player.push_back(&it->second);
		}

		for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
			it->second.next_next_pos = (u_tuple){{ -1, -1 }};
	}

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.visible)
		{
			it->second.next_pos = (u_tuple){{
				it->second.pos.x + it->second.v.x,
				it->second.pos.y + it->second.v.y
			}};

			if (!it->second.in_light)	// dark
			{
				it->second.next_next_pos = (u_tuple){{
					it->second.next_pos.x + it->second.v.x,
					it->second.next_pos.y + it->second.v.y
				}};
			}
		}
	}
}

s_drone	*Data::get_nearest_drone(u_tuple origin)
{
	double	min_dist = numeric_limits<double>::max();
	double	dist;
	s_drone	*ret;

	for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
	{
		dist = distance_tuple(origin, it->second.pos);

		if (dist < min_dist)
		{
			min_dist = dist;
			ret = &it->second;
		}
	}

	return (ret);
}

bool	Data::is_in_light(u_tuple origin)
{
	for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
		if (distance_tuple(origin, it->second.pos) <= it->second.round_light[(g_round == 0 ? 0 : g_round - 1)])
			return (true);
	
	return (false);
}

void	Data::reset(void)
{	
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{		
		last_round_creatures[it->first] = it->second;

		it->second.visible = false;
		it->second.pos.x = -1;
		it->second.pos.y = -1;
		it->second.v.x = -1;
		it->second.v.y = -1;
		it->second.next_pos.x = -1;
		it->second.next_pos.y = -1;
		it->second.next_next_pos.x = -1;
		it->second.next_next_pos.y = -1;
		it->second.my_scan_saved = false;
		it->second.foe_scan_saved = false;
		
		for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
		{
			it2->second.my_scan_no_saved = false;
			it2->second.foe_scan_no_saved = false;
		}

		it->second.in_light = false;
	}
}

/*   MÉTHODE PRIVATE   ****************************************************** */


/* ************************************************************************** */
