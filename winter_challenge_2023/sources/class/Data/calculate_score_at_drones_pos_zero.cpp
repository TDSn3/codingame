/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_score_at_drones_pos_zero.cpp             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 19:16:08 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 19:16:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

pair<int, int>	Data::calculate_score_at_drones_pos_zero(void)	// pair< first int = my_score, second int = foe_score>
{
	int					count_drones_at_zero = 0;
	map<int, s_drone>	new_drones = drones;
	Data				*pt_data = this;
	Data				next_round_data;

	while (count_drones_at_zero < 4)	// drones.size() == 4
	{
		for (map<int, s_drone> :: iterator it = new_drones.begin(); it != new_drones.end(); it++)
		{
			if (it->second.pos.y <= 600)
			{
				if (it->second.pos.y != 0)
					count_drones_at_zero++;
				it->second.pos.y = 0;
			}
			else
				it->second.pos.y -= 600;
		}

		next_round_data = Data(*pt_data, new_drones);
		pt_data = &next_round_data;
	}

	return (pair<int, int>(pt_data->my_score, pt_data->foe_score));
}
