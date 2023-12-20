/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:46:22 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 17:17:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOCK_HPP
# define STOCK_HPP

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

# include "../utils.hpp"

struct s_pos_node
{
	u_tuple	pos;
	bool	visited;
};

class Stock
{
	public:
	
		Stock(void);
		Stock(const Stock &src);
		~Stock(void);

		vector<s_pos_node>	list_pos;

	protected:

	private:

};

#endif
