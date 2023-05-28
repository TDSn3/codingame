/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 16:28:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	my_line(Data &stock_data, int &origin, int neighbor, int dist)
{	
	std::vector<int>	path;
	int					power;

	power = 1;
	(void) dist;
	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);
	if (stock_data.data_of_cells[origin][6] == 1 || stock_data.data_of_cells[neighbor][6] == 1)
	{
		power = stock_data.power_egg;
	}
//	if (stock_data.beacon + (path.size() * power) > (unsigned long int) stock_data.total_ants
//		|| (stock_data.dof_short_by_dist[8][origin] > stock_data.total_ants || stock_data.dof_short_by_dist[8][neighbor] > stock_data.total_ants))
//		return ;
	for (size_t k = 0; k < path.size(); k++)
	{
		if (stock_data.pheromone[path[k]] > power)
			cout << "BEACON" << " " << path[k] << " " << stock_data.pheromone[path[k]] << ";";
		else
			cout << "BEACON" << " " << path[k] << " " << power << ";";

		if (!stock_data.pheromone[path[k]])
			stock_data.beacon += power;

		if (stock_data.pheromone[path[k]] < power)
			stock_data.pheromone[path[k]] = power;

		neighbor = path[k];
	}
	if (stock_data.pheromone[neighbor] > power)
		cout << "BEACON" << " " << neighbor << " " << stock_data.pheromone[neighbor] << ";";
	else
		cout << "BEACON" << " " << neighbor << " " << power << ";";

	if (!stock_data.pheromone[neighbor])
		stock_data.beacon += power;

	if (stock_data.pheromone[neighbor] < power)
		stock_data.pheromone[neighbor] = power;
}