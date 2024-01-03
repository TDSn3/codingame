/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_objective_pos.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:11:54 by tda-silv          #+#    #+#             */
/*   Updated: 2024/01/03 09:43:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

// target_zone_3 = (u_tuple){{ new_x, 7700 }};

u_tuple	get_objective_pos(list<Game> &games, Data &data, int player_drone_id)
{
	// vector<s_creature*>	sort_by_predict_center_creatures;

	// for (Data::it_creatures it = data.creatures.begin(); it != data.creatures.end(); it++)
	// {
	// 	if (it->second.type == -1)
	// 		continue ;
	// 	sort_by_predict_center_creatures.push_back(&it->second);
	// }

	// sort(sort_by_predict_center_creatures.begin(), sort_by_predict_center_creatures.end(), s_compare_creature_predict_center(data.drones_player[player_drone_id]->pos));

	// for (size_t i = 0; i < sort_by_predict_center_creatures.size(); i++)
	// {
	// 	cerr << data.drones_player[player_drone_id]->id << " : " << sort_by_predict_center_creatures[i]->id << endl;
	// }

	// return ((u_tuple){{ -1, -1 }});
}
