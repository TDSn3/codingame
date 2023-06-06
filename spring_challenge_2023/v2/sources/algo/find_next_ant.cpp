/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_next_ant.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:12:07 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/03 17:46:17 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

// front	next ant
// back		origin

std::vector<int>	find_next_ant(Data &stock_data, int origin, int max_dist)
{
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	std::vector<int>					previous(stock_data.data_of_cells.size(), -1);

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		if (dist < max_dist)
		{
			if (stock_data.data_of_cells[index][MY_ANTS] > 0
				&&  stock_data.calculate_number_ant_desired(index) != stock_data.data_of_cells[index][MY_ANTS]
				&& index != origin)
			{
				std::vector<int>	path;
				int					current;

				current = index;
				while (current != origin)
				{
					path.push_back(current);
					current = previous[current];
				}
				path.push_back(origin);
				return (path);
			}
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];

				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					previous[neighbor] = index;
				}
			}
		}
	}
	return (std::vector<int>());
}
