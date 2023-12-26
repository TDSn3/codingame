/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos2.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/26 15:54:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

u_tuple choice_pos(Data &data, Stock &stock, int player_drone_id)
{
	u_tuple	pos = {{ 0, 0}};
	
	for (size_t i = 0; i < stock.list_pos[player_drone_id].size(); i++)
	{
		if (!stock.list_pos[player_drone_id][i].visited)
		{
			pos = stock.list_pos[player_drone_id][i].pos;
			break ;
		}
	}

	return (get_real_pos(data, player_drone_id, pos));	
}
