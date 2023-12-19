/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 19:37:23 by tda-silv         ###   ########.fr       */
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

struct s_creature
{
	int					id;
	int					color;	// de 0 à 3
	int					type;	// de 0 à 2

	int					x;		// position
	int					y;		//

	int					vx;		// vitesse
	int 				vy;		//

	bool				my_scan;
	bool				foe_scan;

	map<int, double>	distance_my_drone;
};

struct s_drone
{
	int	id;
	int	x;
	int	y;
	int	emergency;
	int battery;
};

class Data
{
	public:
	
		Data(void);
		Data(const Data &src);
		~Data(void);

		int						creature_count;
		map<int, s_creature>	creatures;
		map<int, s_drone>		my_drone;
		map<int, s_drone>		foe_drone;
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
		void					update(void);
		double					distance(int drone_id, int creature_id);

	protected:

	private:

};

#endif
