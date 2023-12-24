/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/24 12:19:01 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

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

# include "../utils.hpp"

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

	map<int, e_radar>	radar;

	bool				in_light;			// 0 dark | 1 flashed
};

struct s_drone
{
	int				id;
	u_tuple			pos;			// position
	int				emergency;		// 1 mode urgence, 0 sinon
	int				battery;
	e_drone_owner	owner;
	map<int, int>	round_light;	// round, light
};

class Data
{
	public:
	
		Data(void);
		Data(const Data &src);
		~Data(void);

		int						creature_count;
		map<int, s_creature>	creatures;
		map<int, s_creature>	last_round_creatures;
		map<int, s_drone>		drones;
		vector<s_drone*>		drones_player;	// int for the int of the map<int, s_drone>
		int						my_score;
		int						foe_score;
		int						my_scan_count;
		int						foe_scan_count;
		int						my_drone_count;
		int						foe_drone_count;
		int						drone_scan_count;
		int 					visible_creature_count;
		int 					radar_blip_count;

		void					show_creatures(void);
		void					show_drones(void);
		void					update();
		void					reset(void);

		s_drone					*get_nearest_drone(u_tuple origin);
		bool					is_in_light(u_tuple origin);
		double					distance(int drone_id, int creature_id);
		e_radar					biggest_radar_direction(int drone_id);
		int 					count_no_scaned(void);
		e_zone					get_drone_zone(int drone_id);
		u_tuple					get_round_move(u_tuple origin, u_tuple cible, int max_dist);

	protected:

	private:

};

#endif
