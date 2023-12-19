/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 23:04:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

// class CompareCreaturesDistance
// {
// 	public:

// 		CompareCreaturesDistance(int param) : drone_id(param) {}

// 		int drone_id;

// 		bool operator () (const map<int, s_creature> :: iterator &it1, const map<int, s_creature> :: iterator &it2) const
// 		{
// 			return (it1->second.distance_my_drone[drone_id] < it2->second.distance_my_drone[drone_id]);
// 		}
// };

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
				<< data.my_drone[0].id << " : "
				<< data.my_drone[0].x << " "
				<< data.my_drone[0].y << "   "
				<< data.my_drone[0].battery
				<< endl;

			string	radar = data.radar_direction(0);
			int		x;	// rl
			int		y;	// tb

			cerr << radar << endl;

			if (radar == "TL")
			{
				x = data.my_drone[0].x - 600;
				y = data.my_drone[0].y - 600;
			}
			else if (radar == "TR")
			{
				x = data.my_drone[0].x + 600;
				y = data.my_drone[0].y - 600;
			}
			else if (radar == "BL")
			{
				x = data.my_drone[0].x - 600;
				y = data.my_drone[0].y + 600;
			}
			else
			{
				x = data.my_drone[0].x + 600;
				y = data.my_drone[0].y + 600;
			}

			if (data.no_scaned())
			{
				x = data.my_drone[0].x;
				y = data.my_drone[0].y - 600;
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

			// vector<map<int, s_creature> :: iterator>	creatures_sort_by_dist;

			// for	(map<int, s_creature> :: iterator it = data.creatures.begin(); it != data.creatures.end(); it++)
			// {
			// 	creatures_sort_by_dist.push_back(it);
			// }

			// CompareCreaturesDistance	comp(0);

			// sort(creatures_sort_by_dist.begin(), creatures_sort_by_dist.end(), comp);

			// for (size_t j = 0; j < creatures_sort_by_dist.size(); j++)
			// {
			// 	cerr
			// 		<< creatures_sort_by_dist[j]->second.distance_my_drone[0]
			// 		<< "   >" << creatures_sort_by_dist[j]->second.my_scan
			// 		<< endl;

			// 	if (creatures_sort_by_dist[j]->second.my_scan == false)
			// 	{
			// 		instruction_move(creatures_sort_by_dist[j]->second.x, creatures_sort_by_dist[j]->second.y, 0 );
			// 		break ;
			// 	}
			// }

			// instruction_wait(1);
		}

		data.reset();
	}
}
