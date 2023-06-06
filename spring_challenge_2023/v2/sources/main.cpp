/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 05:30:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_beacon(Data &stock_data);

int main()
{
	Data	stock_data;
	size_t	i;

	i = 0;
	start(stock_data);

	while (1)
	{	
		Data	copy_data(stock_data);

		start_loop(copy_data);
		principal(copy_data);
		print_beacon2(copy_data);
		end_loop(copy_data);

		stock_data = copy_data;
		stock_data.data_prev = &copy_data;

		cerr << "-LOOP " << i <<  " -" << endl;
		i++;
	}

	return (0);
}

