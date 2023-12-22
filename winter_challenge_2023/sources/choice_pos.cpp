/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/21 16:40:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

u_tuple choice_pos(Data &data, Stock &stock, int drone)
{
	if (drone == 0)	
	{
		for (size_t i = 0; i < stock.list_pos.size(); i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				if (data.drones_player[drone]->pos.x == stock.list_pos[i].pos.x && data.drones_player[drone]->pos.y == stock.list_pos[i].pos.y)
				{
					stock.list_pos[i].visited[drone] = true;
					continue ;
				}

				return (stock.list_pos[i].pos);
			}
		}
	}
	else
	{
		for (size_t i = 6; i < stock.list_pos.size(); i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				if (data.drones_player[drone]->pos.x == stock.list_pos[i].pos.x && data.drones_player[drone]->pos.y == stock.list_pos[i].pos.y)
				{
					stock.list_pos[i].visited[drone] = true;
					continue ;
				}

				return (stock.list_pos[i].pos);
			}
		}
		for (size_t i = 0; i < 6; i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				if (data.drones_player[drone]->pos.x == stock.list_pos[i].pos.x && data.drones_player[drone]->pos.y == stock.list_pos[i].pos.y)
				{
					stock.list_pos[i].visited[drone] = true;
					continue ;
				}

				return (stock.list_pos[i].pos);
			}
		}	
	}

	return ((u_tuple){{ 0, 0 }});
}
