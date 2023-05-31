/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/31 09:04:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int	restrict_dist(Data &stock_data, std::vector<int> path);

int	my_line(Data &stock_data, int origin, int neighbor, int index_base)
{	
	std::vector<int>	path;
	int					power_prio;

//	assigne priority cell = 1
	path = find_next_beacon(stock_data, neighbor, 10, index_base).second;

	stock_data.total_power_beacon = 0;
	for (int i = 0; i < stock_data.number_of_cells; i++)
		if (stock_data.beacon_this_loop[i])
			stock_data.total_power_beacon += stock_data.power_cell[i] * stock_data.priority_cell[i];

	if (restrict_dist(stock_data, path))
		return (1);

	//	assigne real priority cell
	path = assign_power_until_base(stock_data, neighbor, index_base);
	for (long long int i = path.size() - 1; i > -1; i--)
	{
//		power_prio = stock_data.priority_cell[path[i]];
//		power_prio = stock_data.power_cell[path[i]] * stock_data.priority_cell[path[i]];
//		power_prio = stock_data.power_cell[path[i]];
		power_prio = 1;

		cout << "BEACON" << " " << path[i] << " " << power_prio << ";";

		if (!stock_data.beacon_this_loop[path[i]])
			stock_data.beacon++;
		stock_data.beacon_this_loop[path[i]] = 1;
	}
	cerr <<  endl;

	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	stock_data.conexions[origin].push_back(neighbor);
	stock_data.total_power_beacon = 0;
	return (0);
}

int	restrict_dist(Data &stock_data, std::vector<int> path)
{
	if (stock_data.number_of_cells >= 70) 											// large
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 0.25 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 0.75) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else if (stock_data.number_of_cells < 70 && stock_data.number_of_cells >= 50)	// medium-large
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 1 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 1.5) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else if (stock_data.number_of_cells < 50 && stock_data.number_of_cells >= 35)	// medium-small
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 1.75 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 2.25) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else																			// smal
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 2 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 2.5) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	return (0);
}
