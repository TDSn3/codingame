/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/25 14:32:31 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	game_loop(Data &data, Stock &stock)
{
	u_tuple	pos;
	bool	light;

	while (1)
	{
		cerr << "round : " << g_round << endl;
		data.update();
		data.show_creatures();
		data.show_drones();

		if (g_round == 0)
			stock.init_list_pos(data);
		else
			stock.update(data);

		for (int i = 0; i < data.my_drone_count; i++)
		{
			light = choice_light(data, stock, i);	// light before pos because stock change in choice_pos()
			pos = choice_pos(data, stock, i);
			instruction_move(pos, light);
		}

		data.reset();
		g_round++;
	}
}
