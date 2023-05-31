/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_beacon.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:12:07 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/31 13:11:40 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	assignation_priority(Data& stock_data, int	path_neighbor);

std::pair<int, std::vector<int> >	find_next_beacon(Data& stock_data, int origin, int max_dist, int index_base)
{
	std::queue<std::pair<int, int> >				bfs_queue;
	std::vector<bool>								visited(stock_data.data_of_cells.size(), false);
	std::vector<int>								path(stock_data.data_of_cells.size(), -1);
	std::vector<std::pair<int, std::vector<int> > >	list_beacons;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	cerr << "base : " << index_base << " origin : " << origin << endl;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		if (dist < max_dist)
		{
			std::vector<int>	stock;
			
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];

				if (neighbor != -1 && !visited[neighbor] && !stock_data.check_opp_base(stock_data, neighbor))
				{
					if (stock_data.beacon_this_loop[neighbor] || stock_data.conected_to_base[neighbor])
						list_beacons.push_back(std::pair<int, std::vector<int> >(neighbor, std::vector<int>()));
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					path[neighbor] = index;
				}
			}
			if (!list_beacons.empty())
			{
				//	parcours tous les beacons
				for (size_t k = 0; k < list_beacons.size(); k++)
				{
					int	path_neighbor = list_beacons[k].first;

					path[list_beacons[k].first] = index;
					while (path_neighbor != origin)
					{
						assignation_priority(stock_data, path_neighbor);
						list_beacons[k].second.push_back(path_neighbor);
						path_neighbor = path[path_neighbor];
					}
					assignation_priority(stock_data, path_neighbor);
					list_beacons[k].second.push_back(path_neighbor);
				}
				int	save_index = -1;
				int	size_dist_from_base = 1000;

				for (size_t k = 0; k < list_beacons.size(); k++)
				{
					if (stock_data.dist_from_base[index_base][ list_beacons[k].first ] < size_dist_from_base)
					{
						save_index = k;
						size_dist_from_base = stock_data.dist_from_base[index_base][ list_beacons[k].first ];
					}
				}
				return (list_beacons[save_index]);
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}

void	assignation_priority(Data& stock_data, int	path_neighbor)
{
	if (stock_data.priority_cell[path_neighbor] < 1)
		stock_data.priority_cell[path_neighbor] = 1;
}
