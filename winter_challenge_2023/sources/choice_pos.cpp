/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2024/01/03 09:54:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	is_scaned_no_save(map<int, s_creature> :: iterator it)
{
	for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
	{
		if (it2->second.my_scan_no_saved)
			return (true);	// is scaned but not saved
	}	
	return (false);	// is not scaned
}

u_tuple get_drone_predict_center_target(Data &data, int player_drone_id, e_tb direction_goal)
{
	double		dist =  numeric_limits<double>::max();
	u_tuple		ret = {{ -1, -1 }};
	s_creature	*creature = nullptr;
	
	(void) direction_goal;
	
	for (map<int, s_creature> :: iterator it = data.creatures.begin(); it != data.creatures.end(); it++)
	{
		if (it->second.type == -1
			|| it->second.type != data.get_drone_player_simple_zone(player_drone_id)
			|| !it->second.radar_signal
			|| it->second.predict_center_target_by_drone
			|| is_scaned_no_save(it)
			|| it->second.my_scan_saved
			|| data.get_nearest_player_drone(it->second.predict_center)->id != data.drones_player[player_drone_id]->id)
			continue ;

		double temp = distance_tuple(it->second.predict_center, data.drones_player[player_drone_id]->pos);

		if (g_round < 20 && data.get_type_scanned(2) > 1 && it->second.type == 2)
			continue ;

		if (g_round < 20 && temp * 2 > 1200
			&& (it->second.predict_center.y > data.drones_player[player_drone_id]->pos.x && it->second.type != 2))
			continue ;

		if (temp < dist)
		{
			creature = &it->second;
			dist = temp;
			ret = it->second.predict_center;
		}
	}

	if (ret.x != -1)
	{
		creature->predict_center_target_by_drone = true;

		data.drones_player[player_drone_id]->use_predict_last_round = true;
		data.drones_player[player_drone_id]->target_creature = true;
		data.drones_player[player_drone_id]->target_creature_predict_center = ret;
		data.drones_player[player_drone_id]->target_creature_pt = creature;
	}
	else
	{
		data.drones_player[player_drone_id]->use_predict_last_round = false;
		data.drones_player[player_drone_id]->target_creature = false;
		data.drones_player[player_drone_id]->target_creature_predict_center = (u_tuple){{ -1, -1 }};
		data.drones_player[player_drone_id]->target_creature_pt = nullptr;
	}

	return (ret);
}

u_tuple choice_pos(Data &data, Stock &stock, int player_drone_id)
{
	u_tuple	pos = {{ 0, 0}};
	e_tb	direction_goal = BOT;
	
	for (size_t i = 0; i < stock.list_pos[player_drone_id].size(); i++)
	{
		if (!stock.list_pos[player_drone_id][i].visited)
		{
			direction_goal = stock.list_pos[player_drone_id][i].direction_goal;
			pos = stock.list_pos[player_drone_id][i].pos;
			break ;
		}
	}

	if (direction_goal == TOP)
	{
		u_tuple	temp = get_drone_predict_center_target(data, player_drone_id, direction_goal);

		if (temp.x != -1)
			pos = temp;
	}

	return (get_real_pos(data, player_drone_id, pos));	
}
