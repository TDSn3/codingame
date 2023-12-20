/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_scaned.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:50:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 09:34:42 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/header.hpp"

bool Data::no_scaned(void)
{
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		for (map<int, s_scan> :: iterator it2 = it->second.scan_no_saved.begin(); it2 != it->second.scan_no_saved.end(); it2++)
		{
			if (it2->second.my_scan_no_saved)
			{
				cerr << "true" << endl;
				return (true);
			}
		}
	}
	cerr << "false" << endl;
	return (false);
}
