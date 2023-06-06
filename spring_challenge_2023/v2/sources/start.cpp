/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:49:48 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 01:19:02 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	start(Data &stock_data)
{
	int	number_of_bases;
	int	base_index;

	cin >> stock_data.number_of_cells; cin.ignore();
	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		int type;													// 0 for empty, 1 for eggs, 2 for crystal
		int initial_resources;										// the initial amount of eggs/crystals on this cell
		int neigh_0;												// the index of the neighbouring cell for each direction or -1
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
			>> neigh_5; cin.ignore();
		stock_data.data_of_cells[i].push_back(neigh_0);				// [0]
		stock_data.data_of_cells[i].push_back(neigh_1);				// [1]
		stock_data.data_of_cells[i].push_back(neigh_2);				// [2]
		stock_data.data_of_cells[i].push_back(neigh_3);				// [3]
		stock_data.data_of_cells[i].push_back(neigh_4);				// [4]
		stock_data.data_of_cells[i].push_back(neigh_5);				// [5]
		stock_data.data_of_cells[i].push_back(type);				// [6]  type
		stock_data.data_of_cells[i].push_back(initial_resources);	// [7]  initial resources
		stock_data.data_of_cells[i].push_back(-1);					// [8]  resources
		stock_data.data_of_cells[i].push_back(-1);					// [9]  my ants
		stock_data.data_of_cells[i].push_back(-1);					// [10] opp ants
		stock_data.data_of_cells[i].push_back(-1);					// [11] weight
		stock_data.data_of_cells[i].push_back(-1);					// [12] beacon this loop
		stock_data.data_of_cells[i].push_back(-1);					// [13] connected my base index
		stock_data.data_of_cells[i].push_back(-1);					// [14] connection in
		stock_data.data_of_cells[i].push_back(-1);					// [15] connection output to the base
		stock_data.data_of_cells[i].push_back(-1);					// [16] power
		stock_data.data_of_cells[i].push_back(-1);					// [17] bloc

		if (type == 1)
		{
			stock_data.total_cell_egg_start++;
			stock_data.total_res_egg_start += initial_resources;
		}
		if (type == 2)
		{
			stock_data.total_cell_cryst_start++;
			stock_data.total_res_cryst_start += initial_resources;
		}

		stock_data.conexions.push_back(vector<vector<int> >());
	}

	cin >> number_of_bases; cin.ignore();
	for (int i = 0; i < number_of_bases; i++)
	{
		cin >> base_index; cin.ignore();
		stock_data.list_my_base_index.push_back(base_index);
	}

	for (int i = 0; i < number_of_bases; i++)
	{
		cin >> base_index; cin.ignore();
		stock_data.list_opp_base_index.push_back(base_index);
	}

	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		stock_data.dist_from_my_base.push_back(vector<int>());
		stock_data.dist_from_opp_base.push_back(vector<int>());
	}

	for (size_t i = 0; i < stock_data.list_my_base_index.size(); i++)
	{
		for (int j = 0; j < stock_data.number_of_cells; j++)
		{
			stock_data.dist_from_my_base[ stock_data.list_my_base_index[i] ].push_back(-1);
			stock_data.dist_from_opp_base[ stock_data.list_opp_base_index[i] ].push_back(-1);
		}
		dist_all_cell_from_base(stock_data, stock_data.list_my_base_index[i], stock_data.list_my_base_index[i], 1, 30);
		dist_all_cell_from_base(stock_data, stock_data.list_opp_base_index[i], stock_data.list_opp_base_index[i], 2, 30);

		stock_data.data_of_cells[ stock_data.list_my_base_index[i] ][13] = stock_data.list_my_base_index[i];
	}
}
