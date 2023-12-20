/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 14:18:24 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	game_loop(Data &data)
{
	while (1)
	{
		cerr << "round : " << g_round << endl;
		data.update();
		// data.show_creatures();

		for (int i = 0; i < data.my_drone_count; i++)
		{
			instruction_move(choice_pos(data), choice_light(data));
			// instruction_wait(1);
		}

		data.reset();
		g_round++;
	}
}
