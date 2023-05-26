/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/26 15:21:31 by tda-silv         ###   ########.fr       */
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
#include <queue>
#include <cmath>

using namespace std;

# include "./class/Data.hpp"

void				start(Data &stock_data);
void				start_2(Data &stock_data);
void				algorithme_bfs(Data& stock_data, int origin, int max_dist);
std::pair<int, int>	algorithme_bfs_stop_first(Data& stock_data, int origin, int max_dist);
void				debug(Data &stock_data);


#endif
