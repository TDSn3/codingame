/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 12:22:03 by tda-silv         ###   ########.fr       */
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
		stock_data.total_ants = 0;
	
		for (int i = 0; i < stock_data.number_of_cells; i++)
		{
			int resources;	// la quantité actuelle d'oeufs/cristaux sur cette cellule
			int my_ants;	// le montant de vos fourmis sur cette cellule
			int opp_ants;	// la quantité de fourmis adverses sur cette cellule
			cin
				>> resources
				>> my_ants
				>> opp_ants;
			cin.ignore();
			stock_data.data_of_cells[i][9] = resources;
			stock_data.data_of_cells[i][10] = my_ants;
			stock_data.data_of_cells[i][11] = opp_ants;
			stock_data.total_ants += my_ants;
			if (resources > 0 && stock_data.data_of_cells[i][6] == 2)
			{
				if (stock_data.data_of_cells[i][8] == 1)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 2)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 3)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 4)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 5)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 6)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] == 7)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
				else if (stock_data.data_of_cells[i][8] > 7)
				{
					stock_data.res_by_dist[stock_data.data_of_cells[i][8]] += 1;
				}
			}
			else if (resources > 0 && stock_data.data_of_cells[i][6] == 1)
			{
				stock_data.egg_by_dist[stock_data.data_of_cells[i][8]] += 1;
			}
		}
		print_by_step(stock_data);
		cerr << "total_ants :\t"<< stock_data.total_ants << endl;
		cerr << "res_by_dist :\t";
		for (unsigned long int i = 0; i < stock_data.res_by_dist.size(); i++)
		{
			cerr << stock_data.res_by_dist[i] << " ";
			stock_data.res_by_dist[i] = 0;
		}
		cerr << endl;
		cerr << "egg_by_dist :\t";
		for (unsigned long int i = 0; i < stock_data.egg_by_dist.size(); i++)
		{
			cerr << stock_data.egg_by_dist[i] << " ";
			stock_data.egg_by_dist[i] = 0;
		}
		cerr << endl;
		cerr << "conexion :\n";
		for (unsigned long int i = 0; i < stock_data.conexions.size(); i++)
		{
			if (!stock_data.conexions[i].empty())
			{
				cerr << i << " :\t";
				for (unsigned long int j = 0; j < stock_data.conexions[i].size(); j++)
				{
					cerr << stock_data.conexions[i][j] << " ";
					stock_data.conexions[i].erase(stock_data.conexions[i].begin() + j);
				}
				cerr << "\n";
			}
		}
		cerr << endl;
		cout << endl;
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
//					if (stock_data.data_of_cells[j][11] >= stock_data.data_of_cells[j][10] && stock_data.res_by_dist[i] == 1 && stock_data.data_of_cells[j][8] < 4)
//						power+= 1;
//					if (stock_data.data_of_cells[j][11] >= stock_data.data_of_cells[j][10] && stock_data.data_of_cells[j][8] < 3)
//						power+= 1;
					std::pair<int, int>	stock;

					stock = algorithme_bfs_stop_first(stock_data, j, 20);
					if (stock.first != -1 && stock.second <= stock_data.data_of_cells[j][8] && !find_conexion(stock_data, stock.first, j))
					{
						cout << "LINE" << " " << j << " " << stock.first << " " << power + 100 << ";";
						stock_data.conexions[j].push_back(stock.first);
					}
					else
					{
						cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << power + 100 << ";";
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