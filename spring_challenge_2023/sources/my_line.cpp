/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 14:02:32 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	wich_connected(Data &stock_data, int origin, int neighbor)
{
	if (stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

int	which_not_connected(Data &stock_data, int origin, int neighbor)
{
	if (!stock_data.conected_to_base[origin])
		return (origin);
	return(neighbor);
}

void	assign_power_until_base(Data &stock_data, int origin, int neighbor, int index_base)
{
	std::pair<int, std::vector<int> > path_to_base;

	path_to_base = find_next_base(stock_data, neighbor, 30, index_base);

	// Affichage les beacons
	for (size_t i = 0; i < path_to_base.second.size(); i++)
	{
		stock_data.power_cell[path_to_base.second[i]] += 1;
		cerr << std::setw(3) << path_to_base.second[i] << " │";
	}
	cerr << endl;

	// Affichage le power des beacons
	for (size_t i = 0; i < path_to_base.second.size(); i++)
	{
		cerr << std::setw(3) << stock_data.power_cell[path_to_base.second[i]] << " │";
	}
	cerr << endl;
}

int	my_line(Data &stock_data, int origin, int neighbor, int index_base)
{	
	std::vector<int>	path;

	path = find_path_origin_neighbor(stock_data, origin, neighbor, 10);

	if (stock_data.beacon + path.size() > (unsigned long int) stock_data.total_ants * 60 / 100)
		return (1);
	assign_power_until_base(stock_data, origin, neighbor, index_base);



	cerr << "new way :\n";
	for (size_t i = 0; i < path.size(); i++)
	{
		cout << "BEACON" << " " << path[i] << " " << stock_data.power_cell[path[i]] << ";";
		
		if (!stock_data.beacon_this_loop[path[i]])
			stock_data.beacon++;
		stock_data.beacon_this_loop[path[i]] = 1;
		cerr << std::setw(3) <<  path[i] << " │";
	}
	cerr <<  endl;

	for (size_t i = 0; i < path.size(); i++)
	{
		cerr << std::setw(3) <<  stock_data.power_cell[path[i]] << " │";
	}
	cerr << "\n" <<  endl;



	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	stock_data.conexions[origin].push_back(neighbor);
	return (0);
}
