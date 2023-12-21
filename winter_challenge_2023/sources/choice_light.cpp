/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_light.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:15:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/21 16:06:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	choice_light(Data &data, int drone)
{
	if ((data.drones_player[drone]->pos.x == 2499 && data.drones_player[drone]->pos.y == 3749)
		|| (data.drones_player[drone]->pos.x == 2499 && data.drones_player[drone]->pos.y == 6249)
		|| (data.drones_player[drone]->pos.x == 2499 && data.drones_player[drone]->pos.y == 8749)
		|| (data.drones_player[drone]->pos.x == 7499 && data.drones_player[drone]->pos.y == 3749)
		|| (data.drones_player[drone]->pos.x == 7499 && data.drones_player[drone]->pos.y == 6249)
		|| (data.drones_player[drone]->pos.x == 7499 && data.drones_player[drone]->pos.y == 8749))
	{
		return (1);
	}
	return (0);
}
