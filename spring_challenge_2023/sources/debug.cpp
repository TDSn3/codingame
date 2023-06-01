/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:20:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/01 12:05:03 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.hpp"

void	debug(Data &stock_data)
{
	cerr << "\nbeacons :\t"<< stock_data.beacon << endl;
	cerr << "cell :\t"<< stock_data.number_of_cells << endl;
	cerr << "total_ants :\t"<< stock_data.total_ants << "\n" << endl;
	for (size_t i = 0; i < stock_data.res_by_dist.size(); i++)
		stock_data.res_by_dist[i] = 0;

	for (size_t i = 0; i < stock_data.egg_by_dist.size(); i++)
		stock_data.egg_by_dist[i] = 0;

	cerr << "conexion :\n";
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			cerr << "┌ " << i << endl;
			for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			{
				cerr << "└ " << j << " : ";
				for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
				{
					cerr << stock_data.conexions[i][j][k] << " ";
				}
				cerr << "\n";
//				stock_data.conexions[i].clear();
			}
			cerr << "\n";
		}
	}
	cerr << endl;

	for (size_t i = 0; i < stock_data.conexions.size(); i++)
		for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			stock_data.conexions[i].clear();

	cout << endl;

	for (unsigned long int i = 0; i < stock_data.power_cell.size(); i++)
	{
//		if (!stock_data.beacon_this_loop[i])
			stock_data.priority_cell[i] = 0;
		stock_data.power_cell[i] = 0;
		stock_data.beacon_this_loop[i] = 0;
		stock_data.priority_cell[i] = 0;
	}

	for (unsigned long int i = 0; i < stock_data.conected_to_base.size(); i++)
		stock_data.conected_to_base[i] = 0;

	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
		stock_data.conected_to_base[ stock_data.list_base_index[i] ] = 1;
	stock_data.egg_and_cryst = 0;
	stock_data.limit_egg = 2;
	stock_data.egg_cell_now = 0;
}
