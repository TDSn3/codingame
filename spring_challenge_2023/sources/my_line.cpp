/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/02 13:34:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int		restrict_dist(Data &stock_data, std::vector<int> path, std::vector<int> save_path);
void	strategie_power(Data &stock_data, int &power_prio, std::vector<int> path, int i);

int	my_line(Data &stock_data, int origin, int neighbor, int index_base, std::vector<int> path)
{	
	int					power_prio;
	std::vector<int>	save_path;

	save_path = path;
	path = assign_power_until_base(stock_data, neighbor, index_base);
	if (path.empty())
		return (1);

	if (restrict_dist(stock_data, path, save_path))
		return (1);

	stock_data.conexions[path.back()].push_back(std::vector<int>());
	for (long long int i = path.size() - 1; i > -1; i--)
	{
		strategie_power(stock_data, power_prio, path, i);

		if (stock_data.power_cell[path[i]] > power_prio)
			power_prio = stock_data.power_cell[path[i]];

		cout << "BEACON" << " " << path[i] << " " << std::abs(power_prio) << ";";

		stock_data.power_cell[path[i]] = power_prio;

		stock_data.conexions[path.back()].back().push_back(path[i]);
		if (!stock_data.beacon_this_loop[path[i]])
			stock_data.beacon++;
		stock_data.beacon_this_loop[path[i]] = 1;
	}

	stock_data.conected_to_base[neighbor] = 1;
	stock_data.conected_to_base[origin] = 1;
	return (0);
}

void	strategie_power(Data &stock_data, int &power_prio, std::vector<int> path, int i)
{
		power_prio = 100;
			
		//	si la res visé est un oeuf
		//	et si c'est un cryst
//		if (stock_data.data_of_cells[path.back()][6] == 1)
//			power_prio += 10 * stock_data.egg_cell_now;
//		else if (stock_data.data_of_cells[path.back()][6] == 1)
//			power_prio = 100;

		if (stock_data.signal_for_crystal && stock_data.data_of_cells[path[i]][6] == 2)
			power_prio += 10;

		//	si la res visé est au centre de la carte
		if (path.back() == 0)
			power_prio += 50;

		//	si le beacon est posé sur une cell avec moins de 3 ant
		if (stock_data.data_of_cells[path[i]][10] < 3)
			power_prio += 5;

		// si la res visé a plus de 50 % de res
		if (stock_data.data_of_cells[path.back()][9] > stock_data.data_of_cells[path.back()][7] / 2)
			power_prio += 25;

		//	si il n'y a pas d'ant ennemi ici et sur la res visé
		if (stock_data.data_of_cells[path[i]][11] == 0
			&& stock_data.data_of_cells[path.back()][11] == 0
			&& path[i] != path.front())
		{
			power_prio -= 10;
			// si la res visé est plus proche de ma base de plus d'1/3 que de celle de l'ennemi
			if (stock_data.ratio_opp_dist(path.back()) <= 1.5)
				power_prio -= 10;
		}	

		// si la res visé est plus proche de ma base de plus d'1/3 que de celle de l'ennemi
		// et si la res visé est plus proche de la base ennemi de plus d'1/3 que de la mienne
		if (stock_data.ratio_opp_dist(path.back()) >= 1.5 && stock_data.ratio_dist(path.back()) >= 1.5)
			power_prio += 50;
		else
		{

			//	si il y a des ant ennemi ici et que cela ce trouve de sont côté de la carte
			//	et si il y a des ant ennemi ici et que cela ce trouve de mon côté de la carte
			if (stock_data.data_of_cells[path[i]][11] > stock_data.data_of_cells[path[i]][10] && stock_data.ratio_dist(path[i]) < 2 )
				power_prio = 1;
			else if (stock_data.data_of_cells[path[i]][11] > stock_data.data_of_cells[path[i]][10] && stock_data.ratio_dist(path[i]) >= 2 )
				power_prio += 50;

		}
}

int	restrict_dist(Data &stock_data, std::vector<int> path, std::vector<int> save_path)
{
	//	si le chemin vers un beacon est < 3
	if (((int) save_path.size() - 1) < stock_data.total_ants - stock_data.beacon)
	{
		if (save_path.size() < 3)
			return (0);
	}


	if (stock_data.beacon > 0)
	{
		// si la res visé est plus proche de la base ennemi de plus d'1/3 que de la mienne
		if (stock_data.ratio_dist(path.back()) <= 1.5)
			return (1);

		if (stock_data.type_size_map == 4) 		// large
		{
			if (pow(1.2 , path.size() - 1) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
				return (1);
		}
		else if (stock_data.type_size_map == 3)	// medium-large
		{
			if (pow(1.3 , path.size() - 1) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
				return (1);	
		}
		else if (stock_data.type_size_map == 2)	// medium-small
		{
			if (pow(1.2 , path.size() - 1) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
				return (1);
		}
		else									// smal
		{
			if (pow(1.6 , path.size() - 1) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
				return (1);	
		}
	}


	// if (stock_data.number_of_cells >= 70) 										// large
	// {
	// 	int	new_path_from_base;
		
	// 	// si la res visé est un oeuf
	// 	if (stock_data.data_of_cells[path.back()][6] == 1)
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.4 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// 	else
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.4 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// }
	// else if (stock_data.number_of_cells < 70 && stock_data.number_of_cells >= 50)	// medium-large
	// {
	// 	int	new_path_from_base;
		
	// 	// si la res visé est un oeuf
	// 	if (stock_data.data_of_cells[path.back()][6] == 1)
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.4 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// 	else
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.4 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// }
	// else if (stock_data.number_of_cells < 50 && stock_data.number_of_cells >= 35)	// medium-small
	// {
	// 	int	new_path_from_base;
		
	// 	// si la res visé est un oeuf
	// 	if (stock_data.data_of_cells[path.back()][6] == 1)
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.6 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// 	else
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.6 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// }
	// else																				// smal
	// {
	// 	int	new_path_from_base;
		
	// 	// si la res visé est un oeuf
	// 	if (stock_data.data_of_cells[path.back()][6] == 1)
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.6 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// 	else
	// 	{
	// 		new_path_from_base = (path.size() - 1);
	// 		if (pow(1.6 , new_path_from_base) > (unsigned long int) stock_data.total_ants - stock_data.beacon)
	// 			return (1);
	// 	}
	// }
	return (0);
}
