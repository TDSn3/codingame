/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 18:55:40 by tda-silv         ###   ########.fr       */
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
//	parcour chaque cercle autour de la base
	for (unsigned long int i = 1; i < stock_data.res_by_dist.size(); i++)
	{
//		si il y a un oeuf a moins de 1 de la base		
		if (stock_data.egg_by_dist[i] > 0 && i < 2)
		{
			cerr << "X" << endl;
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
				if (stock_data.data_of_cells[j][8] == i && stock_data.data_of_cells[j][9] > 0 && stock_data.data_of_cells[j][6] == 1)
					cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << "1" << ";";
			return ;
		}
//		si il y a des ressources dans ce cercle		
		if (stock_data.res_by_dist[i] > 0)
		{
//			parcour chaque case
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
			{
//																					resources [9]								   type [6] == crystal
				if (stock_data.dof_short_by_dist[j][8] == i && stock_data.dof_short_by_dist[j][9] > 0 && stock_data.dof_short_by_dist[j][6] == 2)
				{
					int	power;

					power = 1;
					std::pair<int, int>	stock;

					stock = algorithme_bfs_stop_first(stock_data, j, 20);
//					 index_neighbor			neighbor_dist			     distance_from_base [8]
					if (stock.first != -1 && stock.second <= stock_data.dof_short_by_dist[j][8] && !find_conexion(stock_data, stock.first, j))
					{
						cout << "LINE" << " " << stock_data.dof_short_by_dist[j][13] << " " << stock.first << " " << power + 99 << ";";
						stock_data.conexions[j].push_back(stock.first);
					}
					else
					{
						cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << power + 99 << ";";
						stock_data.conexions[j].push_back(stock_data.my_base_index);
					}
					cerr << "debug : " <<  stock_data.dof_short_by_dist[j][13] << " : " << "[" << stock.first << "]" << stock.second << " < " << stock_data.dof_short_by_dist[j][8] << " " << (stock.second <= stock_data.data_of_cells[j][8]) << endl;
				}
				//if (stock_data.dof_short_by_dist[j][8] == i && stock_data.dof_short_by_dist[j][9] > 0 && stock_data.dof_short_by_dist[j][6] == 1)
				//{
				//	cout << "BEACON" << " " << stock_data.dof_short_by_dist[j][13] << " " << "1" << ";";
				//	cerr << "!!!!!!!    " << stock_data.dof_short_by_dist[j][9] << endl;
				//}
			}
		}
	}
	cout << "BEACON" << " " << stock_data.my_base_index << " " << "1" << ";";
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
//		stock_data.data_of_cells[i].push_back(-1);					// [13] real index 

