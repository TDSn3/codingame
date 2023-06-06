/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_loop.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:56:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 01:19:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	clean_class(Data &stock_data);

void	start_loop(Data &stock_data)
{
	clean_class(stock_data);
	cin >> stock_data.my_score >> stock_data.opp_score; cin.ignore();

	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		cin
			>> stock_data.data_of_cells[i][8]
			>> stock_data.data_of_cells[i][9]
			>> stock_data.data_of_cells[i][10]; cin.ignore();
		stock_data.my_ant += stock_data.data_of_cells[i][9];
		stock_data.opp_ant += stock_data.data_of_cells[i][10];

		if (stock_data.data_of_cells[i][8] > 0)					// res
		{
			if (stock_data.data_of_cells[i][6] == 1)			// egg
			{
				stock_data.total_cell_egg_now++;
				stock_data.total_res_egg_now += stock_data.data_of_cells[i][8];
				if (stock_data.data_of_cells[i][9] > 0)			// my_ant
					stock_data.my_cell_res_cryst_now++;
				else if (stock_data.data_of_cells[i][10] > 0)	// opp_ant
					stock_data.opp_cell_res_cryst_now++;
			}
			else if (stock_data.data_of_cells[i][6] == 2)		// cryst
			{
				stock_data.total_cell_cryst_now++;
				stock_data.total_res_cryst_now += stock_data.data_of_cells[i][8];
				if (stock_data.data_of_cells[i][9] > 0)			// my_ant
					stock_data.my_cell_res_egg_now++;
				else if (stock_data.data_of_cells[i][10] > 0)	// opp_ant
					stock_data.opp_cell_res_egg_now++;
			}
		}
	}
	stock_data.total_ant = stock_data.my_ant + stock_data.opp_ant;
}

void	clean_class(Data &stock_data)
{
	stock_data.my_score = 0;
	stock_data.opp_score = 0;

	stock_data.total_ant = 0;
	stock_data.my_ant = 0;
	stock_data.opp_ant = 0;

	stock_data.total_cell_egg_now = 0;
	stock_data.total_res_egg_now = 0;
	stock_data.my_cell_res_egg_now = 0;
	stock_data.opp_cell_res_egg_now = 0;

	stock_data.total_cell_cryst_now = 0;
	stock_data.total_res_cryst_now = 0;
	stock_data.my_cell_res_cryst_now = 0;
	stock_data.opp_cell_res_cryst_now = 0;

	stock_data.beacon = 0;
	stock_data.beacon_on_res = 0;

	stock_data.signal_res = 0;

	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		stock_data.data_of_cells[i][11] = -1;
		stock_data.data_of_cells[i][12] = -1;
		stock_data.data_of_cells[i][13] = -1;
		stock_data.data_of_cells[i][14] = -1;
		stock_data.data_of_cells[i][15] = -1;
		stock_data.data_of_cells[i][16] = -1;
		stock_data.data_of_cells[i][17] = -1;
	}

	for (size_t i = 0; i < stock_data.list_my_base_index.size(); i++)
		stock_data.data_of_cells[ stock_data.list_my_base_index[i] ][13] = stock_data.list_my_base_index[i];

	for (size_t i = 0; i < stock_data.conexions.size(); i++)
		for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			if (!stock_data.conexions[i].empty())
				stock_data.conexions[i].clear();
}
