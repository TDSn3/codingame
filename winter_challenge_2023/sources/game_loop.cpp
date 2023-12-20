/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 09:38:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	game_loop(Data &data)
{
	while (1)
	{
		data.update();
		// data.show_creatures();

		for (int i = 0; i < data.my_drone_count; i++)
		{

			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;

			cerr
				<< data.drones[0].id << " : "
				<< data.drones[0].x << " "
				<< data.drones[0].y << "   "
				<< data.drones[0].battery
				<< endl;

			e_radar	radar = data.radar_direction(0);
			int		x;	// rl
			int		y;	// tb

			radar & T ? (cerr << "T") : (cerr << "B");
			radar & L ? (cerr << "L") : (cerr << "R");
			cerr << endl;

			if (radar == TL)
			{
				x = data.drones[0].x - 600;
				y = data.drones[0].y - 600;
			}
			else if (radar == TR)
			{
				x = data.drones[0].x + 600;
				y = data.drones[0].y - 600;
			}
			else if (radar == BL)
			{
				x = data.drones[0].x - 600;
				y = data.drones[0].y + 600;
			}
			else	// BR
			{
				x = data.drones[0].x + 600;
				y = data.drones[0].y + 600;
			}

			if (data.no_scaned())
			{
				x = data.drones[0].x;
				y = data.drones[0].y - 600;
			}

			if (x < 0)
				x = 0;
			if (y < 0)
				y = 0;
			if (x > 9999)
				x = 9999;
			if (y > 9999)
				y = 9999;

			instruction_move(x, y, 0);

			// instruction_wait(1);
		}

		data.reset();
	}
}
