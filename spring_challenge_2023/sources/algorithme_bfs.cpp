/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithme_bfs.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 11:04:47 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 00:23:39 by tda-silv         ###   ########.fr       */
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
			stock_data.power_cell.push_back(0);
			stock_data.beacon_this_loop.push_back(0);
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
						return (std::pair<int, int>(neighbor, dist + 1));
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
				}
			}
		}
	}
	return (std::pair<int, int>(-1, -1));
}

std::pair<int, std::vector<int> >	find_next_egg(Data& stock_data, int origin, int max_dist)
{
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<int>					path(stock_data.data_of_cells.size(), -1);

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
					if (stock_data.data_of_cells[neighbor][6] == 1)
					{
						std::vector<int>	ret_path;
						int					path_neighbor = neighbor;

//						cerr << "neighbor["<< neighbor << "] " << index << " FIND !"<< endl;

						path[neighbor] = index;
						while (path_neighbor != origin)
						{
//							cerr << path_neighbor << " " << endl;
							ret_path.push_back(path_neighbor);
							path_neighbor = path[path_neighbor];
						}
						ret_path.push_back(path_neighbor);
//						cerr << path_neighbor << " " << endl;
	
						return (std::pair<int, std::vector<int> >(neighbor, ret_path));
					}
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
//					cerr << "neighbor["<< neighbor << "] " << index << endl;
					path[neighbor] = index;
				}
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}

std::pair<int, std::vector<int> >	find_next_res(Data& stock_data, int origin, int max_dist)
{
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<int>					path(stock_data.data_of_cells.size(), -1);

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
					if (stock_data.data_of_cells[neighbor][6] == stock_data.egg_and_cryst)
					{
						std::vector<int>	ret_path;
						int					path_neighbor = neighbor;

//						cerr << "neighbor["<< neighbor << "] " << index << " FIND !"<< endl;

						path[neighbor] = index;
						while (path_neighbor != origin)
						{
//							cerr << path_neighbor << " " << endl;
							ret_path.push_back(path_neighbor);
							path_neighbor = path[path_neighbor];
						}
						ret_path.push_back(path_neighbor);
//						cerr << path_neighbor << " " << endl;
	
						return (std::pair<int, std::vector<int> >(neighbor, ret_path));
					}
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
//					cerr << "neighbor["<< neighbor << "] " << index << endl;
					path[neighbor] = index;
				}
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}

std::pair<int, std::vector<int> >	find_next_beacon(Data& stock_data, int origin, int max_dist)
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
			std::vector<int>	stock;
			
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];

				if (neighbor != -1 && !visited[neighbor])
				{
					if (stock_data.beacon_this_loop[neighbor])
						list_beacons.push_back(std::pair<int, std::vector<int> >(neighbor, std::vector<int>()));
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					path[neighbor] = index;
				}
			}
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
					if (stock_data.data_of_cells[ list_beacons[k].first ][8] < size_dist_from_base)
					{
						save_index = k;
						size_dist_from_base = stock_data.data_of_cells[ list_beacons[k].first ][8];
					}
				}
				return (list_beacons[save_index]);
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}

std::pair<int, std::vector<int> >	find_base(Data& stock_data, int origin, int max_dist)
{
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<int>					path(stock_data.data_of_cells.size(), -1);

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
				if (neighbor != -1 && !visited[neighbor] && stock_data.power_cell[neighbor])
				{
					if (neighbor == stock_data.my_base_index)
					{
						std::vector<int>	ret_path;
						int					path_neighbor = neighbor;

						path[neighbor] = index;
						while (path_neighbor != origin)
						{
							ret_path.push_back(path_neighbor);
							path_neighbor = path[path_neighbor];
						}
						ret_path.push_back(path_neighbor);	
						return (std::pair<int, std::vector<int> >(neighbor, ret_path));
					}
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					path[neighbor] = index;
				}
			}
		}
	}
	return (std::pair<int, std::vector<int> >(-1, std::vector<int>()));
}
