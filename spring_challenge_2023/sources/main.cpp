/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/27 14:12:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_by_step(Data& stock_data, int src_index);

int main()
{
	Data	stock_data;

	cerr << "Start main" << endl;
	start(stock_data);
	while (1)
	{	
		start_2(stock_data);

		print_by_step(stock_data, stock_data.my_base_index);

		debug(stock_data);
	}
}

void	test(Data &stock_data, std::vector<bool> &star, int &origin)
{
	std::queue<std::pair<int, int> > bfs_queue;
	std::vector<bool> visited(stock_data.data_of_cells.size(), false);

	bfs_queue.push(std::pair<int, int>(origin, 0));
	visited[origin] = true;
	while (!bfs_queue.empty())
	{
		int index = bfs_queue.front().first;
		int dist = bfs_queue.front().second;
		bfs_queue.pop();

		if (dist < 20)
		{
			for (int j = 0; j < 6; j++)
			{
				int neighbor = stock_data.data_of_cells[index][j];
//				cerr << index << " " << j << " === " << stock_data.data_of_cells[index][j] << endl;
				if (neighbor != -1 && !visited[neighbor])
				{
					bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
					visited[neighbor] = true;
					int stock_neighbor = neighbor;
					if (neighbor == stock_data.my_base_index || (stock_data.data_of_cells[neighbor][6] == 2 && stock_data.data_of_cells[neighbor][9] > 0))
					{
						if ((dist + 1 <= stock_data.data_of_cells[neighbor][8] && star[neighbor] == false) || neighbor == stock_data.my_base_index)
						{
							int	dist_back;

							dist_back = stock_data.data_of_cells[neighbor][8];
							cout << "BEACON" << " " << neighbor << " "  << "1" << ";";
							stock_data.pheromone[neighbor]++;
							cerr << "+---START---+" << endl;
							cerr << neighbor << endl;
							while (neighbor != origin)
							{
								int	stock_index_phero = -1;
								int	stock_phero = 0;

								for (int j = 0; j < 6; j++)
								{
									int	index_back;
									
									index_back = stock_data.data_of_cells[neighbor][j];
									if (stock_data.pheromone[index_back] > stock_phero && index_back != neighbor)
									{
										stock_index_phero = index_back;
										stock_phero = stock_data.pheromone[index_back];
									}
								}
								if (stock_phero > 0)
								{
									cerr << "PHERO ! " << stock_index_phero << endl;
									cout << "BEACON" << " " << stock_index_phero << " " << "1" << ";";
									stock_data.pheromone[stock_index_phero]++;
									dist_back = stock_data.data_of_cells[stock_index_phero][8];
									neighbor = stock_index_phero;
									continue ;
								}
								for (int j = 0; j < 6; j++)
								{
									int	index_back;
									
									index_back = stock_data.data_of_cells[neighbor][j];
									if (stock_data.data_of_cells[index_back][8] < dist_back)
									{
										cerr << "Non. " << index_back << endl;
										cout << "BEACON" << " " << index_back << " " << "1" << ";";
										stock_data.pheromone[index_back]++;
										dist_back--;
										neighbor = index_back;
										break ;
									}
								}
							}
							cerr << "O___END___O" << endl;


						//	cout << "LINE" << " " << origin << " " << neighbor << " " << "1" << ";";
							cerr << origin << " ---> " << stock_neighbor << endl;
							cerr << stock_neighbor << " dist :\t" << dist + 1 << endl;
							cerr << stock_neighbor << " dist base\t: " << stock_data.data_of_cells[stock_neighbor][8] << endl;
							star[stock_neighbor] = true;
						}
					}
				}
			}
		}
	}
}

void	print_by_step(Data& stock_data, int src_index)
{
	std::vector<bool> star(stock_data.data_of_cells.size(), false);

//	parcour chaque cercle autour de la base
//	i == dist du cercle par rapport a la base
	for (unsigned long int i = 0; i < stock_data.data_of_cells.size(); i++)
	{
//		si il y a un oeuf a moins de 1 de la base		
		if (stock_data.egg_by_dist[i] > 0 && i < 2)
		{
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
				if (stock_data.data_of_cells[j][8] == (int) i && stock_data.data_of_cells[j][9] > 0 && stock_data.data_of_cells[j][6] == 1)
					cout << "LINE" << " " << stock_data.my_base_index << " " << j << " " << "1" << ";";
			return ;
		}
/*
		if (i == 0)
		{
//			parcour chaque index du cercle i
			for (unsigned long int j = 0; j < stock_data.data_of_cells.size(); j++)
			{
//				si l'index est au bon cercle
//				si il y a des ressources
//				si c'est un crystal
				if (stock_data.data_of_cells[j][8] == (int) i + 1
					&& stock_data.data_of_cells[j][9] > 0
					&& stock_data.data_of_cells[j][6] == 2)
				{
					cerr << "---> " << j << "\n";
					std::pair<int, int>	next_index;

					next_index = algorithme_bfs_stop_first(stock_data, src_index, 20);
					if (next_index.first != -1)
					{
						cerr << "OUI\n";
						cerr << "next index " << src_index << " " << next_index.first << ", " << next_index.second << "\n";
						cout << "LINE" << " " << src_index << " " << next_index.first << " " << "1" << ";";
						stock_data.conexions[src_index].push_back(next_index.first);
						cerr << "connexion add " << src_index << "--->" << next_index.first << "\n";
					}
				}
			}
			visited[src_index] = true;
		}
*/

		int	real_index;

		real_index = stock_data.dof_short_by_dist[i][13];

//		cerr << "┬ " << i << endl;
//		cerr << "└───── " << real_index << endl;

		if (i == 0
			|| (stock_data.data_of_cells[real_index][9] > 0
				&& stock_data.data_of_cells[real_index][6] == 2))
		{
			cerr << "===> " << real_index << endl;
//			test(stock_data, star, real_index);
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

