/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:49:59 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/26 17:02:04 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

// x(right - left), y(top - bot)

//	zone 0 : 0 - 2499
//	zone 1 : 2500 - 4999
//	zone 2 : 5000 - 7499
//	zone 3 : 7500 - 9999

//	left L : 0 - 4999
//	right R : 5000 - 9999

//	zone L0 : x(0 - 4999),		y (0 - 2499)
//	zone R0 : x(5000 - 9999),	y (0 - 2499)

//	zone L1 : x(0 - 4999),		y (2500 - 4999)
//	zone R1 : x(5000 - 9999),	y (2500 - 4999)

//	zone L2 : x(0 - 4999),		y (5000 - 7499)
//	zone R2 : x(5000 - 9999),	y (5000 - 7499)

//	zone L3 : x(0 - 4999),		y (7500 - 9999)
//	zone R3 : x(5000 - 9999),	y (7500 - 9999)

enum e_zone
{
	Z0	= -1,
	Z1	= 0,
	Z2	= 1,
	Z3	= 2,

	L0,
	R0,

	L1,
	R1,

	L2,
	R2,

	L3,
	R3
};

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

enum e_tb
{
	TOP,
	BOT
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
