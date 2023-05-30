/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 04:01:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int main()
{
	Data					stock_data;
	unsigned long long int	i;

	i = 0;
	cerr << "Start main" << endl;
	start(stock_data);
	while (1)
	{	
		start_2(stock_data);
		cout << "MESSAGE" << " " << "Hello :)" << ";";
		bfs_from_base(stock_data);
		debug(stock_data);
		cerr << "-LOOP " << i <<  " -" << endl;
		i++;
	}
}
