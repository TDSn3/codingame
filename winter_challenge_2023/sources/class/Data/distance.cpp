/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:30:26 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/22 15:25:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

struct s_point
{
	double	x;
	double	y;
};

double	Data::distance(int drone_id, int creature_id)
{
	s_point	p1 =	{
						static_cast<double>(drones[drone_id].pos.x),
						static_cast<double>(drones[drone_id].pos.y)
					};

	s_point	p2 =	{
						static_cast<double>(creatures[creature_id].pos.x),
						static_cast<double>(creatures[creature_id].pos.y)
					};

	double	deltaX = p2.x - p1.x;
	double	deltaY = p2.y - p1.y;

	if (creatures[creature_id].pos.x == -1)
		return (-1);

	return (sqrt(pow(deltaX, 2) + pow(deltaY, 2)));
}
