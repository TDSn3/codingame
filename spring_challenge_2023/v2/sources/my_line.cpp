/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_line.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:52:55 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/04 22:03:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int		restrict_dist(Data &stock_data, std::vector<int> path);

int	my_line(Data &stock_data, int origin, int neighbor, int index_base, std::vector<int> path)
{	
	int	power;

	power = 100;
	if (restrict_dist(stock_data, path))
		return (1);
	stock_data.conexions[ path.back() ]. push_back(std::vector<int>());
	for (long long int i = path.size() - 1; i > -1; i--)
	{
		stock_data.assign_beacon(path[i], power);
		stock_data.conexions[ path.back() ]. back(). push_back(path[i]);
	}

	stock_data.data_of_cells[neighbor][CONNECTED_MY_BASEE_INDEX] = index_base;
	stock_data.data_of_cells[origin][CONNECTED_MY_BASEE_INDEX] = index_base;

	return (0);
}

int	restrict_dist(Data &stock_data, std::vector<int> path)
{
	if (stock_data.beacon > 0
		&& pow(1.4 , path.size() - 1) > (unsigned long int) stock_data.my_ant - stock_data.beacon)
		return (1);	
	return (0);
}
