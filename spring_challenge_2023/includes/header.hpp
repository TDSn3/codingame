/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/30 04:00:45 by tda-silv         ###   ########.fr       */
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

using namespace std;

# include "./class/Data.hpp"

void								start(Data &stock_data);
void								start_2(Data &stock_data);
void								distance_all_cell_from_base(Data& stock_data, int origin, int max_dist, int index_base);
std::vector<int>					find_path_origin_neighbor(Data& stock_data, int origin, int dest, int max_dist);
std::pair<int, std::vector<int> >	find_next_beacon(Data& stock_data, int origin, int max_dist, int index_base);
int									my_line(Data &stock_data, int origin, int neighbor);
void								debug(Data &stock_data);
void								bfs_from_base(Data &stock_data);

#endif
