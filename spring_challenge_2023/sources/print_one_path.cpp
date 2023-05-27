/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_path.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:56:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 00:32:39 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_one_path(Data &stock_data, int &origin)
{
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	int									signal_stop;
	int 								neighbor;

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	signal_stop = 0;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;
		bfs_queue.pop();

		if (dist < 20)
		{
			for (int j = 0; j < 6; j++)
			{
				neighbor = stock_data.data_of_cells[index][j];
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					if ((neighbor == stock_data.my_base_index
							&& origin != stock_data.my_base_index)
						|| (stock_data.data_of_cells[neighbor][6] == 2
							&& stock_data.data_of_cells[neighbor][9] > 0))
					{
						if ((stock_data.conected_to_base[origin] == 1
								&& stock_data.conected_to_base[neighbor] == 0
								&& ((origin != stock_data.my_base_index && stock_data.data_of_cells[neighbor][8] >= dist + 1)
										|| (origin == stock_data.my_base_index)))
							|| (stock_data.conected_to_base[origin] == 0
								&& stock_data.conected_to_base[neighbor] == 1))
						{
							std::pair<int, int> stock = find_next_cell_conected(stock_data, origin, 10);

							if (stock.first != -1 && stock_data.conected_to_base[stock.first] && stock.first != neighbor)
								continue ;
							else
							{
								my_line(stock_data, origin, neighbor, dist + 1);
								stock_data.conexions[origin].push_back(neighbor);
								cerr << origin << " ---> " << neighbor << endl;
								if (stock_data.conected_to_base[origin] == 1)
									stock_data.conected_to_base[neighbor] = 1;
								else
									stock_data.conected_to_base[origin] = 1;
								signal_stop = 1;
							}
						}
					}
				}
			}
			if (signal_stop)
				return ;
		}
	}
}
