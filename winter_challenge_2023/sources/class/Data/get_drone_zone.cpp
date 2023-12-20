/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_drone_zone.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:54:56 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:05 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

e_zone	Data::get_drone_zone(int drone_id)
{
	int x = drones[drone_id].pos.x;
	int y = drones[drone_id].pos.y;

	if (x <= 4999)	// Zone gauche (L)
	{
		if (y <= 2499)
			return L0;
		else if (y <= 4999)
			return L1;
		else if (y <= 7499)
			return L2;
		else
			return L3;
	}
	else			// Zone droite (R)
	{
		if (y <= 2499)
			return R0;
		else if (y <= 4999)
			return R1;
		else if (y <= 7499)
			return R2;
		else
			return R3;
	}
}
