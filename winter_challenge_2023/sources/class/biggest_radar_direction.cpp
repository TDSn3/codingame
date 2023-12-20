/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_radar_direction.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 13:57:54 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/header.hpp"

e_radar	Data::biggest_radar_direction(int drone_id)
{
	e_radar	tblr;

	string	lf;
	int		count[4] = {};	// { tl, tr, bl, br}
	int		biggest_radar_int = -1;
	int		biggest_radar;

	(drones[drone_id].pos.x < 4999) ? tblr = L : tblr = R;

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.radar[drone_id] == TL)
			count[0]++;
		else if (it->second.radar[drone_id] == TR)
			count[1]++;
		else if (it->second.radar[drone_id] == BL)
			count[2]++;
		else if (it->second.radar[drone_id] == BR)
			count[3]++;
	}

	for (int i = 0; i < 4; i++)
	{
		if (biggest_radar_int < count[i])
		{
			biggest_radar_int = count[i];
			biggest_radar = i;
		}
		else if (biggest_radar_int == count[i])
		{
			if (lf == "L")
			{
				if (biggest_radar != 0 && biggest_radar != 2)
					biggest_radar = i;
			}
			else
			{
				if (biggest_radar != 1 && biggest_radar != 3)
					biggest_radar = i;				
			}
		}
	}

	if (biggest_radar == 0)
		return (TL);
	else if (biggest_radar == 1)
		return (TR);
	else if (biggest_radar == 2)
		return (BL);
	else
		return (BR);
}