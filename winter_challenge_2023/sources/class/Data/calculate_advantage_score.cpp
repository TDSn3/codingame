/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_advantage_score.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 10:53:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 19:21:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

void	Data::calculate_advantage_score(void)
{
	// cerr << "TYPE :\n"; 

	// for (it_drones it = drones.begin(); it != drones.end(); it++)
	// {
		// cerr << "[" << it->second.id << "] ";
		// for (int type = 0; type < 3; type++)
		// {
		// 	if (type == 0)
		// 		cerr << " (0_tentacle) ";
		// 	if (type == 1)
		// 		cerr << " (1_fish) ";
		// 	if (type == 2)
		// 		cerr << " (2_pincer) ";

		// 	cerr << " : " << is_full_scanned(it->first, type).second << (is_full_scanned(it->second.owner, type).first ? "*" : "") << "  │  ";

			// drones[it->first].potential_score += stock_is_full_scanned.second * (type + 1);
		// }

		// cerr << endl;
	// }

	// cerr << "COLOR :\n";

	// for (it_drones it = drones.begin(); it != drones.end(); it++)
	// {
		// cerr << "[" << it->second.id << "] ";
		// for (int color = 0; color < 4; color++)
		// {
			// if (color == 0)
			// 	cerr << " (0_pink) ";
			// if (color == 1)
			// 	cerr << " (1_yellow) ";
			// if (color == 2)
			// 	cerr << " (2_green) ";
			// if (color == 3)
			// 	cerr << " (3_blue) ";

			// cerr << " : " << is_full_scanned(it->first, color, 0).second << (is_full_scanned(it->second.owner, color, 0).first ? "*" : "") << "  │  ";

			// drones[it->first].potential_score += stock_is_full_scanned.second * (color + 1);
		// }

		// cerr << endl;
	// }

/* ************************************************************************** */

	vector<s_drone*>	sort_by_pos_y_drones;
	bool				first_y = true;

	for (it_drones it = drones.begin(); it != drones.end(); it++)
		sort_by_pos_y_drones.push_back(&it->second);

	sort(sort_by_pos_y_drones.begin(), sort_by_pos_y_drones.end(), s_compare_drone_pos_y());

	for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
	{
		for (size_t i = 0; i < sort_by_pos_y_drones.size(); i++)
		{
			if (is_scanned(sort_by_pos_y_drones[i]->id, it->second.id))
			{
				sort_by_pos_y_drones[i]->potential_point += it->second.type + 1;
				if (first_y && it->second.my_scan_saved == false && it->second.foe_scan_saved == false)
				{
					sort_by_pos_y_drones[i]->first_scan_potential_point += it->second.type + 1;
					first_y = false;
				}
			}
		}

		first_y = true;
	}

/* ************************************************************************** */

	bool			first_combo_type[3] = { false, false, false };
	bool			first_combo_color[4] = { false, false, false, false };
	array<int, 3>	player_combo_type = { 0, 0, 0 };
	array<int, 4>	player_combo_color = { 0, 0, 0, 0 };
	array<int, 3>	foe_combo_type = { 0, 0, 0 };
	array<int, 4>	foe_combo_color = { 0, 0, 0, 0 };

	for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.type == -1)
			continue ;
		
		if (it->second.my_scan_saved)
		{
			player_combo_type[it->second.type]++;
			player_combo_color[it->second.color]++;
		}
		if (it->second.foe_scan_saved)
		{
			foe_combo_type[it->second.type]++;
			foe_combo_color[it->second.color]++;			
		}		
	}

	for (size_t type = 0; type < 3; type++)
	{
		if (player_combo_type[type] == 4 || foe_combo_type[type] == 4)
		{
			first_combo_type[type] = true;
			// cerr << " ! type " << type << " is alredy full saved !\n";
		}
	}

	for(size_t color = 0; color < 4; color++)
	{
		if (player_combo_color[color] == 3 || foe_combo_color[color] == 3)
		{
			first_combo_color[color] = true;
			// cerr << " ! color " << color << " is alredy full saved !\n";
		}
	}

	for (size_t i = 0; i < sort_by_pos_y_drones.size(); i++)
	{		
		array<int, 3>	cpy_player_combo_type(player_combo_type);
		array<int, 3>	cpy_foe_combo_type(foe_combo_type);

		for (int type = 0; type < 3; type++)
		{
			if (sort_by_pos_y_drones[i]->owner == PLAYER && player_combo_type[type] == 4)
				continue ;
			if (sort_by_pos_y_drones[i]->owner == FOE && foe_combo_type[type] == 4)
				continue ;

			for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
			{
				if (it->second.type != type)
					continue ;

				if (is_scanned(sort_by_pos_y_drones[i]->id, it->second.id))
				{
					if (sort_by_pos_y_drones[i]->owner == PLAYER && it->second.my_scan_saved == false)
						cpy_player_combo_type[it->second.type]++;
					if (sort_by_pos_y_drones[i]->owner == FOE && it->second.foe_scan_saved == false)
						cpy_foe_combo_type[it->second.type]++;
				}
			}

			if ((sort_by_pos_y_drones[i]->owner == PLAYER && cpy_player_combo_type[type] == 4)
				|| (sort_by_pos_y_drones[i]->owner == FOE && cpy_foe_combo_type[type] == 4))
			{
				sort_by_pos_y_drones[i]->potential_point_combo += 4;
			}
			if ((cpy_player_combo_type[type] == 4 || cpy_foe_combo_type[type] == 4) && first_combo_type[type] == false)
			{
				sort_by_pos_y_drones[i]->first_potential_point_combo += 4;
				first_combo_type[type] = true;
				continue ;
			}
		}

		array<int, 4>	cpy_player_combo_color(player_combo_color);
		array<int, 4>	cpy_foe_combo_color(foe_combo_color);

		for(int color = 0; color < 4; color++)
		{
			if (sort_by_pos_y_drones[i]->owner == PLAYER && player_combo_color[color] == 3)
				continue ;
			if (sort_by_pos_y_drones[i]->owner == FOE && foe_combo_color[color] == 3)
				continue ;

			for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
			{
				if (it->second.color != color)
					continue ;
				
				if (is_scanned(sort_by_pos_y_drones[i]->id, it->second.id))
				{
					if (sort_by_pos_y_drones[i]->owner == PLAYER && it->second.my_scan_saved == false)
						cpy_player_combo_color[it->second.color]++;
					if (sort_by_pos_y_drones[i]->owner == FOE && it->second.foe_scan_saved == false)
						cpy_foe_combo_color[it->second.color]++;
				}
			}

			if ((sort_by_pos_y_drones[i]->owner == PLAYER && cpy_player_combo_color[color] == 3)
				|| (sort_by_pos_y_drones[i]->owner == FOE && cpy_foe_combo_color[color] == 3))
			{
				sort_by_pos_y_drones[i]->potential_point_combo += 3;
			}
			if ((cpy_player_combo_color[color] == 3 || cpy_foe_combo_color[color] == 3) && first_combo_color[color] == false)
			{
				sort_by_pos_y_drones[i]->first_potential_point_combo += 3;
				first_combo_color[color] = true;
				continue ;
			}
		}
	}

/* ************************************************************************** */

	// cerr << "───────\n";
	
	for (size_t i = 0; i < sort_by_pos_y_drones.size(); i++)
	{
		sort_by_pos_y_drones[i]->total_potential_point = sort_by_pos_y_drones[i]->potential_point + sort_by_pos_y_drones[i]->first_scan_potential_point + sort_by_pos_y_drones[i]->potential_point_combo + sort_by_pos_y_drones[i]->first_potential_point_combo;

		// cerr << "[" << sort_by_pos_y_drones[i]->id << "] ("
		// << sort_by_pos_y_drones[i]->potential_point << "  +  "
		// << sort_by_pos_y_drones[i]->first_scan_potential_point << "  =  "
		// << sort_by_pos_y_drones[i]->potential_point + sort_by_pos_y_drones[i]->first_scan_potential_point << ")  +  ("
		// << sort_by_pos_y_drones[i]->potential_point_combo << "  +  "
		// << sort_by_pos_y_drones[i]->first_potential_point_combo << "  =  "
		// << sort_by_pos_y_drones[i]->potential_point_combo + sort_by_pos_y_drones[i]->first_potential_point_combo << ")  =  "
		// << sort_by_pos_y_drones[i]->total_potential_point
		// << endl;
	}
}
