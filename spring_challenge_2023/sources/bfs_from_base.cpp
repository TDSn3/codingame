/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_from_base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:25:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/01 13:39:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	empty_list_queue(std::vector<std::queue<std::pair<int, int> > >	list_queue);

void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int base,
	int &index,
	int &dist,
	int j);



void	bfs_from_base(Data &stock_data)
{
	std::vector<std::queue<std::pair<int, int> > >	list_queue;
	std::vector<bool>								visited(stock_data.data_of_cells.size(), false);
	std::vector<int>								index2;
	std::vector<int>								dist2;

	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
	{
		list_queue.push_back(std::queue<std::pair<int, int> >());
		list_queue[i].push(std::pair<int, int>(stock_data.list_base_index[i] , 0));
		index2.push_back(-1);
		dist2.push_back(0);
		visited[stock_data.list_base_index[i]] = true;
	}

	while (!empty_list_queue(list_queue))
	{
		for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
		{
			if (!list_queue[i].empty())
			{
				index2[i] = list_queue[i].front().first;
				dist2[i] = list_queue[i].front().second;

				list_queue[i].pop();
				for (size_t j = 0; j < 6; j++)
					visit_neighbors(stock_data, list_queue[i], visited, stock_data.list_base_index[i], index2[i], dist2[i], j);
			}
		}
	}
}




int	empty_list_queue(std::vector<std::queue<std::pair<int, int> > >	list_queue)
{
	for (size_t i = 0; i < list_queue.size(); i++)
	{
		if (!list_queue[i].empty())
			return (0);
	}
	return (1);
}

void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int base,
	int &index,
	int &dist,
	int j)
{
	int	neighbor;

	neighbor = stock_data.data_of_cells[index][j];
	if (neighbor != -1 && !visited[neighbor] && !stock_data.check_opp_base(stock_data, neighbor))
	{
		bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
		visited[neighbor] = true;

		if ((stock_data.data_of_cells[neighbor][9] > 0)
			&& ((stock_data.data_of_cells[neighbor][6] > stock_data.egg_and_cryst
			&& stock_data.data_of_cells[neighbor][6] <= stock_data.limit_egg) || stock_data.signal_for_crystal > 0))
		{			
			//	assigne priority cell = 1
			std::pair<int, std::vector<int> > stock = find_next_beacon(stock_data, neighbor, 10, base);

			if (stock.first != -1)
			{
				cerr << stock.first << " ---> " << neighbor << "\n";
				my_line(stock_data, stock.first, neighbor, base, stock.second);
			}
			if (stock_data.data_of_cells[neighbor][6] == 2)
				stock_data.signal_for_crystal--;
		}
	}
}
