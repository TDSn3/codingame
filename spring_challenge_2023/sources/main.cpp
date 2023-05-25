/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/25 22:14:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int main()
{
	Data	stock_data;
	std::vector<int>				RESS_POS;
	std::map<int, std::vector<int>>	mapVariables;

	cerr << "Start main" << endl;
	start(stock_data);
	while (1)
	{
		for (int i = 0; i < stock_data.number_of_cells; i++)
		{
			int resources; // the current amount of eggs/crystals on this cell
			int my_ants; // the amount of your ants on this cell
			int opp_ants; // the amount of opponent ants on this cell
			cin >> resources >> my_ants >> opp_ants; cin.ignore();
			if (resources > 0)
				RESS_POS.push_back(i);
		}

		for (int i = 0; i < RESS_POS.size(); i++)
		{
			cout << "LINE" << " " << stock_data.my_base_index << " " << RESS_POS[i] << " " << "1" << ";";
		}
		cout << endl;
	}
}

//		WAIT
//		LINE <sourceIdx> <targetIdx> <strength>
//		BEACON <cellIdx> <strength>
//		MESSAGE <text
