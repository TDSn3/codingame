/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 09:27:58 by tda-silv         ###   ########.fr       */
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
	int	id;
	int	color;	// de 0 à 3
	int	type;	// de 0 à 2

	int	x;		// position
	int	y;		//

	int	vx;		// vitesse
	int vy;		//
};

class Data
{
	public:
	
		Data(void);
		Data(const Data &src);
		~Data(void);

		int						creature_count;
		map<int, s_creature>	creatures;
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

	protected:

	private:

};

#endif
