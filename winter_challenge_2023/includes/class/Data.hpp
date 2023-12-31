/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:57:10 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 19:15:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include "../utils.hpp"

class Data
{
	public:
	
		Data(void);
		Data(const Data &src);
		Data(const Data &src, map<int, s_drone> &new_drones);	// simulate input whith new drones position
		~Data(void);

		typedef map<int, s_creature> :: iterator	it_creatures;
		typedef map<int, s_drone> :: iterator		it_drones;

		Data					&operator = (const Data &src);

		int						creature_count;
		map<int, s_creature>	creatures;
		map<int, s_creature>	last_round_creatures;
		map<int, s_drone>		drones;
		vector<s_drone*>		drones_player;	// int for the int of the map<int, s_drone>
		int						my_score;
		int						foe_score;
		int						my_scan_score_not_saved;
		int						my_scan_count;
		int						foe_scan_count;
		int						my_drone_count;
		int						foe_drone_count;
		int						drone_scan_count;
		int 					visible_creature_count;
		int 					radar_blip_count;

		void					round_zero_init(void);
		void					show_creatures(void);
		void					show_drones(void);
		void					update();
		void					reset(void);

		s_drone					*get_nearest_drone(u_tuple origin);
		s_drone					*get_nearest_player_drone(u_tuple origin);
		bool					is_in_light(u_tuple origin);
		bool					is_creature_already_scanned(int id_creature);
		double					distance(int drone_id, int creature_id);
		e_radar					biggest_radar_direction(int drone_id);
		int 					count_no_scaned(void);
		e_zone					get_drone_zone(int drone_id);
		e_zone					get_drone_player_simple_zone(int drone_id);
		pair<int, int>			get_limite_zone(s_creature creature);
		u_tuple					get_round_move(u_tuple origin, u_tuple cible, int max_dist);
		bool					is_scanned(int drone_id, int creature_id);
		pair<bool, int>			is_full_scanned(int player_drone_id);
		pair<bool, int>			is_full_scanned(int drone_id, int type);
		pair<bool, int>			is_full_scanned(int drone_id, int color, bool useless);
		pair<bool, int>			is_full_scanned(e_drone_owner player_or_foe, int type);
		pair<bool, int>			is_full_scanned(e_drone_owner player_or_foe, int color, bool useless);
		void					calculate_advantage_score(void);
		int						get_type_scanned(int type);
		int						get_type_scanned(int player_drone_id, int type);
		pair<int, int>			calculate_score_at_drones_pos_zero(void);	// pair< first int = my_score, second int = foe_score>

	protected:

	private:

};

#endif
