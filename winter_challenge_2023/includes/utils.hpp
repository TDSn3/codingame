/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:49:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 13:51:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

enum e_radar
{
	T			= 1 << 0,
	B			= 1 << 1,
	L			= 1 << 2,
	R			= 1 << 3,

	TL			= T | L,
	TR			= T | R,
	BL			= B | L,
	BR			= B | R
};

enum e_drone_owner
{
	PLAYER,
	FOE
};

union u_tuple
{
	struct
	{
		double	x;
		double	y;
	};
	double		tuple[2];
};

extern volatile unsigned int	g_round;

#endif
