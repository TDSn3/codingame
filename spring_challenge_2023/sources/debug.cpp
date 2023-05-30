/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:20:15 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 04:17:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/header.hpp"

void	debug(Data &stock_data)
{
	cerr << "beacons :\t"<< stock_data.beacon << endl;
	cerr << "total_ants :\t"<< stock_data.total_ants << endl;
	for (unsigned long int i = 0; i < stock_data.res_by_dist.size(); i++)
		stock_data.res_by_dist[i] = 0;

	for (unsigned long int i = 0; i < stock_data.egg_by_dist.size(); i++)
		stock_data.egg_by_dist[i] = 0;

	cerr << "conexion :\n";
	for (unsigned long int i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			cerr << i << " :\t";
			for (unsigned long int j = 0; j < stock_data.conexions[i].size(); j++)
				cerr << stock_data.conexions[i][j] << " ";
			cerr << "\n";
			while (!stock_data.conexions[i].empty())
				stock_data.conexions[i].erase(stock_data.conexions[i].begin());
		}
	}
	cerr << endl;

	cout << endl;

	for (unsigned long int i = 0; i < stock_data.power_cell.size(); i++)
	{
		if (!stock_data.beacon_this_loop[i])
			stock_data.power_cell[i] = 0;
		stock_data.beacon_this_loop[i] = 0;
	}
	for (unsigned long int i = 0; i < stock_data.conected_to_base.size(); i++)
		stock_data.conected_to_base[i] = 0;
	stock_data.conected_to_base[stock_data.my_base_index] = 1;
	stock_data.egg_and_cryst = 0;
	stock_data.limit_egg = 2;
}
