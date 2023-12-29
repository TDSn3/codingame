/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_scanned.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:16:50 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/29 11:50:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

bool	Data::is_scanned(int drone_id, int creature_id)
{
	for (it_creatures it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.id == creature_id)
		{
			for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
			{
				if (it2->first == drone_id && (it2->second.my_scan_no_saved || it2->second.foe_scan_no_saved))
					return (true);
			}
		}
	}
	return (false);
}
