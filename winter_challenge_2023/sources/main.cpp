/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2024/01/03 08:51:27 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

volatile unsigned int	g_round = 0;

int main()
{
	list<Game>	games;
	Data		data;
	Stock		stock;
	u_tuple		pos;
	bool		light;

	data.round_zero_init();

	while (1)	// game loop
	{
		data.update();

		games.push_back(Game(g_round, data));

		data.show_creatures();
		data.show_drones();

		if (g_round == 0)
			stock.init_list_pos(data);
		else
			stock.update(data);

		for (int i = 0; i < data.my_drone_count; i++)
		{
			// get_objective_pos(games, data, i);
			pos = choice_pos(data, stock, i);
			light = choice_light(data, stock, i, pos);
			instruction_move(pos, light);
		}

		data = Data(data);
		data.reset();

		g_round++;
	}

	return (0);
}
