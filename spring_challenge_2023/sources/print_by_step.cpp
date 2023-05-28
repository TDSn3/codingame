/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_step.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:58:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 12:31:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_by_step(Data& stock_data)
{
	int	real_index;

//	parcour chaque cercle autour de la base
//	i == dist du cercle par rapport a la base
	for (unsigned long int i = 0; i < stock_data.data_of_cells.size(); i++)
	{
		real_index = stock_data.dof_short_by_dist[i][13];
		if (i == 0
			|| (stock_data.data_of_cells[real_index][9] > 0
				&& stock_data.data_of_cells[real_index][6] == 2))
		{
			print_one_path(stock_data, real_index);
		}
	}

//	link les oeufs si ils sont proches des phero
	for (unsigned long int i = 0; i < stock_data.data_of_cells.size(); i++)
	{
		if (stock_data.data_of_cells[i][6] == 1 && !stock_data.conected_to_base[i] && stock_data.data_of_cells[i][9] > 0 && stock_data.data_of_cells[i][8] < 10)
		{
			std::pair<int, std::vector<int> >	stock = find_next_phero(stock_data, i, 5);
			if (stock.first != 1)
			{
				stock_data.conexions[i].push_back(stock.first);
				cerr << stock.first << " ---> " << i << endl;
				for (size_t j = 0; j < stock.second.size(); j++)
				{
					cout << "BEACON" << " " << stock.second[j] << " " << "1" << ";";
					stock_data.pheromone[stock.second[j]]++;
				}
				stock_data.conected_to_base[i] = 1;
			}
		}
	}
}

//		// [0]
//		// [1]
//		// [2]
//		// [3]
//		// [4]
//		// [5]
//		// [6]  type
//		// [7]  initial_resources
//		// [8]  distance from my base
//		// [9]  resources
//		// [10] my_ants
//		// [11] opp_ants
//		// [12] case conected
//		// [13] real index 