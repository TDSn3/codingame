/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:56:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/02 17:39:44 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	start_2(Data &stock_data)
{
	int	my_score;
	int	opp_score;

	cin >> my_score >> opp_score; cin.ignore();

	stock_data.my_score = my_score;
	stock_data.opp_score = opp_score;




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



		if (resources > 0)
		{
			if (stock_data.data_of_cells[i][6] == 1)
			{
				stock_data.egg_cell_now++;
				stock_data.total_res_egg_now += resources;
			}
			else if (stock_data.data_of_cells[i][6] == 2)
			{
				stock_data.cryst_cell_now++;
				stock_data.total_res_cryst_now += resources;
			}
		}
	}

	cout << "MESSAGE" << " " 
	<< "c(" << stock_data.number_cryst_cell_start << ")"
	<< "[" << stock_data.total_res_cryst_start << "]"
	<< " " << stock_data.cryst_cell_now
	<< " " << stock_data.total_res_cryst_now << "  |  "
	<< "e(" << stock_data.number_egg_cell_start << ")"
	<< "[" << stock_data.total_res_egg_start << "]"
	<< " " << stock_data.egg_cell_now
	<< " " << stock_data.total_res_egg_now
	<< ";";

	if (stock_data.egg_cell_now < stock_data.number_egg_cell_start / 2
		&& stock_data.total_res_egg_now < stock_data.total_res_egg_start / 2)
		stock_data.signal_for_crystal = 1;

	cerr << "│ " << std::setw(15) << "cryst start : " << stock_data.number_cryst_cell_start << " ";
	cerr << "│ " << std::setw(15) << "cryst now :" << stock_data.cryst_cell_now  << " │\n";

	cerr << "│ " << std::setw(15) << "egg start : " << stock_data.number_egg_cell_start << " ";
	cerr << "│ " << std::setw(15) << "egg now :" << stock_data.egg_cell_now  << " │\n";

	if (stock_data.egg_cell_now)
		cerr << "│ " << std::setw(15) << "ratio cryst/egg : " << stock_data.number_cryst_cell_start / stock_data.egg_cell_now << "\n";
	else
		cerr << "│ " << std::setw(15) << "ratio cryst/egg : 0\n";

	cerr << "├ " << stock_data.signal_for_crystal << "\n\n";

	cerr << "score : " << stock_data.my_score << "\tlast :" << stock_data.my_score_last_turn << "\n";
	cerr << "bloc : " << stock_data.i_am_bloc << "\n\n";


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
