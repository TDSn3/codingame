/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 11:20:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

bool	compare_distance(double dist_a, double dist_b)
{
	return (dist_a < dist_b);
}

void	game_loop(Data &data)
{
	while (1)
	{
		data.update();
		data.show_creatures();

		for (int i = 0; i < data.my_drone_count; i++)
		{

			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;

			cerr
				<< data.my_drone[0].id << " : "
				<< data.my_drone[0].x << " "
				<< data.my_drone[0].y << "   "
				<< data.my_drone[0].battery
				<< endl;



			vector<map<int, s_creature> :: iterator>	creatures_sort_by_dist;

			for	(map<int, s_creature> :: iterator it = data.creatures.begin(); it != data.creatures.end(); it++)
			{
				creatures_sort_by_dist.push_back(it);
			}

			sort(creatures_sort_by_dist.begin(), creatures_sort_by_dist.end());

			wait(1);
		}
	}
}
