/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/28 17:30:55 by tda-silv         ###   ########.fr       */
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

using namespace std;

# include "./class/Data.hpp"

void								start(Data &stock_data);
void								start_2(Data &stock_data);
void								algorithme_bfs(Data& stock_data, int origin, int max_dist);
std::vector<int>					algorithme_bfs_2(Data& stock_data, int origin, int dest, int max_dist);
std::pair<int, int>					find_next_cell_conected(Data& stock_data, int origin, int max_dist);
std::pair<int, std::vector<int> >	find_next_res(Data& stock_data, int origin, int max_dist);
std::pair<int, std::vector<int> >	find_next_egg(Data& stock_data, int origin, int max_dist);
std::pair<int, std::vector<int> >	find_next_phero(Data& stock_data, int origin, int max_dist);
std::pair<int, std::vector<int> >	find_base(Data& stock_data, int origin, int max_dist);
void								my_line(Data &stock_data, int &origin, int neighbor, int dist);
void								print_one_path(Data &stock_data, int &origin);
void								print_by_step(Data& stock_data);
void								debug(Data &stock_data);

#endif
