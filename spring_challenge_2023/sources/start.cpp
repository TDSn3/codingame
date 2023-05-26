/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 16:57:34 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

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
		stock_data.data_of_cells[i].push_back(neigh_0);				// [0]
		stock_data.data_of_cells[i].push_back(neigh_1);				// [1]
		stock_data.data_of_cells[i].push_back(neigh_2);				// [2]
		stock_data.data_of_cells[i].push_back(neigh_3);				// [3]
		stock_data.data_of_cells[i].push_back(neigh_4);				// [4]
		stock_data.data_of_cells[i].push_back(neigh_5);				// [5]
		stock_data.data_of_cells[i].push_back(type);				// [6]
		stock_data.data_of_cells[i].push_back(initial_resources);	// [7]
		stock_data.data_of_cells[i].push_back(-1);					// [8]  distance from my base
		stock_data.data_of_cells[i].push_back(-1);					// [9]  resources
		stock_data.data_of_cells[i].push_back(-1);					// [10] my_ants
		stock_data.data_of_cells[i].push_back(-1);					// [11] opp_ants
		stock_data.data_of_cells[i].push_back(-1);					// [12] case conected
		stock_data.data_of_cells[i].push_back(i);					// [13] real index 
	}

	int number_of_bases;
	cin >> number_of_bases; cin.ignore();

	for (int i = 0; i < number_of_bases; i++)
	{
		cin >> stock_data.my_base_index; cin.ignore();
	}

	for (int i = 0; i < number_of_bases; i++)
	{
		int opp_base_index;
		cin >> opp_base_index; cin.ignore();
	}

	cerr << "Start bfs" << endl;
	algorithme_bfs(stock_data, stock_data.my_base_index, 20);
}

