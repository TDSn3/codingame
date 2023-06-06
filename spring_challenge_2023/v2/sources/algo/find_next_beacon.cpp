/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_beacon.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:12:07 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/04 23:46:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	fnb_visit_neighbors(Data &stock_data,std::queue<std::pair<int, int> > &bfs_queue, std::vector<bool> &visited, std::vector<int> &path, std::vector<std::pair<int, std::vector<int> > > &list_beacons, int &index, int &dist);

std::pair<int, std::vector<int> >	find_next_beacon(Data &stock_data, int origin, int index_base, int max_dist)
{
	std::queue<std::pair<int, int> >				bfs_queue;
	std::vector<bool>								visited(stock_data.data_of_cells.size(), false);
	std::vector<int>								path(stock_data.data_of_cells.size(), -1);
	std::vector<std::pair<int, std::vector<int> > >	list_beacons;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		if (dist < max_dist)
		{			
			fnb_visit_neighbors(stock_data, bfs_queue, visited, path, list_beacons, index, dist);

			if (!list_beacons.empty())
			{
				for (size_t k = 0; k < list_beacons.size(); k++)
				{
					int	path_neighbor = list_beacons[k].first;

					path[list_beacons[k].first] = index;
					while (path_neighbor != origin)
					{
						list_beacons[k].second.push_back(path_neighbor);
						path_neighbor = path[path_neighbor];
					}
					list_beacons[k].second.push_back(path_neighbor);
				}
				int	save_index = -1;
				int	size_dist_from_base = 1000;

				for (size_t k = 0; k < list_beacons.size(); k++)
				{
					if (stock_data.dist_from_my_base[index_base][ list_beacons[k].first ] < size_dist_from_base)
					{
						save_index = k;
						size_dist_from_base = stock_data.dist_from_my_base[index_base][ list_beacons[k].first ];
					}
				}
				return (list_beacons[save_index]);
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}

void	fnb_visit_neighbors(Data &stock_data,std::queue<std::pair<int, int> > &bfs_queue, std::vector<bool> &visited, std::vector<int> &path, std::vector<std::pair<int, std::vector<int> > > &list_beacons, int &index, int &dist)
{
	int					neighbor;

	for (int j = 0; j < 6; j++)
	{
		neighbor = stock_data.data_of_cells[index][j];

		if (neighbor != -1 && !visited[neighbor] && stock_data.check_opp_base(neighbor) == -1)
		{
			// [12] beacon this loop, [13] connected my base index
			if (stock_data.data_of_cells[neighbor][12] == 1 || stock_data.data_of_cells[neighbor][13] > -1)
				list_beacons.push_back(std::pair<int, std::vector<int> >(neighbor, std::vector<int>()));
			bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
			visited[neighbor] = true;
			path[neighbor] = index;
		}
	}
}
