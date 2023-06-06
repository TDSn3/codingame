/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_from_base.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:25:02 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/02 15:55:28 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

int		empty_list_queue(std::vector<std::queue<std::pair<int, int> > >	list_queue);
void	strategie_power2(Data &stock_data);
int		stategie_specific(Data &stock_data, int neighbor);

void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int base,
	int &index,
	int &dist,
	int j);



void	bfs_from_base(Data &stock_data)
{
	std::vector<std::queue<std::pair<int, int> > >	list_queue;
	std::vector<bool>								visited(stock_data.data_of_cells.size(), false);
	std::vector<int>								index2;
	std::vector<int>								dist2;

	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
	{
		list_queue.push_back(std::queue<std::pair<int, int> >());
		list_queue[i].push(std::pair<int, int>(stock_data.list_base_index[i] , 0));
		index2.push_back(-1);
		dist2.push_back(0);
		visited[stock_data.list_base_index[i]] = true;
	}

	while (!empty_list_queue(list_queue))
	{
		for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
		{
			if (!list_queue[i].empty())
			{
				index2[i] = list_queue[i].front().first;
				dist2[i] = list_queue[i].front().second;

				list_queue[i].pop();
				for (size_t j = 0; j < 6; j++)
					visit_neighbors(stock_data, list_queue[i], visited, stock_data.list_base_index[i], index2[i], dist2[i], j);
			}
		}
	}

	strategie_power2(stock_data);
}




int	empty_list_queue(std::vector<std::queue<std::pair<int, int> > >	list_queue)
{
	for (size_t i = 0; i < list_queue.size(); i++)
	{
		if (!list_queue[i].empty())
			return (0);
	}
	return (1);
}

void	visit_neighbors(
	Data &stock_data,
	std::queue<std::pair<int, int> > &bfs_queue,
	std::vector<bool> &visited,
	int base,
	int &index,
	int &dist,
	int j)
{
	int	neighbor;

	neighbor = stock_data.data_of_cells[index][j];
	if (neighbor != -1 && !visited[neighbor] && !stock_data.check_opp_base(stock_data, neighbor))
	{
		bfs_queue.push(std::pair<int, int>(neighbor, dist + 1));
		visited[neighbor] = true;

		if (stock_data.data_of_cells[neighbor][9] > 0)
		{			
			if (stategie_specific(stock_data, neighbor))
				return ;

			//	assigne priority cell = 1
			std::pair<int, std::vector<int> > stock = find_next_beacon(stock_data, neighbor, 10, base);

			if (stock.first != -1)
			{
				cerr << stock.first << " ---> " << neighbor << "\n";
				my_line(stock_data, stock.first, neighbor, base, stock.second);
			}
		}
	}
}

int		stategie_specific(Data &stock_data, int neighbor)
{
//	// si je suis bloqué depuis 3 tour
//	if (stock_data.i_am_bloc > 3)
//	{
//		cerr << "!!! I AM BLOC !!! " << stock_data.i_am_bloc << "\n";
//		stock_data.signal_for_crystal = 1;
//		if (stock_data.i_am_bloc == 3)
//			stock_data.i_am_bloc += 3;
//		if (stock_data.beacon_on_res_this_turn > 1)
//			return (1);
//		stock_data.total_ants /= 10;
//		return(0);
//	}

	//	si c'est une carte small et qu'il y a des res et que je suis sur la case 0
	if (stock_data.type_size_map == 1 && stock_data.data_of_cells[0][9] > 0 && neighbor == 0)
		return (0);

	//	si il y a que deux cryst sur la carte
	if (stock_data.number_cryst_cell_start == 2)
		return (0);

	//	si il y a moins d'oeuf que 75% de cryst
	if (stock_data.total_res_egg_start < stock_data.total_res_cryst_start * 0.35)
	{
		if (stock_data.egg_cell_now < stock_data.number_egg_cell_start - 1)
		{
			stock_data.signal_for_crystal = 1;
			return (0);
		}
	}
	if (stock_data.data_of_cells[neighbor][6] == 2 && !stock_data.signal_for_crystal )
		return (1);
	return (0);
}

void	strategie_power2(Data &stock_data)
{
	int	path_power = 1000;
	int	opp_path_power = 0;

	cerr << "conexion :\n";
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			cerr << "┌ " << i << endl;
			for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			{
				cerr << "└ " << j << " : ";
				for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
				{
					int	index = stock_data.conexions[i][j][k];
					
					cerr << index << " (" << stock_data.data_of_cells[ index ][10] << "-"<< stock_data.data_of_cells[ index ][11] << ") " ;
					if (stock_data.data_of_cells[ index ][10] < path_power)
						path_power = stock_data.data_of_cells[ index ][10];
					if (stock_data.data_of_cells[ index ][11] > opp_path_power)
						opp_path_power = stock_data.data_of_cells[ index ][11];
				}
				cerr << "| pp : " << path_power << " | opp : " << opp_path_power << endl;
				if (opp_path_power > path_power)
				{
					cerr << "BLOC !!!" << endl;
					for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
					{
						int	index = stock_data.conexions[i][j][k];

//						if (stock_data.data_of_cells[index][10] < stock_data.data_of_cells[index][11])
//							cout << "BEACON" << " " << index << " " << stock_data.power_cell[index] + 50 << ";";

						if (k == 0)
						{
							cout << "BEACON" << " " << index << " " << 200 << ";";
							if (index == 0)
								cout << "BEACON" << " " << index << " " << 250 << ";";
						}
						else
							cout << "BEACON" << " " << index << " " << std::abs(stock_data.power_cell[index] - 10) << ";";
					}
				path_power = 1000;	
				opp_path_power = 0;
				}
			}
			cerr << "\n";
		}
	}
	cerr << "\n";


	if (stock_data.total_res_egg_now < stock_data.total_res_cryst_now * 0.35)
	{
		if (stock_data.egg_cell_now < stock_data.number_egg_cell_start - 1)
		{
			if (stock_data.list_base_index.size() == 1 && stock_data.give_dist_from_base(stock_data.list_opp_base_index.front()) < 3)
			{
				std::vector<int>	path;
				
				path = find_path_origin_neighbor(stock_data, stock_data.list_base_index.front(), stock_data.list_opp_base_index.front(), 4);
				if (!path.empty())
				{
					for (size_t i = 0; i < path.size(); i++)
						cout << "BEACON" << " " << path[i] << " " << 1000 << ";";
				}
			}
		}
	}

	// if (stock_data.list_base_index.size() == 2)
	// {
	// 	if (stock_data.total_res_egg_now < stock_data.total_res_egg_start / 2)
	// 	{
	// 		for (int i = 0; i < 2; i++)
	// 		{
	// 			if (stock_data.give_dist_from_base(stock_data.list_opp_base_index[i]) < 3)
	// 			{
	// 				std::vector<int>	path;

	// 				path = find_path_origin_neighbor(stock_data, stock_data.list_base_index[i], stock_data.list_opp_base_index[i], 4);
	// 				if (!path.empty())
	// 				{
	// 					for (size_t i = 0; i < path.size(); i++)
	// 						cout << "BEACON" << " " << path[i] << " " << 0 << ";";
	// 				}
	// 			}
	// 		}
	// 	}
	// }

//	for (int i = 0; i < stock_data.number_of_cells; i++)
// 		if (stock_data.give_number_becon_neighbor(i) == 1
//			&& stock_data.check_base(stock_data, i) == -1
//			&& stock_data.data_of_cells[i][9] > 0
//			&& stock_data.data_of_cells[i][10] == 0)
//			cout << "BEACON" << " " << i << " " << stock_data.power_cell[i] * 2 << ";";
}
