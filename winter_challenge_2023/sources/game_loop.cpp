/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:40:05 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/18 18:03:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	game_loop(Data &data)
{
	while (1)
	{
		cin >> data.my_score; cin.ignore();
		cin >> data.foe_score; cin.ignore();
		cin >> data.my_scan_count; cin.ignore();

		for (int i = 0; i < data.my_scan_count; i++)
		{
			int creature_id;
			cin >> creature_id; cin.ignore();
		}

		cin >> data.foe_scan_count; cin.ignore();

		for (int i = 0; i < data.foe_scan_count; i++)
		{
			int creature_id;
			cin >> creature_id; cin.ignore();
		}

		cin >> data.my_drone_count; cin.ignore();

		for (int i = 0; i < data.my_drone_count; i++)
		{
			int drone_id;
			int drone_x;
			int drone_y;
			int emergency;
			int battery;
			cin >> drone_id >> drone_x >> drone_y >> emergency >> battery; cin.ignore();
		}

		cin >> data.foe_drone_count; cin.ignore();

		for (int i = 0; i < data.foe_drone_count; i++)
		{
			int drone_id;
			int drone_x;
			int drone_y;
			int emergency;
			int battery;
			cin >> drone_id >> drone_x >> drone_y >> emergency >> battery; cin.ignore();
		}

		cin >> data.drone_scan_count; cin.ignore();

		for (int i = 0; i < data.drone_scan_count; i++)
		{
			int drone_id;
			int creature_id;
			cin >> drone_id >> creature_id; cin.ignore();
		}

		cin >> data.visible_creature_count; cin.ignore();


		int creature_id;

		for (int i = 0; i < data.visible_creature_count; i++)
		{
			cin
				>> creature_id
				>> data.creatures[creature_id].x
				>> data.creatures[creature_id].y
				>> data.creatures[creature_id].vx
				>> data.creatures[creature_id].vy;
			cin.ignore();
		}

		cin >> data.radar_blip_count; cin.ignore();

		for (int i = 0; i < data.radar_blip_count; i++)
		{
			int drone_id;
			int creature_id;
			string radar;
			cin >> drone_id >> creature_id >> radar; cin.ignore();
		}

// show creatues

		for (map<int, s_creature> :: iterator it = data.creatures.begin(); it != data.creatures.end(); it++)
		{
			cerr
				<< it->second.id << " - "
				<< it->second.color << " - "
				<< it->second.type
				<< "   x : " << it->second.x
				<< "   y : " << it->second.y
				<< "   vx : " << it->second.vx
				<< "   vy : " << it->second.vy
				<< std::endl;
		}

		for (int i = 0; i < data.my_drone_count; i++)
		{

			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;

			cout << "WAIT 1" << endl; // MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
		}
	}
}
