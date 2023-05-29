/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 18:44:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	wich_connected(Data &stock_data, int origin, int neighbor)
{
	if (stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

int	wich_not_connected(Data &stock_data, int origin, int neighbor)
{
	if (!stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

void	re_print_to_base(Data &stock_data, int origin, int neighbor, int power)
{
	cerr << origin << " " << neighbor << " power dif. " << stock_data.power_cell[origin] << " " << stock_data.power_cell[neighbor] << endl;
	std::vector<int>	path;

	path = find_base(stock_data, wich_not_connected(stock_data, origin, neighbor), 10).second;
	for (size_t k = 0; k < path.size(); k++)
	{
		if (stock_data.power_cell[path[k]] > power)
			continue ;
		else
			cout << "BEACON" << " " << path[k] << " " << power << ";";

		if (!stock_data.power_cell[path[k]])
			stock_data.beacon += 1;

		if (stock_data.power_cell[path[k]] < power)
			stock_data.power_cell[path[k]] = power;
	}
}

void	print_origin_to_neighbor(Data &stock_data, int origin, int neighbor, int power, std::vector<int> path)
{
	for (size_t k = 0; k < path.size(); k++)
	{
		if (stock_data.power_cell[path[k]] > power)
			cout << "BEACON" << " " << path[k] << " " << stock_data.power_cell[path[k]] << ";";
		else
			cout << "BEACON" << " " << path[k] << " " << power << ";";

		if (!stock_data.power_cell[path[k]])
			stock_data.beacon += 1;

		if (stock_data.power_cell[path[k]] < power)
			stock_data.power_cell[path[k]] = power;
	}	
}

int	my_line(Data &stock_data, int origin, int neighbor, int dist)
{	
	std::vector<int>	path;
	int					power;

	power = 1;
	(void) dist;
	path = algorithme_bfs_2(stock_data, origin, neighbor, 10);
	if (stock_data.data_of_cells[origin][6] == 1 || stock_data.data_of_cells[neighbor][6] == 1)
	{
		power = 2;
	}

	if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants * 80 / 100)
		return (1);
	if (origin != stock_data.my_base_index && !stock_data.power_cell[origin] && !stock_data.power_cell[neighbor])
		return (1);



	cerr <<  origin << " ---> " << neighbor << "\t| " << stock_data.power_cell[origin] << " " << stock_data.power_cell[neighbor] << endl;

	if (stock_data.power_cell[ wich_connected(stock_data, origin, neighbor) ] != power && origin != stock_data.my_base_index)
		re_print_to_base(stock_data, origin, neighbor, power);
	else
		print_origin_to_neighbor(stock_data, origin, neighbor, power, path);



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
	// if (origin != stock_data.my_base_index && !stock_data.power_cell[origin] && !stock_data.power_cell[neighbor])
	// {
	// 	cerr << "│ NO PRINT" << endl;
	// 	cerr << "└─────────────────────────────┘" << endl;
	// 	return (1);
	// }

	// cerr << "└─────────────────────────────┘" << endl;