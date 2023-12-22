/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 17:02:49 by tda-silv         ###   ########.fr       */
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

		if (g_round == 0)
			stock.init_list_pos(data);

		cerr << enum_to_str(data.get_drone_zone(0)) << endl;

		for (int i = 0; i < data.my_drone_count; i++)
		{
			pos = choice_pos(data, stock, i);
			light = choice_light(data, i);
			instruction_move(pos, light);
		}

		data.reset();
		g_round++;
	}
}
