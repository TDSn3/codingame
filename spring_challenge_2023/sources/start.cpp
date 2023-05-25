/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/25 23:57:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void recursive_dist_from_base(Data& stock_data, int max_dist) {
	std::vector<bool> visited(stock_data.data_of_cells.size(), false);	// Tableau pour marquer les cellules visitées
	std::queue<std::pair<int, int>> bfs_queue;							// File d'attente pour la recherche en largeur

	bfs_queue.push({stock_data.my_base_index, 0});						// Ajouter la cellule de départ à la file d'attente
	visited[stock_data.my_base_index] = true;							// Marquer la cellule de départ comme visitée

	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;
		bfs_queue.pop();

		stock_data.data_of_cells[index][8] = dist;						// Mettre à jour la distance
		cerr << index << " = " << dist << endl;

		if (dist < max_dist)
		{
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push({neighbor, dist + 1});				// Ajouter le voisin à la file d'attente
					visited[neighbor] = true;							// Marquer le voisin comme visité
				}
			}
		}
	}
}

void	start(Data &stock_data)
{
	cerr << "Start strat" << endl;
	cin >> stock_data.number_of_cells; cin.ignore();
	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		int type;				// 0 for empty, 1 for eggs, 2 for crystal
		int initial_resources;	// the initial amount of eggs/crystals on this cell
		int neigh_0;			// the index of the neighbouring cell for each direction or -1
		int neigh_1;
		int neigh_2;
		int neigh_3;
		int neigh_4;
		int neigh_5;
		cin
			>> type
			>> initial_resources
			>> neigh_0
			>> neigh_1
			>> neigh_2
			>> neigh_3
			>> neigh_4
			>> neigh_5;
		cin.ignore();
		stock_data.data_of_cells[i].push_back(neigh_0);
		stock_data.data_of_cells[i].push_back(neigh_1);
		stock_data.data_of_cells[i].push_back(neigh_2);
		stock_data.data_of_cells[i].push_back(neigh_3);
		stock_data.data_of_cells[i].push_back(neigh_4);
		stock_data.data_of_cells[i].push_back(neigh_5);
		stock_data.data_of_cells[i].push_back(type);
		stock_data.data_of_cells[i].push_back(initial_resources);
		stock_data.data_of_cells[i].push_back(-1);					// distance from my base
//		cerr << i << endl;
	}

	int number_of_bases;
	cin >> number_of_bases; cin.ignore();

	for (int i = 0; i < number_of_bases; i++)
		cin >> stock_data.my_base_index; cin.ignore();

	for (int i = 0; i < number_of_bases; i++)
	{
		int opp_base_index;
		cin >> opp_base_index; cin.ignore();
	}

	std::vector<int>	save_index;
	int					dist;

	dist = 0;
	cerr << "Start recursive" << endl;
	recursive_dist_from_base(stock_data, 20);
}

