/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:56:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 15:18:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	start_2(Data &stock_data)
{
	for (int i = 0; i < stock_data.number_of_cells; i++)
	{
		int resources;	// la quantité actuelle d'oeufs/cristaux sur cette cellule
		int my_ants;	// le montant de vos fourmis sur cette cellule
		int opp_ants;	// la quantité de fourmis adverses sur cette cellule
		cin
			>> resources
			>> my_ants
			>> opp_ants;
		cin.ignore();
		stock_data.data_of_cells[i][9] = resources;
		stock_data.data_of_cells[i][10] = my_ants;
		stock_data.data_of_cells[i][11] = opp_ants;
		stock_data.total_ants += my_ants;
		if (resources > 0
			&& stock_data.data_of_cells[i][6] == 2
			&& stock_data.data_of_cells[i][8] > 0)							// [6] type == crystal [8] dist_from_base > 0
			stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
		else if (resources > 0 && stock_data.data_of_cells[i][6] == 1)		// [6] type == egg
			stock_data.egg_by_dist[stock_data.data_of_cells[i][8]] += 1;
	}
}