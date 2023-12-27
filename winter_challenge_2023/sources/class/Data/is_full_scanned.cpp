/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_full_scanned.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:33:33 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/27 14:21:14 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   Vérifie si chaque créature d'un certain type a été scannée.			  */
/*   Si une créature n'est pas scannée, return (false).						  */
/*   Si toutes les créatures sont scannées, return (true). 					  */
/*                                                                            */
/* ************************************************************************** */
pair<bool, int>	Data::is_full_scanned(int player_drone_id, int type)
{
	int		count_creature_scanned = 0;
	bool	creature_scanned = false;

	(void)player_drone_id;

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.type == type)
		{
			if (!it->second.radar_signal)
				creature_scanned = true;	// is not creature_scanned but leave the map
			else
			{
				for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
				{
					if (it2->second.my_scan_no_saved)
					{
						count_creature_scanned++;
						creature_scanned = true;	// is scaned but not saved
					}
				}				
			}

			if (creature_scanned == false)
				return (pair<bool, int>(false, count_creature_scanned));
			else
				creature_scanned = false;
		}
	}

	return (pair<bool, int>(true, count_creature_scanned));
}

pair<bool, int>	Data::is_full_scanned(int player_drone_id)
{
	int		count_creature_scanned = 0;
	bool	creature_scanned = false;

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.type == get_drone_player_simple_zone(player_drone_id))
		{
			if (!it->second.radar_signal)
				creature_scanned = true;	// is not creature_scanned but leave the map
			else
			{
				for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
				{
					if (it2->second.my_scan_no_saved)
					{
						count_creature_scanned++;
						creature_scanned = true;	// is scaned but not saved
					}
				}				
			}

			if (creature_scanned == false)
				return (pair<bool, int>(false, count_creature_scanned));
			else
				creature_scanned = false;
		}
	}

	return (pair<bool, int>(true, count_creature_scanned));
}