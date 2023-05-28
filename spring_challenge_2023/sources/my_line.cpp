/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 15:25:52 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	my_line(Data &stock_data, int &origin, int neighbor, int dist)
{	
	std::vector<int>	path;

	(void) dist;
	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);
	if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants)
		return ;
	for (size_t k = 0; k < path.size(); k++)
	{
		cout << "BEACON" << " " << path[k] << " " << "1" << ";";
		if (!stock_data.pheromone[path[k]])
			stock_data.beacon++;
		stock_data.pheromone[path[k]]++;
		neighbor = path[k];
	}
	cout << "BEACON" << " " << neighbor << " " << "1" << ";";
	if (!stock_data.pheromone[neighbor])
		stock_data.beacon++;
}
