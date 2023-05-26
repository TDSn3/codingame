/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_bfs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:04:47 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 16:39:29 by tda-silv         ###   ########.fr       */
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
		cerr << index << " = " << dist << endl;

		if (dist < max_dist)
		{
			std::vector<int>	stock;
			
			stock_data.res_by_dist.push_back(0);
			stock_data.egg_by_dist.push_back(0);
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

std::pair<int, int>	algorithme_bfs_stop_first(Data& stock_data, int origin, int max_dist)
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

		cerr << index << " = " << dist << endl;

		if (dist < max_dist)
		{
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					if (stock_data.data_of_cells[neighbor][6] == 2 && stock_data.data_of_cells[neighbor][9] > 0 && stock_data.data_of_cells[neighbor][8] < 20)
						return (std::pair<int, int>(neighbor, dist + 1));
				}
			}
		}
	}
	return (std::pair<int, int>(-1, -1));
}

std::pair<int, int>	algorithme_bfs_stop_first_2(Data& stock_data, int origin, int max_dist)
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

		cerr << index << " = " << dist << endl;

		if (dist < max_dist)
		{
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.dof_short_by_dist[index][j];
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					if (stock_data.dof_short_by_dist[neighbor][6] == 2 && stock_data.dof_short_by_dist[neighbor][9] > 0 && stock_data.dof_short_by_dist[neighbor][8] < 20)
						return (std::pair<int, int>(neighbor, dist + 1));
				}
			}
		}
	}
	return (std::pair<int, int>(-1, -1));
}