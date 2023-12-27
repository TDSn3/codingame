/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:12:11 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/26 18:51:21 by tda-silv         ###   ########.fr       */
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

# include "./utils.hpp"
# include "./color.hpp"
# include "./class/Data.hpp"
# include "./class/Stock.hpp"

void	game_loop(Data &data, Stock &stock);
double	distance_tuple(u_tuple a, u_tuple b);
void	instruction_move(u_tuple pos, bool light);
void	instruction_wait(bool light);
u_tuple	choice_pos(Data &data, Stock &stock, int player_drone_id);
u_tuple	get_real_pos(Data &data, int player_drone_id, u_tuple pos);
bool	choice_light(Data &data, Stock &stock, int player_drone_id, u_tuple pos_drone_end_round);
string	enum_to_str(e_zone token);
string	enum_to_str(e_radar token);

#endif
