/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:49:59 by tda-silv          #+#    #+#             */
/*   Updated: 2024/01/03 09:23:33 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iomanip>
# include <list>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <queue>
# include <cmath>
# include <array>
# include <ctgmath>

using namespace std;

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

struct s_scan
{
	bool	my_scan_no_saved;
	bool	foe_scan_no_saved;
};

struct s_creature
{
	int					id;
	int					color;				// de 0 à 3	// monster -1
	int					type;				// de 0 à 2	// monster -1

	bool				visible;

	u_tuple				pos;				// position
	u_tuple				next_pos;			// position at the end of the round
	u_tuple				next_next_pos;		// position at the start of the next round for last_round_creatures
	u_tuple				v;					// vitesse (velocity)

	bool				my_scan_saved;
	bool				foe_scan_saved;

	map<int, s_scan>	scan_no_saved;		// PLAYER & FOE

	bool				radar_signal;

	map<int, e_radar>	radar;

	array<u_tuple, 4>	radar_predict;		// Square :
											// [0] top left corner,
											// [1] top right corner,
											// [2] bot right corner,
											// [3] bot left corner

	u_tuple				predict_center;
	bool				predict_center_target_by_drone;

	bool				in_light;			// 0 dark | 1 flashed

	bool				broken_simetric;	// 0 not broken | 1 broken
};

struct s_drone
{
	int				id;
	u_tuple			pos;			// position
	int				emergency;		// 1 mode urgence, 0 sinon
	int				battery;
	e_drone_owner	owner;
	map<int, int>	round_light;	// round, light

	int				potential_point;			// without bonus first scan
	int				first_scan_potential_point;	// with bonus first scan
	int				potential_point_combo;
	int				first_potential_point_combo;
	int				total_potential_point;

	bool			use_predict_last_round;
	bool			target_creature;
	s_creature		*target_creature_pt;
	u_tuple			target_creature_predict_center;
};

struct s_compare_drone_pos_y
{
	bool	operator () (const s_drone *a, const s_drone *b)
	{
		return (a->pos.y < b->pos.y);
	}
};

double	distance_tuple(u_tuple a, u_tuple b);

struct s_compare_creature_predict_center
{
	s_compare_creature_predict_center(u_tuple origin) : origin(origin) {}

	u_tuple	origin;
	
	bool	operator () (const s_creature *a, const s_creature *b)
	{
		u_tuple	origin_y_a = origin;
		u_tuple	origin_y_b = origin;

		origin_y_a.y = a->predict_center.y;
		origin_y_b.y = b->predict_center.y;

		return (distance_tuple(a->predict_center, origin_y_a) < distance_tuple(b->predict_center, origin_y_b));
	}
};

extern volatile unsigned int	g_round;

#endif
