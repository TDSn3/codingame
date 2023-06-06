/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 05:29:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_HPP
# define HEADER_HPP

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
# include <random>
# include <ctgmath>

using namespace std;

enum index_cell
{
	TYPE 						= 6,
	INITIAL_RES					= 7,
	RES							= 8,
	MY_ANTS						= 9,
	OPP_ANTS					= 10,
	WEIGHT						= 11,
	BEACON_THIS_LOOP			= 12,
	CONNECTED_MY_BASEE_INDEX	= 13,
	CONNECTION_IN				= 14,
	CONNECTION_OUT				= 15,
	POWER						= 16,
	BLOC						= 17
};

# include "./class/Data.hpp"

void							start(Data &stock_data);
void							start_loop(Data &stock_data);
void							end_loop(Data &stock_data);
void							dist_all_cell_from_base(Data &stock_data, int origin, int index_base, int my_or_opp, int max_dist);
pair<int, vector<int> >			find_next_beacon(Data &stock_data, int origin, int index_base, int max_dist);
vector<int>						find_next_ant(Data &stock_data, int origin, int max_dist);
std::vector<int>				find_next_base(Data& stock_data, int origin, int max_dist);	// front beacon_dest, back res_origin
std::vector<int>				find_next_opp_base_connected_ant(Data& stock_data, int origin, int max_dist);
std::vector<int>				find_next_my_base_connected_ant(Data& stock_data, int origin, int max_dist);
int								my_line(Data &stock_data, int origin, int neighbor, int index_base, vector<int> path);
void							print_beacon2(Data &stock_data);
void							print_beacon(Data &stock_data);
void							principal(Data &stock_data);

#endif
