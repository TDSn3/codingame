/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_path.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:56:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 13:53:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	visit_six_next_cell(
	Data &stock_data,
	int &origin,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int &signal_stop,
	int &index,
	int &dist,
	int j);

void	print_one_path(Data &stock_data, int &origin)
{
	std::queue<std::pair<int, int> >	bfs_queue;
	std::vector<bool>					visited(stock_data.data_of_cells.size(), false);
	int									signal_stop;

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
				if (visit_six_next_cell(stock_data, origin, bfs_queue, visited, signal_stop, index, dist, j))
					return ;
		}
		if (signal_stop && dist == signal_stop)
			return ;
	}
}

int	visit_six_next_cell(
	Data &stock_data,
	int &origin,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int &signal_stop,
	int &index,
	int &dist,
	int j)
{
	int	neighbor;
	
	neighbor = stock_data.data_of_cells[index][j];
//	si la cell origin ou neighbor n'est pas vide et que neighbor n'est pas déjà visité
	if (neighbor != -1 && index != -1 && !visited[neighbor])
	{
		bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
		visited[neighbor] = true;
//		si la cell visité est la base et que l'origine n'est pas la base
//		ou
//		si la cell visité est un crystal et que la cell visité à des ressources
		if ((neighbor == stock_data.my_base_index
				&& origin != stock_data.my_base_index)
			|| (stock_data.data_of_cells[neighbor][6] > stock_data.egg_and_cryst
				&& stock_data.data_of_cells[neighbor][9] > 0))
		{
//			cerr << origin << " ---> " << neighbor  << " ? "<< "(" << index << ") " << dist + 1 <<  endl;
//			si l'origine est connecté et que la cell visité ne l'est pas et que
//				l'origine n'est pas la base et que
//				la distance entre la cell visité et la base est supp ou égale à la dist de l'origine avec la cell visité
//				ou
//				que l'origine sois la base
//			ou
//			que l'origine n'est pas connecté et que la cell visité l'est et que
//				la cell visité n'est pas la base et que
//				la distance entre l’origine et la base est inf ou égale à la dist de l'origine avec la cell visité
//				ou
//				que l'origine sois la base
			if ((stock_data.conected_to_base[origin] == 1
					&& stock_data.conected_to_base[neighbor] == 0
					&& ((origin != stock_data.my_base_index && stock_data.data_of_cells[neighbor][8] >= dist + 1)
							|| (origin == stock_data.my_base_index)))
				|| ((stock_data.conected_to_base[origin] == 0
					&& stock_data.conected_to_base[neighbor] == 1)
					&& ((neighbor != stock_data.my_base_index && stock_data.data_of_cells[origin][8] >= dist + 1)
							|| (neighbor == stock_data.my_base_index))))
			{
				std::pair<int, int> stock = find_next_cell_conected(stock_data, neighbor, 10);
				if (stock.first != -1)
				{
					std::pair<int, std::vector<int> > next_res = find_next_res(stock_data, stock.first, 10);
					if (next_res.first != -1
						&& next_res.second.size() < (size_t) stock.second
						&& stock.first != stock_data.my_base_index
						&& stock.first != origin
						&& stock.first != neighbor
						&& next_res.first != stock.first
						&& next_res.first != neighbor
						&& next_res.first != origin)
					{
//						cerr << origin << "\t" << neighbor << "\t" << stock.first << " " << next_res.first << endl;
						return (0) ;
					}
				}

				if (stock.first != -1 && stock_data.conected_to_base[stock.first] && stock.first != neighbor && stock.first != origin)
				{
					my_line(stock_data, stock.first, neighbor, dist + 1);
					stock_data.conexions[stock.first].push_back(neighbor);
					cerr << stock.first << " -1-> " << neighbor << "\torigin :" << origin << endl;
					if (stock_data.conected_to_base[stock.first] == 1)
						stock_data.conected_to_base[neighbor] = 1;
					else
						stock_data.conected_to_base[stock.first] = 1;
					signal_stop = dist + 1;
				}
				else
				{
					my_line(stock_data, origin, neighbor, dist + 1);
					stock_data.conexions[origin].push_back(neighbor);
					cerr << origin << " -2-> " << neighbor << "\torigin :" << origin << endl;
					if (stock_data.conected_to_base[origin] == 1)
						stock_data.conected_to_base[neighbor] = 1;
					else
						stock_data.conected_to_base[origin] = 1;
					signal_stop = dist + 1;
				}
			}
		}
	}
	if (signal_stop && dist == signal_stop)
		return (1);
	return (0);
}
