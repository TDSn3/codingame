/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_bfs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:04:47 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/31 22:55:55 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	assignation_priority2(Data& stock_data, int	path_neighbor);

void	distance_all_cell_from_base(Data& stock_data, int origin, int max_dist, int index_base)
{
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		stock_data.data_of_cells[index][8] = dist;
		stock_data.dist_from_base[index_base][index] = dist;
		if (dist < max_dist)
		{
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

std::vector<int>	find_path_origin_neighbor(Data& stock_data, int origin, int dest, int max_dist)
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
		if (index == dest)
		{
			std::vector<int>	path;
			int					current;

			current = dest;
			while (current != origin)
			{
				if (stock_data.priority_cell[current] < 1)
					stock_data.priority_cell[current] = 1;
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
				if (neighbor != -1 && !visited[neighbor] && !stock_data.check_opp_base(stock_data, neighbor))
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

int	check_base(Data& stock_data, int index)
{	
	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
		if (stock_data.list_base_index[i] == index)
			return (index);
	return (-1);
}

std::vector<int>	find_next_base(Data& stock_data, int origin, int max_dist)
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
			if (check_base(stock_data, index) > -1)
			{
				std::vector<int>	path;
				int					current;

				current = check_base(stock_data, index);
				while (current != origin)
				{
//					assignation_priority2(stock_data, current);
					path.push_back(current);
					current = previous[current];
				}
//				assignation_priority2(stock_data, current);
				path.push_back(origin);
				return (path);
			}
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];

				if (neighbor != -1 && !visited[neighbor] && !stock_data.check_opp_base(stock_data, neighbor) && (stock_data.priority_cell[neighbor] /**/|| stock_data.data_of_cells[neighbor][10] > 2/**/))
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

//void	assignation_priority2(Data& stock_data, int	path_neighbor)
//{
//	if (stock_data.priority_cell[path_neighbor] < 1)
//		stock_data.priority_cell[path_neighbor] = 1;
//	if (stock_data.data_of_cells[path_neighbor][10] < stock_data.data_of_cells[path_neighbor][11])
//	{
//		cerr << "===== PRIORITY : " << path_neighbor << " : " << stock_data.data_of_cells[path_neighbor][10] << " < " << stock_data.data_of_cells[path_neighbor][11] << endl;
//		stock_data.priority_cell[path_neighbor] += 5;
//	}
//	else if (stock_data.priority_cell[path_neighbor] > 1)
//		stock_data.priority_cell[path_neighbor] -= 1;
//}
