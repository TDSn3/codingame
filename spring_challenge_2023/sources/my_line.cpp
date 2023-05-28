/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 03:18:43 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	my_line(Data &stock_data, int &origin, int neighbor, int dist)
{	
	std::vector<int>	path;

	(void) dist;
	stock_data.pheromone[neighbor]++;
	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);
	for (size_t k = 0; k < path.size(); k++)
	{
		cout << "BEACON" << " " << path[k] << " " << "1" << ";";
		stock_data.pheromone[path[k]]++;
		neighbor = path[k];
	}
	cout << "BEACON" << " " << neighbor << " " << "1" << ";";
}
