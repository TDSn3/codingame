/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/21 16:06:07 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	game_loop(Data &data, Stock &stock)
{
	(void) stock;
	while (1)
	{
		cerr << "round : " << g_round << endl;
		data.update();
		// data.show_creatures();

		cerr << enum_to_str(data.get_drone_zone(0)) << endl;

		for (int i = 0; i < data.my_drone_count; i++)
		{
			instruction_move(choice_pos(data, stock, i), choice_light(data, i));
		}

		data.reset();
		g_round++;
	}
}
