/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_beacon.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:16:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 04:07:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	cout_beacon(int &l, int &objective_strong_power, vector<int> &path_to_base, int &empty_beacon, vector<int> &history_power_print, vector<int> &history_becon_print);
int		print_stategie_specific(Data &stock_data, int neighbor);
void	verif_bloc(Data &stock_data, vector<int> &history_becon_print);
int		give_small_my_ant_in_path(Data &stock_data, int index_my_ant_origin);
int		give_small_opp_ant_in_path(Data &stock_data, int index_opp_ant_origin);

void	print_beacon(Data &stock_data)
{	
	int	l;
	int				objective_strong_power;
	vector<int>		path_to_base;
	int				empty_beacon;
	vector<int>		history_power_print(stock_data.number_of_cells, 1);
	vector<int>		history_becon_print(stock_data.number_of_cells, 0);

	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			{
				
				empty_beacon = 100;
				path_to_base = find_next_base(stock_data, stock_data.conexions[i][j][0], 30);
				if (!print_stategie_specific(stock_data, path_to_base.back()))
				{
//					cerr << path_to_base.back() << " | " << give_small_opp_ant_in_path(stock_data, stock_data.conexions[i][j]) << endl;

					l = path_to_base.size() - 1;
					while (l > 0) // 0 and not -1 for exclued base
					{
						if (stock_data.data_of_cells[path_to_base[l]][MY_ANTS] < stock_data.calculate_number_ant_desired(path_to_base[l]))
							empty_beacon += 100;
						else
							break ;
						l--;
					}

					l += 3;
					if (l >= (int) path_to_base.size())
						l = path_to_base.size() - 1;
					objective_strong_power = l;

					cout_beacon(l, objective_strong_power, path_to_base, empty_beacon, history_power_print, history_becon_print);
					// for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
					// 	cout << "BEACON" << " " << stock_data.conexions[i][j][k] << " " << 1 << ";";
				}
			}
		}
	}
	for (size_t i = 0; i < history_becon_print.size(); i++)
	{
		if (history_becon_print[i] == 1)
		{
			if (stock_data.data_of_cells[i][MY_ANTS] > 0
				&& stock_data.data_of_cells[i][OPP_ANTS] > 0
				&& stock_data.data_of_cells[i][MY_ANTS] <= stock_data.data_of_cells[i][OPP_ANTS])
			{
				
				int	opp_min_ant = give_small_opp_ant_in_path(stock_data, i);
				int	my_min_ant = give_small_my_ant_in_path(stock_data, i);

				cerr << "index contested : " << i << " | opp min ant " << opp_min_ant << endl;
				cerr << "index contested : " << i << " | my min ant " << my_min_ant << endl;
				if (my_min_ant < opp_min_ant)
				{
					vector<int>		path_to_my_base;
					
					path_to_my_base = find_next_my_base_connected_ant(stock_data, i, 30);
					cerr << "I AM BLOC !!!\n";
					for (int j = 0; j < path_to_my_base.size(); j++)
						cerr << j << " : " << path_to_my_base[j] << endl;
					for (size_t j = 0; j < path_to_my_base.size(); j++)
					{
						if (stock_data.data_of_cells[ path_to_my_base[j] ][MY_ANTS] == my_min_ant)
						{
							cout << "BEACON" << " " << path_to_my_base[j] << " " << 899 << ";";
							stock_data.data_of_cells[ path_to_my_base[j] ][BLOC] = 899;
						}
						else
							cout << "BEACON" << " " << path_to_my_base[j] << " " << 800 << ";";
					}
				}
			}
		}
	}
}

void	cout_beacon(int &l, int &objective_strong_power, vector<int> &path_to_base, int &empty_beacon, vector<int> &history_power_print, vector<int> &history_becon_print)
{
	int	power;

	power = 100;
	while (l > -1)
	{
		if (l == objective_strong_power)
		{
			power = empty_beacon;
			if (history_power_print[path_to_base[l]] > power)
				power = history_power_print[path_to_base[l]];
			
			cout << "BEACON" << " " << path_to_base[l] << " " << power << ";";
			history_power_print[path_to_base[l]] = power;
		}
		else
			cout << "BEACON" << " " << path_to_base[l] << " " << 100 << ";";
		history_becon_print[path_to_base[l]] = 1;
		l--;
	}
}

int		print_stategie_specific(Data &stock_data, int neighbor)
{
	// si il y a au moins 20 % d'oeuf au début, qu'il en reste la moitié et que la cell visitée est un cryst
	if (stock_data.total_cell_egg_start * 100 / (stock_data.total_cell_egg_start + stock_data.total_cell_cryst_start) > 20
		&& stock_data.total_res_egg_now > stock_data.total_res_egg_start / 2
		&& stock_data.data_of_cells[neighbor][TYPE] == 2)
		return (1);

	return (0);
}

void	verif_bloc(Data &stock_data, vector<int> &history_becon_print)
{
	vector<int>		path_to_base;
	int				path_number_my_ant = 1000;
	int				opp_path_number_my_ant = 0;

	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			{
//				path_to_base = find_next_base(stock_data, stock_data.conexions[i][j][0], 30);
//				for (size_t k = 0; k < path_to_base.size(); k++)
//				{
//					int	index = path_to_base[k];
//					
//					if (stock_data.data_of_cells[index][MY_ANTS] < path_number_my_ant && stock_data.data_of_cells[index][MY_ANTS] != -1)
//						path_number_my_ant = stock_data.data_of_cells[index][MY_ANTS];
//					if (stock_data.data_of_cells[index][OPP_ANTS] > opp_path_number_my_ant && stock_data.data_of_cells[index][OPP_ANTS] != -1)
//						opp_path_number_my_ant = stock_data.data_of_cells[index][OPP_ANTS];
//				}
				if (opp_path_number_my_ant > path_number_my_ant)
				{
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
//						else
//							cout << "BEACON" << " " << index << " " << std::abs(stock_data.power_cell[index] - 10) << ";";
					}
				path_number_my_ant = 1000;	
				opp_path_number_my_ant = 0;
				}
			}
		}
	}
}

int	give_small_my_ant_in_path(Data &stock_data, int index_my_ant_origin)
{
	vector<int>		path_to_opp_base;
	int				small_num_ant;

	small_num_ant = 1000;
	path_to_opp_base = find_next_my_base_connected_ant(stock_data, index_my_ant_origin, 30);
	if (path_to_opp_base.empty())
		return (0);
	for (size_t i = 0; i < path_to_opp_base.size(); i++)
		if (stock_data.data_of_cells[path_to_opp_base[i]][MY_ANTS] < small_num_ant && stock_data.data_of_cells[path_to_opp_base[i]][MY_ANTS] > 0)
			small_num_ant = stock_data.data_of_cells[path_to_opp_base[i]][MY_ANTS];
	return (small_num_ant);
}

int	give_small_opp_ant_in_path(Data &stock_data, int index_opp_ant_origin)
{
	vector<int>		path_to_opp_base;
	int				small_num_ant;

	small_num_ant = 1000;
	path_to_opp_base = find_next_opp_base_connected_ant(stock_data, index_opp_ant_origin, 30);
	if (path_to_opp_base.empty())
		return (0);
	for (size_t i = 0; i < path_to_opp_base.size(); i++)
		if (stock_data.data_of_cells[path_to_opp_base[i]][OPP_ANTS] < small_num_ant && stock_data.data_of_cells[path_to_opp_base[i]][OPP_ANTS] > 0)
			small_num_ant = stock_data.data_of_cells[path_to_opp_base[i]][OPP_ANTS];
	return (small_num_ant);
}
