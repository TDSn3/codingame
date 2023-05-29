/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_from_base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:25:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 23:38:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int &index,
	int &dist,
	int j);




void	bfs_from_base(Data &stock_data)
{
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);

	bfs_queue.push(std::pair<int, int>(stock_data.my_base_index , 0));
	visited[stock_data.my_base_index] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;

		bfs_queue.pop();
		if (dist < 20)
			for (int j = 0; j < 6; j++)
				visit_neighbors(stock_data, bfs_queue, visited, index, dist, j);
	}
}




void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int &index,
	int &dist,
	int j)
{
	int	neighbor;

	neighbor = stock_data.data_of_cells[index][j];
	if (neighbor != -1 && !visited[neighbor])
	{
		bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
		visited[neighbor] = true;

//		cerr << neighbor;
		if (stock_data.data_of_cells[neighbor][9] > 0 && stock_data.data_of_cells[neighbor][6] > 0)
		{
			std::pair<int, std::vector<int> > stock = find_next_beacon(stock_data, neighbor, 10);
			if (stock.first != -1 && stock.first != stock_data.my_base_index)
			{
//				cerr << " | " << stock.first << " ---> " << neighbor << " (1)";
				my_line(stock_data, stock.first, neighbor);
			}
			else
			{
//				cerr << " | " << stock_data.my_base_index << " ---> " << neighbor << " (2) " << stock.first << " " << stock.second.size();
				my_line(stock_data, stock_data.my_base_index, neighbor);
			}
		}
//		cerr << endl;
	}
}
