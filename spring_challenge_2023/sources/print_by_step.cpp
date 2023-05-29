/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_by_step.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:58:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 21:32:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   Parcours tous les cercles autour de la base.							  */
/*   "i" est égal à la distance entre la base et le cercle.					  */
/*   Explore les autres cases si l'origine est la base ou une ressource		  */
/*   abondante qui est connectée.											  */
/*                                                                            */
/* ************************************************************************** */
//void	print_by_step(Data& stock_data)
//{
//	int	real_index;
//
//	for (unsigned long int i = 0; i < stock_data.data_of_cells.size(); i++)
//	{
//		real_index = stock_data.dof_short_by_dist[i][13];
//		if (i == 0
//			|| (stock_data.data_of_cells[real_index][9] > 0
//				&& stock_data.data_of_cells[real_index][6] > stock_data.egg_and_cryst)
//				&& stock_data.conected_to_base[real_index])
//		{
//			print_one_path(stock_data, real_index);
//		}
//		print_one_path(stock_data, stock_data.my_base_index);
//	}
//}

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
