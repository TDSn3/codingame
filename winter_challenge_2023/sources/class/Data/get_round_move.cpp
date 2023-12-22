/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_round_move.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:00:43 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 11:15:00 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

u_tuple	Data::get_round_move(u_tuple origin, u_tuple cible, int max_dist)
{
	int		dx = cible.x - origin.x;
	int		dy = cible.y - origin.y;
	double	origin_cible_dist = sqrt(dx * dx + dy * dy);
	double	ratio;

	if (origin_cible_dist <= max_dist)
		return cible;

	ratio = max_dist / origin_cible_dist;
	u_tuple ret = {{
		origin.x + static_cast<int>(dx * ratio),
		origin.y + static_cast<int>(dy * ratio)
	}};

	return (ret);
}
