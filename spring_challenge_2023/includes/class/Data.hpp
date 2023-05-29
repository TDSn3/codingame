/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/29 19:01:56 by tda-silv         ###   ########.fr       */
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

class Data
{
public:

	Data(void);
	Data(int my_base_index, int number_of_cells);
	Data(const Data &src);
	~Data(void);

	int									my_base_index;
	int									number_of_cells;
	int									total_ants;
	int									total_opp_ants;
	int									max_dist;
	int									beacon;
	int									egg_and_cryst;
	int									power_egg;
	std::vector<int>					res_by_dist;
	std::vector<int>					egg_by_dist;
	std::vector<int>					power_cell;
	std::vector<int>					beacon_this_loop;
	std::vector<int>					conected_to_base;
	std::vector<std::vector<int> >		conexions;
	std::map<int, std::vector<int> >	data_of_cells;
	std::map<int, std::vector<int> >	dof_short_by_dist; // dof = data_of_cells
	std::list<std::list<int> >			path_to_base;

protected:

private:

};

#endif
