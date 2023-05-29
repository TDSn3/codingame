/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 23:52:48 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	my_line(Data &stock_data, int origin, int neighbor)
{	
	std::vector<int>	path;

	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);

	if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants * 80 / 100)
		return (1);

	for (size_t i = 0; i < path.size(); i++)
	{
		cout << "BEACON" << " " << path[i] << " " << "1" << ";";
		stock_data.beacon_this_loop[path[i]] = 1;
		if (!stock_data.power_cell[path[i]])
			stock_data.beacon += 1;
		stock_data.power_cell[path[i]] = 1;
	}
	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	stock_data.conexions[origin].push_back(neighbor);
	return (0);
}
