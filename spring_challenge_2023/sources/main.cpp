/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 12:17:18 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int main()
{
	Data					stock_data;
	unsigned long long int	i;
//	int						real_index;

	i = 0;
	cerr << "Start main" << endl;
	start(stock_data);
	while (1)
	{	
		start_2(stock_data);

		print_by_step(stock_data);

		debug(stock_data);
		cerr << "-LOOP " << i <<  " -" << endl;
		i++;
	}
}

//		WAIT
//		LINE <sourceIdx> <targetIdx> <strength>
//		BEACON <cellIdx> <strength>
//		MESSAGE <text

//		// [0]
//		// [1]
//		// [2]
//		// [3]
//		// [4]
//		// [5]
//		// [6]  type
//		// [7]  initial_resources
//		// [8]  distance from my base
//		// [9]  resources
//		// [10] my_ants
//		// [11] opp_ants
//		// [12] case conected
//		// [13] real index 

