/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 15:39:15 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_by_step(Data& stock_data);

int main()
{
	Data	stock_data;

	cerr << "Start main" << endl;
	start(stock_data);
	while (1)
	{	
		start_2(stock_data);

		print_by_step(stock_data);

		debug(stock_data);
	}
}

bool	find_conexion(Data& stock_data, int src_index, int chr_index)
{
	cerr << "+-------+\n";
	cerr << src_index << " " << chr_index << endl;
	for (unsigned long int j = 0; j < stock_data.conexions[src_index].size(); j++)
	{
		if (stock_data.conexions[src_index][j] == chr_index)
		{
			cerr << "+---1---+\n";
			return (true);
		}
	}
	cerr << "+---0---+\n";
	return (false);
}

void	print_by_step(Data& stock_data)
{
	cerr << "print_by_step :\t";
	for (unsigned long int i = 1; i < stock_data.res_by_dist.size(); i++)
	{
		if (stock_data.egg_by_dist[i] > 0 && i < 2)
		{
			cerr << "X" << endl;
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
				if (stock_data.data_of_cells[j][8] == i && stock_data.data_of_cells[j][9] > 0 && stock_data.data_of_cells[j][6] == 1)
					cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << "1" << ";";
			return ;
		}
		if (stock_data.res_by_dist[i] > 0)
		{
			cerr << "O" << endl;
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
			{
				if (stock_data.data_of_cells[j][8] == i && stock_data.data_of_cells[j][9] > 0 && stock_data.data_of_cells[j][6] == 2)
				{
					int	power;

					power = 1;
					//                    opp_ants [11]                       my_ants [10]                                              distance_from_base [8]
//					if (stock_data.data_of_cells[j][11] >= stock_data.data_of_cells[j][10] && stock_data.res_by_dist[i] == 1 && stock_data.data_of_cells[j][8] < 4)
//						power+= 1;
//					if (stock_data.data_of_cells[j][11] >= stock_data.data_of_cells[j][10] && stock_data.data_of_cells[j][8] < 3)
//						power+= 1;
//					if (stock_data.data_of_cells[j][11] >= stock_data.data_of_cells[j][10])
//						power+= 100;
					std::pair<int, int>	stock;

					stock = algorithme_bfs_stop_first(stock_data, j, 20);
					if (stock.first != -1 && stock.second <= stock_data.data_of_cells[j][8] && !find_conexion(stock_data, stock.first, j))
					{
						cout << "LINE" << " " << j << " " << stock.first << " " << power + 99 << ";";
						stock_data.conexions[j].push_back(stock.first);
					}
					else
					{
						cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << power + 99 << ";";
						stock_data.conexions[j].push_back(stock_data.my_base_index);
					}
					cerr << "debug : " <<  j << " : " << "[" << stock.first << "]" << stock.second << " < " << stock_data.data_of_cells[j][8] << " " << (stock.second <= stock_data.data_of_cells[j][8]) << endl;
				}
				if (stock_data.data_of_cells[j][8] == i && stock_data.data_of_cells[j][9] > 0 && stock_data.data_of_cells[j][6] == 1)
					cout << "BEACON" << " " << j << " " << "1" << ";";
			}
		}
		cerr << i << " ";
	}
	cerr << endl;
}

//		WAIT
//		LINE <sourceIdx> <targetIdx> <strength>
//		BEACON <cellIdx> <strength>
//		MESSAGE <text

//		stock_data.data_of_cells[i].push_back(neigh_0);				// [0]
//		stock_data.data_of_cells[i].push_back(neigh_1);				// [1]
//		stock_data.data_of_cells[i].push_back(neigh_2);				// [2]
//		stock_data.data_of_cells[i].push_back(neigh_3);				// [3]
//		stock_data.data_of_cells[i].push_back(neigh_4);				// [4]
//		stock_data.data_of_cells[i].push_back(neigh_5);				// [5]
//		stock_data.data_of_cells[i].push_back(type);				// [6]
//		stock_data.data_of_cells[i].push_back(initial_resources);	// [7]
//		stock_data.data_of_cells[i].push_back(-1);					// [8]  distance from my base
//																	// [9]  resources
//																	// [10] my_ants
//																	// [11] opp_ants
//		stock_data.data_of_cells[i].push_back(-1);					// [12] case conected
