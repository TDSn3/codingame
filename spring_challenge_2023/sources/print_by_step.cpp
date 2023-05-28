/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_step.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:58:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 16:10:29 by tda-silv         ###   ########.fr       */
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
				&& stock_data.data_of_cells[real_index][6] > stock_data.egg_and_cryst))
		{
			print_one_path(stock_data, real_index);
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