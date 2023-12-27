/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_light.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/27 14:20:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	choice_light(Data &data, Stock &stock, int player_drone_id, u_tuple pos_drone_end_round)
{
	int	index_list_pos = stock.index_vector_first_visited_false(player_drone_id);

	if (data.drones_player[player_drone_id]->target_creature_pt != nullptr
		&& index_list_pos != -1
		&& (stock.list_pos[player_drone_id][index_list_pos].direction_goal == TOP || g_round > 20))
	{
		double	dist = distance_tuple(data.drones_player[player_drone_id]->target_creature_predict_center, pos_drone_end_round);

		cerr << data.drones_player[player_drone_id]->id << " : -> " << data.drones_player[player_drone_id]->target_creature_pt->id << " : " << dist << "( " << dist * 2 << " < 4000 ? )" << endl;
		if (dist * 2 <= 4000)
		{
			data.drones_player[player_drone_id]->round_light[g_round] = 2000;

			return (1);
		}
	}

	if (index_list_pos != -1 && stock.list_pos[player_drone_id][index_list_pos].direction_goal == BOT)
	{
		if ((pos_drone_end_round.y >= 1400 && pos_drone_end_round.y <= 2000 && g_round > 10) 
			|| (pos_drone_end_round.y >= 3200 && pos_drone_end_round.y <= 3800)
			|| (pos_drone_end_round.y >= 5000 && pos_drone_end_round.y <= 5600)
			|| (pos_drone_end_round.y >= 6800 && pos_drone_end_round.y <= 8600))
		{
			data.drones_player[player_drone_id]->round_light[g_round] = 2000;

			return (1);
		}		
	}

	if (index_list_pos != -1 && stock.list_pos[player_drone_id][index_list_pos].direction_goal == TOP)
	{
		if ((pos_drone_end_round.y >= 3200 && pos_drone_end_round.y <= 3800)
				|| (pos_drone_end_round.y >= 5000 && pos_drone_end_round.y <= 5600)
				|| (pos_drone_end_round.y >= 6800 && pos_drone_end_round.y <= 8600))
		{
			data.drones_player[player_drone_id]->round_light[g_round] = 2000;

			return (1);
		}
	}

	data.drones_player[player_drone_id]->round_light[g_round] = 800;

	return (0);
}