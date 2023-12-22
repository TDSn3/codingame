/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_pos.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:41:35 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 11:21:49 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

u_tuple choice_pos(Data &data, Stock &stock, int drone)
{
	u_tuple	ret;
	
	if (drone == 0)	
	{
		for (size_t i = 0; i < stock.list_pos.size(); i++)
		{
			if (!stock.list_pos[i].visited[drone])
			{
				if (data.drones_player[drone]->pos.y >= stock.list_pos[i].pos.y - 300 && data.drones_player[drone]->pos.y <= stock.list_pos[i].pos.y + 300)
				{
					stock.list_pos[i].visited[drone] = true;
					continue ;
				}

				cerr << "cible : " << stock.list_pos[i].pos.x << " " << stock.list_pos[i].pos.y << endl;

				ret = data.get_round_move(
					(u_tuple){{ data.drones_player[drone]->pos.x, data.drones_player[drone]->pos.y }},
					(u_tuple){{ stock.list_pos[i].pos.x, stock.list_pos[i].pos.y }},
					600
				);
				return (ret);
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
