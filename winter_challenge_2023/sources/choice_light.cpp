/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_light.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/24 12:15:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	choice_light(Data &data, Stock &stock, int drone)
{
	int	index_list_pos = stock.index_vector_first_visited_false(drone);

	if (index_list_pos != -1 && stock.list_pos[drone][index_list_pos].direction_goal == BOT)
	{
		if ((data.drones_player[drone]->pos.y >= 1600 && data.drones_player[drone]->pos.y <= 2199 && g_round > 10) 
			|| (data.drones_player[drone]->pos.y >= 2850 && data.drones_player[drone]->pos.y <= 3449)
			|| (data.drones_player[drone]->pos.y >= 5350 && data.drones_player[drone]->pos.y <= 5949)
			|| (data.drones_player[drone]->pos.y >= 8448 && data.drones_player[drone]->pos.y <= 9647))
		{
			data.drones_player[drone]->round_light[g_round] = 2000;

			return (1);
		}		
	}

	if (index_list_pos != -1 && stock.list_pos[drone][index_list_pos].direction_goal == TOP)
	{
		if ((data.drones_player[drone]->pos.y >= 4049 && data.drones_player[drone]->pos.y <= 4648)
			|| (data.drones_player[drone]->pos.y >= 6549 && data.drones_player[drone]->pos.y <= 7148)
			|| (data.drones_player[drone]->pos.y >= 8448 && data.drones_player[drone]->pos.y <= 9647))
		{
			data.drones_player[drone]->round_light[g_round] = 2000;

			return (1);
		}
	}

	// if (data.drones_player[drone]->battery >= 10
	// 	&& ())
	// {
	// 	data.drones_player[drone]->round_light[g_round] = 2000;

	// 	return (1);	
	// }

	data.drones_player[drone]->round_light[g_round] = 800;

	return (0);
}