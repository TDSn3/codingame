/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   principal.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 20:28:17 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/04 20:57:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int		empty_list_queue(vector<queue<pair<int, int> > >	list_queue);
void	visit_neighbors(Data &stock_data, queue<pair<int, int> > &bfs_queue, vector<bool> &visited, int base, int &index, int &dist, int j);
int		stategie_specific(Data &stock_data, int neighbor);

void	principal(Data &stock_data)
{
	vector<queue<pair<int, int> > >	list_queue;
	vector<bool>					visited(stock_data.data_of_cells.size(), false);
	vector<int>						index2;
	vector<int>						dist2;

	for (size_t i = 0; i < stock_data.list_my_base_index.size(); i++)
	{
		list_queue.push_back(queue<pair<int, int> >());
		list_queue[i].push(pair<int, int>(stock_data.list_my_base_index[i] , 0));
		index2.push_back(-1);
		dist2.push_back(0);
		visited[stock_data.list_my_base_index[i]] = true;
	}

	while (!empty_list_queue(list_queue))
	{
		for (size_t i = 0; i < stock_data.list_my_base_index.size(); i++)
		{
			if (!list_queue[i].empty())
			{
				index2[i] = list_queue[i].front().first;
				dist2[i] = list_queue[i].front().second;

				list_queue[i].pop();
				for (size_t j = 0; j < 6; j++)
					visit_neighbors(stock_data, list_queue[i], visited, stock_data.list_my_base_index[i], index2[i], dist2[i], j);
			}
		}
	}
}

int		empty_list_queue(vector<queue<pair<int, int> > >	list_queue)
{
	for (size_t i = 0; i < list_queue.size(); i++)
		if (!list_queue[i].empty())
			return (0);
	return (1);
}

void	visit_neighbors(Data &stock_data, queue<pair<int, int> > &bfs_queue, vector<bool> &visited, int base, int &index, int &dist, int j)
{
	int	neighbor;

	neighbor = stock_data.data_of_cells[index][j];
	if (neighbor != -1 && !visited[neighbor])
	{
		bfs_queue.push(pair<int, int>(neighbor, dist + 1));
		visited[neighbor] = true;

		if (stock_data.data_of_cells[neighbor][RES] > 0)
		{			
			if (stategie_specific(stock_data, neighbor))
				return ;
			
			pair<int, vector<int> > stock = find_next_beacon(stock_data, neighbor, base, 10);

			if (stock.first != -1)
			{
				cerr << neighbor<< " ---> " << stock.first << "\n";
				my_line(stock_data, stock.first, neighbor, base, stock.second);
			}
		}
	}
}

int		stategie_specific(Data &stock_data, int neighbor)
{
	// si il y a déjà des beacon de posés
	if (stock_data.beacon > 0)
	{
		// si la res visé est plus proche de la base ennemi de plus d'1/3 que de la mienne
		if (stock_data.ratio_dist(neighbor) <= 1.5)
			return (1);
	}

	return (0);
}
