/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_scaned.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:50:24 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 23:12:50 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/header.hpp"

bool Data::no_scaned(void)
{
	// cerr << "ici" << endl;
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		if (it->second.my_scan_no_saved)
		{
			cerr << "true : " << it->first << endl;
			return (true);
		}
	}
	cerr << "false" << endl;
	return (false);
}
