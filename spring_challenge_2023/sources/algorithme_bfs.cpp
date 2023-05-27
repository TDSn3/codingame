/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_bfs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:04:47 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 00:22:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void algorithme_bfs(Data& stock_data, int origin, int max_dist)
{
	std::vector<bool> visited(stock_data.data_of_cells.size(), false);
	std::queue<std::pair<int, int> > bfs_queue;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;

	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;
		bfs_queue.pop();

		stock_data.data_of_cells[index][8] = dist;
		if (dist < max_dist)
		{
			std::vector<int>	stock;
			
			stock_data.res_by_dist.push_back(0);
			stock_data.egg_by_dist.push_back(0);
			stock_data.pheromone.push_back(0);
			stock_data.conected_to_base.push_back(0);
			stock_data.conexions.push_back(stock);
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
				}
			}
		}
	}
}

std::vector<int>	algorithme_bfs_2(Data& stock_data, int origin, int dest, int max_dist)
{
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	std::vector<int>					previous(stock_data.data_of_cells.size(), -1);
	std::queue<std::pair<int, int> >	bfs_queue;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;

	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;
		bfs_queue.pop();

		if (index == dest)
		{
			std::vector<int>	path;
			int	current;

			current = dest;
		    while (current != origin)
            {
                path.push_back(current);
                current = previous[current];
            }
			path.push_back(origin);
			return (path);
		}
		if (dist < max_dist)
		{
			std::vector<int>	stock;

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
	return (std::vector<int>(0));
}

std::pair<int, int>	find_next_cell_conected(Data& stock_data, int origin, int max_dist)
{
	std::vector<bool> visited(stock_data.data_of_cells.size(), false);
	std::queue<std::pair<int, int> > bfs_queue;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;

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
				if (neighbor != -1 && !visited[neighbor])
				{
					if (stock_data.conected_to_base[neighbor] == true)
						return (std::pair<int, int>(neighbor, dist));
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
				}
			}
		}
	}
	return (std::pair<int, int>(-1, -1));
}
