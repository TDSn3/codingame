/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:45 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/25 13:44:04 by tda-silv         ###   ########.fr       */
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
		if (it->second.visible)
			cerr
				<< it->second.id << " "
				<< " c(" << it->second.color << ")"
				<< " t(" << it->second.type << ")"
				<< " pos(" << it->second.pos.x << ", " << it->second.pos.y << ")"
				<< " v(" << it->second.v.x << ", " << it->second.v.y << ")"
				<< " next(" << it->second.next_pos.x << ", " << it->second.next_pos.y << ")"
				<< " next2(" << it->second.next_next_pos.x << ", " << it->second.next_next_pos.y << ")"
				// << "   my_scan : " << it->second.my_scan_saved
				// << "   foe_scan : " << it->second.foe_scan_saved
				// << "   dist : " << distance(0, it->second.id)
				<< ((it->second.visible) ? (" visible") : (""))
				<< ((it->second.in_light) ? (" flashed") : (" dark"))
				<< endl;
	}
	for (map<int, s_creature> :: iterator it = last_round_creatures.begin(); it != last_round_creatures.end(); it++)
	{
		if (it->second.visible)
		{
			cerr << "last round :" << endl;
			cerr
				<< it->second.id << " "
				<< " c(" << it->second.color << ")"
				<< " t(" << it->second.type << ")"
				<< " pos(" << it->second.pos.x << ", " << it->second.pos.y << ")"
				<< " v(" << it->second.v.x << ", " << it->second.v.y << ")"
				<< " next(" << it->second.next_pos.x << ", " << it->second.next_pos.y << ")"
				<< " next2(" << it->second.next_next_pos.x << ", " << it->second.next_next_pos.y << ")"
				// << "   my_scan : " << it->second.my_scan_saved
				// << "   foe_scan : " << it->second.foe_scan_saved
				// << "   dist : " << distance(0, it->second.id)
				<< ((it->second.visible) ? (" visible") : (""))
				<< ((it->second.in_light) ? (" flashed") : (" dark"))
				<< endl;
		}
	}
}

void	Data::show_drones(void)
{
	for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
	{
		cerr
			<< it->second.id << " : "
			<< it->second.pos.x << " " << it->second.pos.y << " "
			<< enum_to_str(get_drone_zone(it->second.id))
			<< endl;
	}
}

void	Data::update()
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

	map<int, array<int, 3> >	type;	//	[0] type 0,	[1] type 1,	[2] type 2
	map<int, array<int, 4> >	color;	//	[0] pink,	[1] yellow,	[2] green,	[3] blue

	int		potential_score = 0;

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

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		for (size_t i = 0; i < drones.size() ; i++)
		{
			if (it->second.scan_no_saved[i].my_scan_no_saved)
			{
				potential_score += creatures[it->first].type + 1;
				type[i][creatures[it->first].type]++;
				color[i][creatures[it->first].color]++;
				break ;
			}
		}
	}

/* ************************************************************************** */

	int	combo_type[3] = { 0, 0, 0 };
	int	combo_color[4] = { 0, 0, 0, 0 };

	for (map<int, array<int, 3> > :: iterator it = type.begin(); it != type.end(); it++)
	{
		cerr << " > drone " << it->first << " : " << endl;
		for (int i = 0; i < 3; i++)		// type
		{
			cerr << "TYPE " << i << " : " << type[it->first][i] << endl;
			combo_type[i] += type[it->first][i];
		}		
	}
	
	for (int i = 0; i < 3; i++)
	{
		if (combo_type[i] == 4)
		{
			cerr << " FULL TYPE " << i << endl;
			potential_score += 4;
		}
	}
	
	for (map<int, array<int, 4> > :: iterator it = color.begin(); it != color.end(); it++)
	{
		cerr << " > drone " << it->first << " : " << endl;
		for (int i = 0; i < 4; i++)		// color
		{
			cerr << "COLOR " << i << " : " << type[it->first][i] << endl;
			combo_color[i] += type[it->first][i];
		}	
	}

	for (int i = 0; i < 4; i++)
	{
		if (combo_type[i] == 3)
		{
			cerr << " FULL COLOR " << i << endl;
			potential_score += 3;
		}
	}

	cerr << "potential score " << potential_score << endl;

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

			if (it->second.in_light)
			{
				// TODO: look in "else"
			}
			else	// dark
			{
				it->second.next_next_pos = (u_tuple){{
					it->second.next_pos.x + it->second.v.x,
					it->second.next_pos.y + it->second.v.y
				}};
			}
		}
		else
		{
			if (last_round_creatures[it->first].in_light)	// flashed
			{
				last_round_creatures[it->first].next_next_pos = get_round_move(
					last_round_creatures[it->first].next_pos,
					get_nearest_drone(last_round_creatures[it->first].next_pos)->pos,
					540
				);
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
