/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_light.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/21 15:46:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	choice_light(Data &data)
{
	(void) data;

	if ((data.drones_player[0]->pos.x == 2499 && data.drones_player[0]->pos.y == 3749)
		|| (data.drones_player[0]->pos.x == 2499 && data.drones_player[0]->pos.y == 6249)
		|| (data.drones_player[0]->pos.x == 2499 && data.drones_player[0]->pos.y == 8749)
		|| (data.drones_player[0]->pos.x == 7499 && data.drones_player[0]->pos.y == 3749)
		|| (data.drones_player[0]->pos.x == 7499 && data.drones_player[0]->pos.y == 6249)
		|| (data.drones_player[0]->pos.x == 7499 && data.drones_player[0]->pos.y == 8749))
	{
		return (1);
	}
	return (0);
}
