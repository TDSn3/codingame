/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:45 by tda-silv          #+#    #+#             */
/*   Updated: 2024/01/03 09:49:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::Data(void)
{}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	*this = src;
}

Data::Data(const Data &src, map<int, s_drone> &new_drones)	// simulate input whith new drones position
{
	*this = src;
	drones = new_drones;

	// show_drones();

	vector<s_drone*>	sort_by_pos_y_drones;

	for (it_drones it = drones.begin(); it != drones.end(); it++)
		sort_by_pos_y_drones.push_back(&it->second);

	sort(sort_by_pos_y_drones.begin(), sort_by_pos_y_drones.end(), s_compare_drone_pos_y());
	
	for (size_t i = 0; i < sort_by_pos_y_drones.size(); i++)
	{
		sort_by_pos_y_drones[i]->potential_point = 0;
		sort_by_pos_y_drones[i]->first_scan_potential_point = 0;
		sort_by_pos_y_drones[i]->potential_point_combo = 0;
		sort_by_pos_y_drones[i]->first_potential_point_combo = 0;
		sort_by_pos_y_drones[i]->total_potential_point = 0;

		calculate_advantage_score();

		// cerr << "drone[" << sort_by_pos_y_drones[i]->id << "] : " << sort_by_pos_y_drones[i]->total_potential_point << endl;

		if (sort_by_pos_y_drones[i]->pos.y <= 500)
		{
			if (sort_by_pos_y_drones[i]->owner == PLAYER)
				my_score += sort_by_pos_y_drones[i]->total_potential_point;
			else	// FOE
				foe_score += sort_by_pos_y_drones[i]->total_potential_point;

			for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
			{
				if (is_scanned(sort_by_pos_y_drones[i]->id, it->second.id))
				{
					e_drone_owner	owner = sort_by_pos_y_drones[i]->owner;
					
					if (owner == PLAYER)
						it->second.my_scan_saved = true;
					else	// FOE
						it->second.foe_scan_saved = true;

					for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
					{
						if (drones[it2->first].owner == owner)
						{
							if (owner == PLAYER)
								it2->second.my_scan_no_saved = false;
							else
								it2->second.foe_scan_no_saved = false;
						}
					}
				}
			}
		}
	}

	// cerr << "my_score : " << my_score << endl;
	// cerr << "foe_score : " << foe_score << endl;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::~Data(void)
{}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

Data	&Data::operator = (const Data &src)
{
	if (this != &src)
	{
		creature_count = src.creature_count;
		creatures = src.creatures;
		last_round_creatures = src.last_round_creatures;
		drones = src.drones;
		my_score = src.my_score;
		foe_score = src.foe_score;
		my_scan_score_not_saved = src.my_scan_score_not_saved;
		my_scan_count = src.my_scan_count;
		foe_scan_count = src.foe_scan_count;
		my_drone_count = src.my_drone_count;
		foe_drone_count = src.foe_drone_count;
		drone_scan_count = src.drone_scan_count;
		visible_creature_count = src.visible_creature_count;
		radar_blip_count = src.radar_blip_count;

		drones_player.clear();
		for (std::vector<s_drone*>::const_iterator it = src.drones_player.begin(); it != src.drones_player.end(); ++it)
			if (*it != nullptr)
				drones_player.push_back(&drones[(*it)->id]);
	}

	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	Data::round_zero_init(void)
{
	s_creature	creature = {};

	cin >> creature_count; cin.ignore();

	for (int i = 0; i < creature_count; i++)
	{
		cin >> creature.id >> creature.color >> creature.type; cin.ignore();
		creatures[creature.id] = creature;
		creatures[creature.id].broken_simetric = false;
	}	
}

void	Data::show_creatures(void)
{
	std::stringstream	ss;
	
	cerr
		<< setw(4) << "id " << "│"
		<< setw(4) << "co " << "│"
		<< setw(4) << "ty " << "│"
		<< setw(12) << "pos " << "│"
		<< setw(9) << "visible " << "│"
		<< setw(9) << "light " << "│"
		<< " radar"
		<< endl;
	
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		ss << it->second.pos.x << ", " << it->second.pos.y;

		cerr
			<< setw(3) << it->second.id << " │"
			<< setw(3) << it->second.color << " │"
			<< setw(3) << it->second.type << " │"
			<< setw(11) << ss.str() << " │"
			<< setw(8) << ((it->second.visible) ? ("visible") : ("")) << " │"
			<< setw(8) << ((it->second.in_light) ? ("flashed") : ("dark"));

		cerr << " │ ";

		for (map<int, e_radar> :: iterator it2 = it->second.radar.begin(); it2 !=  it->second.radar.end(); it2++ )
			cerr << "[" << it2->first << "] " << enum_to_str(it2->second) << " │ " ;
		
		cerr << (it->second.radar_signal ? "" : "NO SIGNAL");
		
		// cerr << (it->second.broken_simetric ? " BROKEN SIMETRIC " : "");
		
		cerr << endl;

		ss.str("");
		ss.clear();
	}
}

void	Data::show_drones(void)
{
	for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
	{
		cerr
			<< "drone[" << it->second.id << "] "
			<< it->second.pos.x << ", " << it->second.pos.y << " "
			<< enum_to_str(get_drone_zone(it->first)) << " "
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

	cerr << "round : " << g_round << endl;

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
		{
			drones[drone_id].round_light[g_round] = 0;
			drones[drone_id].use_predict_last_round = false;
			drones[drone_id].potential_point = 0;
			drones[drone_id].first_scan_potential_point = 0;
			drones[drone_id].potential_point_combo = 0;
			drones[drone_id].first_potential_point_combo = 0;
			drones[drone_id].total_potential_point = 0;
		}
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
		if (g_round == 0)
		{
			drones[drone_id].potential_point = 0;
			drones[drone_id].first_scan_potential_point = 0;
			drones[drone_id].potential_point_combo = 0;
			drones[drone_id].first_potential_point_combo = 0;
			drones[drone_id].total_potential_point = 0;
		}
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
		creatures[creature_id].radar_signal = true;
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

/* ************************************************************************** */	
		
		array<u_tuple, 4>								final_radar_predict;

		final_radar_predict[0] = (u_tuple){{ 0, 0 }};
		final_radar_predict[1] = (u_tuple){{ 0, 0 }};
		final_radar_predict[2] = (u_tuple){{ 0, 0 }};
		final_radar_predict[3] = (u_tuple){{ 0, 0 }};

		map<int, pair<e_radar, array<u_tuple, 2> > >	radar_predict;
			
		for (map<int, e_radar> :: iterator it2 = it->second.radar.begin(); it2 !=  it->second.radar.end(); it2++ )
		{				
			radar_predict[it2->first].first = it2->second;
			
			radar_predict[it2->first].second[0].x = drones[it2->first].pos.x;
			radar_predict[it2->first].second[0].y = get_limite_zone(it->second).first;

			radar_predict[it2->first].second[1].x = drones[it2->first].pos.x;
			radar_predict[it2->first].second[1].y = get_limite_zone(it->second).second;

			if (it2->second == TL || it2->second == TR)
			{
				if (drones[it2->first].pos.y < radar_predict[it2->first].second[1].y)
					radar_predict[it2->first].second[1].y = drones[it2->first].pos.y;
			}
			else if (it2->second == BL || it2->second == BR)
			{
				if (drones[it2->first].pos.y > radar_predict[it2->first].second[0].y)
					radar_predict[it2->first].second[0].y = drones[it2->first].pos.y;
			}
		}

		for (map<int, pair<e_radar, array<u_tuple, 2> > > :: iterator it3 = radar_predict.begin(); it3 != radar_predict.end(); it3++)
		{			
			if (it3->second.first == TL)
			{
				if (final_radar_predict[0].y < it3->second.second[0].y)
					final_radar_predict[0].y = it3->second.second[0].y;

				if (final_radar_predict[1].x > it3->second.second[0].x || final_radar_predict[1].x == 0)
					final_radar_predict[1].x = it3->second.second[0].x;
				if (final_radar_predict[1].y < it3->second.second[0].y)
					final_radar_predict[1].y = it3->second.second[0].y;

				if (final_radar_predict[2].x > it3->second.second[1].x || final_radar_predict[2].x == 0)
					final_radar_predict[2].x = it3->second.second[1].x;
				if (final_radar_predict[2].y > it3->second.second[1].y || final_radar_predict[2].y == 0)
					final_radar_predict[2].y = it3->second.second[1].y;

				if (final_radar_predict[3].y > it3->second.second[1].y || final_radar_predict[3].y == 0)
					final_radar_predict[3].y = it3->second.second[1].y;
			}
			else if (it3->second.first == TR)
			{
				if (final_radar_predict[0].x < it3->second.second[0].x)
					final_radar_predict[0].x = it3->second.second[0].x;
				if (final_radar_predict[0].y < it3->second.second[0].y)
					final_radar_predict[0].y = it3->second.second[0].y;

				if (final_radar_predict[1].x == 0)
					final_radar_predict[1].x = 9999;
				if (final_radar_predict[1].y < it3->second.second[0].y)
					final_radar_predict[1].y = it3->second.second[0].y;

				if (final_radar_predict[2].x == 0)
					final_radar_predict[2].x = 9999;
				if (final_radar_predict[2].y > it3->second.second[1].y || final_radar_predict[2].y == 0)
					final_radar_predict[2].y = it3->second.second[1].y;

				if (final_radar_predict[3].x < it3->second.second[1].x)
					final_radar_predict[3].x = it3->second.second[1].x;
				if (final_radar_predict[3].y > it3->second.second[1].y || final_radar_predict[3].y == 0)
					final_radar_predict[3].y = it3->second.second[1].y;
			}
			else if (it3->second.first == BL)	// OK
			{
				if (final_radar_predict[0].y < it3->second.second[0].y)
					final_radar_predict[0].y = it3->second.second[0].y;

				if (final_radar_predict[1].x > it3->second.second[0].x || final_radar_predict[1].x == 0)
					final_radar_predict[1].x = it3->second.second[0].x;
				if (final_radar_predict[1].y < it3->second.second[0].y)
					final_radar_predict[1].y = it3->second.second[0].y;

				if (final_radar_predict[2].x > it3->second.second[1].x || final_radar_predict[2].x == 0)
					final_radar_predict[2].x = it3->second.second[1].x;
				if (final_radar_predict[2].y > it3->second.second[1].y || final_radar_predict[2].y == 0)
					final_radar_predict[2].y = it3->second.second[1].y;

				if (final_radar_predict[3].y > it3->second.second[1].y || final_radar_predict[3].y == 0)
					final_radar_predict[3].y = it3->second.second[1].y;
			}
			else if (it3->second.first == BR)
			{
				if (final_radar_predict[0].x < it3->second.second[0].x)
					final_radar_predict[0].x = it3->second.second[0].x;
				if (final_radar_predict[0].y < it3->second.second[0].y)
					final_radar_predict[0].y = it3->second.second[0].y;

				if (final_radar_predict[1].x == 0)
					final_radar_predict[1].x = 9999;
				if (final_radar_predict[1].y < it3->second.second[0].y)
					final_radar_predict[1].y = it3->second.second[0].y;

				if (final_radar_predict[2].x == 0)
					final_radar_predict[2].x = 9999;
				if (final_radar_predict[2].y > it3->second.second[1].y || final_radar_predict[2].y == 0)
					final_radar_predict[2].y = it3->second.second[1].y;

				if (final_radar_predict[3].x < it3->second.second[1].x)
					final_radar_predict[3].x = it3->second.second[1].x;
				if (final_radar_predict[3].y > it3->second.second[1].y || final_radar_predict[3].y == 0)
					final_radar_predict[3].y = it3->second.second[1].y;	
			}			
		}

		// cerr << it->second.id << " : ";
		// cerr << "[0]" << final_radar_predict[0].x << ", " << final_radar_predict[0].y << "   ";
		// cerr << "[1]" << final_radar_predict[1].x << ", " << final_radar_predict[1].y << "   ";
		// cerr << "[2]" << final_radar_predict[2].x << ", " << final_radar_predict[2].y << "   ";
		// cerr << "[3]" << final_radar_predict[3].x << ", " << final_radar_predict[3].y << endl;

		it->second.radar_predict = final_radar_predict;
		it->second.predict_center = (u_tuple){{
			round((final_radar_predict[0].x + final_radar_predict[2].x) / 2.0),
			round((final_radar_predict[0].y + final_radar_predict[2].y) / 2.0)
		}};
		it->second.predict_center_target_by_drone = false;
	}

/* ************************************************************************** */

	calculate_advantage_score();

	pair<int, int>	scores = calculate_score_at_drones_pos_zero();

	cerr << "calculate PLAYER score at drones pos zero : " << scores.first << endl;
	cerr << "calculate FOE score at drones pos zero : " << scores.second << endl;

/* ************************************************************************** */

	// for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	// {
	// 	if (it->second.type == -1 || it->second.pos.x == -1)
	// 		continue ;

	// 	for (map<int, s_drone> :: iterator it2 = drones.begin(); it2 != drones.end(); it2++)
	// 	{
	// 		if (distance_tuple(it->second.pos, it2->second.pos) < 1400)
	// 		{
	// 			it->second.broken_simetric = true;
	// 			break ;
	// 		}
	// 	}
	// }
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

s_drone	*Data::get_nearest_player_drone(u_tuple origin)
{
	double	min_dist = numeric_limits<double>::max();
	double	dist;
	s_drone	*ret;

	for (map<int, s_drone> :: iterator it = drones.begin(); it != drones.end(); it++)
	{
		if (it->second.owner == PLAYER)
		{
			dist = distance_tuple(origin, it->second.pos);

			if (dist < min_dist)
			{
				min_dist = dist;
				ret = &it->second;
			}
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

bool	Data::is_creature_already_scanned(int id_creature)
{
	return (creatures[id_creature].my_scan_saved = true || creatures[id_creature].foe_scan_saved == true);
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
		it->second.radar_signal = false;
		
		for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
		{
			it2->second.my_scan_no_saved = false;
			it2->second.foe_scan_no_saved = false;
		}

		it->second.in_light = false;
	}

	for (it_drones it = drones.begin(); it != drones.end(); it++)
	{
		it->second.potential_point = 0;
		it->second.first_scan_potential_point = 0;
		it->second.potential_point_combo = 0;
		it->second.first_potential_point_combo = 0;
		it->second.total_potential_point = 0;
	}

}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
