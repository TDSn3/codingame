/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 23:02:25 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	start(Data &stock_data)
{
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
		if (type == 1)
			stock_data.number_egg_cell_start++;
	}

	int number_of_bases;
	cin >> number_of_bases; cin.ignore();

	for (int i = 0; i < number_of_bases; i++)
	{
		int base_index;
		
		cin >> base_index;
		cin.ignore();
		stock_data.my_base_index = base_index;
		stock_data.list_base_index.push_back(base_index);
	}

	for (int i = 0; i < number_of_bases; i++)
	{
		int opp_base_index;

		cin >> opp_base_index;
		cin.ignore();
		stock_data.list_opp_base_index.push_back(opp_base_index);
	}

	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		stock_data.res_by_dist.push_back(0);
		stock_data.egg_by_dist.push_back(0);
		stock_data.power_cell.push_back(0);
		stock_data.priority_cell.push_back(0);
		stock_data.beacon_this_loop.push_back(0);
		stock_data.conected_to_base.push_back(0);
		stock_data.conexions.push_back(std::vector<int>());
		stock_data.dist_from_base.push_back(std::vector<int>());
	}

	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
	{
		for (int j = 0; j < stock_data.number_of_cells; j++)
			stock_data.dist_from_base[ stock_data.list_base_index[i] ].push_back(-1);
		distance_all_cell_from_base(stock_data, stock_data.list_base_index[i], 20, stock_data.list_base_index[i]);

		stock_data.conected_to_base[stock_data.list_base_index[i]] = 1;
	}
}

