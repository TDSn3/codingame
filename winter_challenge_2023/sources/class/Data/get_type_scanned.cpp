/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_scanned.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:37:29 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/27 13:43:22 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

int	Data::get_type_scanned(int type)
{
	int		count_creature_scanned = 0;

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
		if (it->second.type == type)
			for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
				if (it2->second.my_scan_no_saved)
					count_creature_scanned++;

	return (count_creature_scanned);
}

int	Data::get_type_scanned(int player_drone_id, int type)
{
	int		count_creature_scanned = 0;

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
		if (it->second.type == type)
			for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
				if (it2->first == drones_player[player_drone_id]->id &&  it2->second.my_scan_no_saved)
					count_creature_scanned++;

	return (count_creature_scanned);
}
