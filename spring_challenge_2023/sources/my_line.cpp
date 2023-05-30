/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/31 00:29:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

std::vector<int>	assign_power_until_base(Data &stock_data, int neighbor, int index_base);


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




	if (stock_data.number_of_cells >= 70)
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 0.5 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 0.75) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else if (stock_data.number_of_cells < 70 && stock_data.number_of_cells >= 50)
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 1 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 1.5) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else if (stock_data.number_of_cells < 50 && stock_data.number_of_cells >= 35)
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 0.25 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 2.2) > (unsigned long int) stock_data.total_ants)
			return (1);
	}
	else
	{
		if (stock_data.number_egg_cell_start / 2 >= stock_data.signal_for_crystal) {
			if (stock_data.total_power_beacon * (path.size() - 1) * 1 > (unsigned long int) stock_data.total_ants)
				return (1); }
		else if (stock_data.total_power_beacon * ((path.size() - 1) * 1.5) > (unsigned long int) stock_data.total_ants)
			return (1);
	}




//	if (stock_data.beacon * ((path.size() - 1) * 2) > (unsigned long int) stock_data.total_ants)
//		return (1);

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

std::vector<int>	assign_power_until_base(Data &stock_data, int neighbor, int index_base)
{
	std::vector<int>	path_to_base;

	path_to_base = find_next_base(stock_data, neighbor, index_base, 30);

	// Affichage les beacons
	for (size_t i = 0; i < path_to_base.size(); i++)
	{
		stock_data.power_cell[path_to_base[i]] += 1;
		cerr << std::setw(3) << path_to_base[i] << " │";
	}
	stock_data.power_cell[index_base] = 1;
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
