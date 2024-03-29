/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:46:22 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 13:02:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STOCK_HPP
# define STOCK_HPP

# include "../utils.hpp"

class Data;

struct s_pos_node
{
	u_tuple			pos;
	bool			visited;
	e_tb			direction_goal;

	s_pos_node(u_tuple pos) : pos(pos), visited(false), direction_goal(BOT) {}
};

class Stock
{
	public:
	
		Stock(void);
		Stock(const Stock &src);
		~Stock(void);

		map<int, vector<s_pos_node> >	list_pos;	// int = player_drone

		void	init_list_pos(Data &data);
		void	update(Data &data);
		int		index_vector_first_visited_false(int drone);

	protected:

	private:

};

#endif
