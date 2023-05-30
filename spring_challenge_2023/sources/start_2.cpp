/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:56:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 18:09:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	start_2(Data &stock_data)
{
	int	my_score;
	int	opp_score;

	cin >> my_score >> opp_score; cin.ignore();




//	if (stock_data.total_ants <= stock_data.total_opp_ants + 20)
//	{
		stock_data.egg_and_cryst = 0;
//		stock_data.power_egg = 5;
//	}
//	else
//	{
//		stock_data.egg_and_cryst = 1;
//		stock_data.power_egg = 1;
//	}




	stock_data.beacon = 0;
	stock_data.total_power_beacon = 0;
	stock_data.total_ants = 0;
	stock_data.total_opp_ants = 0;



	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		int resources;
		int my_ants;
		int opp_ants;
		cin
			>> resources
			>> my_ants
			>> opp_ants;
		cin.ignore();
		stock_data.data_of_cells[i][9] = resources;
		stock_data.data_of_cells[i][10] = my_ants;
		stock_data.data_of_cells[i][11] = opp_ants;
		stock_data.total_ants += my_ants;
		stock_data.total_opp_ants += opp_ants;
		if (resources > 0
			&& stock_data.data_of_cells[i][6] == 2
			&& stock_data.data_of_cells[i][8] > 0)							// [6] type == crystal [8] dist_from_base > 0
			stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
		else if (resources > 0 && stock_data.data_of_cells[i][6] == 1)		// [6] type == egg
			stock_data.egg_by_dist[stock_data.data_of_cells[i][8]] += 1;
//		if (resources > 0 && stock_data.data_of_cells[i][6] == 1)
//			stock_data.limit_egg = 1;
	}



	vector<pair<int, int> >	stock;

	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		stock.push_back(std::pair<int, int>(stock_data.data_of_cells[i][8], i));
	}
	sort(stock.begin(), stock.end());
	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		int	size;

		size = stock_data.data_of_cells[i].size();
		for (int j = 0; j < size; j++)
		{
			stock_data.dof_short_by_dist[i].push_back(stock_data.data_of_cells[stock[i].second][j]);
		}
	}
}
