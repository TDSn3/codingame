/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_light.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 19:55:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	choice_light(Data &data, int drone)
{
	if ( (data.drones_player[drone]->pos.y >= 3749 - 300 && data.drones_player[drone]->pos.y <= 3749 + 300)
		|| (data.drones_player[drone]->pos.y >= 6249 - 300 && data.drones_player[drone]->pos.y <= 6249 + 300)
		|| (data.drones_player[drone]->pos.y >= 8749 - 300 && data.drones_player[drone]->pos.y <= 8749 + 300))
	{
		data.drones_player[drone]->round_light[g_round] = 2000;

		return (1);
	}

	data.drones_player[drone]->round_light[g_round] = 800;

	return (0);
}
