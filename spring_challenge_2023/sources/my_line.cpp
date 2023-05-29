/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 15:31:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	my_line(Data &stock_data, int origin, int neighbor, int dist)
{	
	std::vector<int>	path;
	int					power;

	power = 1;
	(void) dist;
	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);
	if (stock_data.data_of_cells[origin][6] == 1 || stock_data.data_of_cells[neighbor][6] == 1)
		power = stock_data.power_egg;

	if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants)
		return (1);
	if (origin != stock_data.my_base_index && !stock_data.pheromone[origin] && !stock_data.pheromone[neighbor])
		return (1);

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

	}
	if (stock_data.pheromone[neighbor] > power)
		cout << "BEACON" << " " << neighbor << " " << stock_data.pheromone[neighbor] << ";";
	else
		cout << "BEACON" << " " << neighbor << " " << power << ";";

	if (!stock_data.pheromone[neighbor])
		stock_data.beacon += power;

	if (stock_data.pheromone[neighbor] < power)
		stock_data.pheromone[neighbor] = power;

	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	stock_data.conexions[origin].push_back(neighbor);
	return (0);
}



	// cerr << "┌─────────────────────────────┐" << endl;
	// cerr << "│ " <<  origin << " ---> " << neighbor << endl;
	// cerr << "│ " << "beacon : " << stock_data.beacon << "\tpath.size : " << path.size() << "\ttotal_ants : " << stock_data.total_ants << endl;
	// cerr << "│ " << stock_data.beacon + path.size() << endl;
	// cerr << "│ " << "origin ?: " <<  stock_data.conected_to_base[origin] << "\tneighbor ?: " << stock_data.conected_to_base[neighbor] << endl;

	// if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants)
	// {
	// 	cerr << "│ NO PRINT" << endl;
	// 	cerr << "└─────────────────────────────┘" << endl;
	// 	return (1);
	// }
	// if (origin != stock_data.my_base_index && !stock_data.pheromone[origin] && !stock_data.pheromone[neighbor])
	// {
	// 	cerr << "│ NO PRINT" << endl;
	// 	cerr << "└─────────────────────────────┘" << endl;
	// 	return (1);
	// }

	// cerr << "└─────────────────────────────┘" << endl;