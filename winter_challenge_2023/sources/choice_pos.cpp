/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 14:02:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

u_tuple choice_pos(Data &data)
{
	e_radar radar = data.biggest_radar_direction(0);
	u_tuple	pos;	// x(rl) y(tb)

	radar &T ? (cerr << "T") : (cerr << "B");
	radar &L ? (cerr << "L") : (cerr << "R");
	cerr << endl;

	if (radar == TL)
	{
		pos.x = data.drones[0].pos.x - 600;
		pos.y = data.drones[0].pos.y - 600;
	}
	else if (radar == TR)
	{
		pos.x = data.drones[0].pos.x + 600;
		pos.y = data.drones[0].pos.y - 600;
	}
	else if (radar == BL)
	{
		pos.x = data.drones[0].pos.x - 600;
		pos.y = data.drones[0].pos.y + 600;
	}
	else // BR
	{
		pos.x = data.drones[0].pos.x + 600;
		pos.y = data.drones[0].pos.y + 600;
	}

	if (data.no_scaned())
	{
		pos.x = data.drones[0].pos.x;
		pos.y = data.drones[0].pos.y - 600;
	}

	if (pos.x < 0)
		pos.x = 0;
	if (pos.y < 0)
		pos.y = 0;
	if (pos.x > 9999)
		pos.x = 9999;
	if (pos.y > 9999)
		pos.y = 9999;

	return (pos);
}
