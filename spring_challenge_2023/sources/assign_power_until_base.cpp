/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_power_until_base.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 08:50:31 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/01 19:21:08 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

std::vector<int>	assign_power_until_base(Data &stock_data, int neighbor, int index_base)
{
	std::vector<int>	path_to_base;

	(void) index_base;
	path_to_base = find_next_base(stock_data, neighbor, 30);
	if (path_to_base.empty())
		return (std::vector<int>());

	// Affichage les beacons
	for (size_t i = 0; i < path_to_base.size(); i++)
	{
//		stock_data.power_cell[path_to_base[i]] += 1;
		cerr << std::setw(3) << path_to_base[i] << " │";
	}
//	stock_data.power_cell[index_base] = 1;
	cerr << endl;

	// Affichage le power des beacons
	for (size_t i = 0; i < path_to_base.size(); i++)
		cerr << std::setw(3) << stock_data.power_cell[path_to_base[i]] << " │";
	cerr << endl;

	// Affichage priority cell
	for (size_t i = 0; i < path_to_base.size(); i++)
		cerr << std::setw(3) << stock_data.priority_cell[path_to_base[i]] << " │";
	cerr << endl;

	return (path_to_base);
}
