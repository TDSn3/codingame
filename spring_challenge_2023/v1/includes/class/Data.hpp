/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/02 14:10:20 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iomanip>
# include <list>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <queue>
# include <cmath>
# include <array>

class Data
{
public:

	Data(void);
	Data(int my_base_index, int number_of_cells);
	Data(const Data &src);
	~Data(void);

	int												my_base_index;
	int												number_of_cells;
	int												total_ants;
	int												total_opp_ants;
	int												max_dist;
	int												beacon;
	int												total_power_beacon;
	int												power_egg;
	int												limit_egg;
	int												number_egg_cell_start;
	int												egg_cell_now;
	int												number_cryst_cell_start;
	int												cryst_cell_now;
	int												signal_for_crystal;
	int												total_res_cryst_start;
	int												total_res_egg_start;
	int												total_res_cryst_now;
	int												total_res_egg_now;
	int												type_size_map;
	int												my_score;
	int												my_score_last_turn;
	int												opp_score;
	int												i_am_bloc;
	int												max_search_dist;
	int												beacon_on_res_this_turn;
	std::vector<int>								list_base_index;
	std::vector<int>								list_opp_base_index;
	std::vector<int>								res_by_dist;
	std::vector<int>								egg_by_dist;
	std::vector<int>								power_cell;
	std::vector<int>								priority_cell;
	std::vector<int>								beacon_this_loop;
	std::vector<int>								conected_to_base;
	std::vector<std::vector<std::vector<int> > >	conexions;
	std::map<int, std::vector<int> >				data_of_cells;
	std::vector<std::vector<int> >					dist_from_base;
	std::vector<std::vector<int> >					dist_from_opp_base;
	std::map<int, std::vector<int> >				dof_short_by_dist; // dof = data_of_cells
	std::list<std::list<int> >						path_to_base;

	int												check_base(Data& stock_data, int index);
	int												check_opp_base(Data &stock_data, int index);
	int												give_dist_from_opp_base(int index);
	int												give_dist_from_base(int index);
	double											ratio_dist(int index);
	double											ratio_opp_dist(int index);
	double											ratio_dist_from_zero(int index);
	int												give_number_becon_neighbor(int index);

protected:

private:

};

#endif
