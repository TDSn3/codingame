/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 01:18:09 by tda-silv         ###   ########.fr       */
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
# include <ctgmath>

using namespace std;

class Data
{
	public:
	
		Data(void);
		Data(const Data &src);
		~Data(void);
	
		Data								&operator = (const Data &right);

//

		int									number_of_cells;
		map<int, vector<int> >				data_of_cells;			// [0-5] neighbor
																	// [6]   type
																	// [7]   initial resources
																	// [8]   resources
																	// [9]   my ants
																	// [10]  opp ants
																	// [11]  weight
																	// [12]  beacon this loop
																	// [13]  connected my base index
																	// [14]  connection in
																	// [15]  connection output to the base
																	// [16]  power
																	// [17]  bloc

		vector<int>							list_my_base_index;		// x * number_of_base
		vector<int>							list_opp_base_index;	// [x] -> count_base
		int									my_score;
		int									opp_score;
		vector<int>							my_score_history;
		vector<int>							opp_score_history;

		vector<vector<int> >				dist_from_my_base;		// x * number_of_cells, y * number_of_cells
		vector<vector<int> >				dist_from_opp_base;		// [x] -> index_base, [y] -> index_cell

		int									total_ant;
		int									my_ant;
		int									opp_ant;

		int									total_res_cryst_start;
		int									total_cell_cryst_start;
		int									total_res_cryst_now;
		int									total_cell_cryst_now;
		int									my_cell_res_cryst_now;
		int									opp_cell_res_cryst_now;

		int									total_res_egg_start;
		int									total_cell_egg_start;
		int									total_res_egg_now;
		int									total_cell_egg_now;
		int									my_cell_res_egg_now;
		int									opp_cell_res_egg_now;

		int									beacon;
		int									beacon_on_res;

		int									signal_res;				// 0 egg, 1 egg/cryst

		vector<vector<vector<int> > >		conexions;				// front res_origin, back beacon_dest

		Data								*data_prev;

//

		void								assign_beacon(int index, int power);
		int									give_total_beacon_power(void);
		int									give_total_cell_my_ant(void);

		int									check_base(int index);
		int									check_opp_base(int index);
		int									give_dist_from_opp_base(int index);
		int									give_dist_from_base(int index);

		double								ratio_dist(int index);
		double								ratio_opp_dist(int index);
		double								ratio_dist_from_zero(int index);

		int									calculate_number_ant_desired(int index);
		void								move_ant_to_resource(int index_res);
		int									all_other_number_ant_desired(int index_exclude);

	protected:
	
	private:

};

#endif
