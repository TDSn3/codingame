/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_step.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:58:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 00:34:58 by tda-silv         ###   ########.fr       */
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
//		si il y a un oeuf a moins de 1 de la base		
		if (i == 0 && stock_data.egg_by_dist[i + 1])
		{
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
				if (stock_data.data_of_cells[j][8] == (int) i + 1
					&& stock_data.data_of_cells[j][9] > 0
					&& stock_data.data_of_cells[j][6] == 1)
					cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << "1" << ";";
			return ;
		}
		real_index = stock_data.dof_short_by_dist[i][13];
		if (i == 0
			|| (stock_data.data_of_cells[real_index][9] > 0
				&& stock_data.data_of_cells[real_index][6] == 2))
		{
			print_one_path(stock_data, real_index);
		}
	}

	for (unsigned long int i = 0; i < stock_data.data_of_cells.size(); i++)
	{
		
	}
}
