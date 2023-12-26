/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limite_zone.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 17:47:52 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/26 11:50:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

pair<int, int>	Data::get_limite_zone(s_creature creature)
{
	if (creature.type == 0)
		return (pair<int, int>( 2500, 4999 ));	//	zone 1 : y(2500) - y(4999)
	else if (creature.type == 1)
		return (pair<int, int>( 5000, 7499 ));	//	zone 2 : y(5000) - y(7499)
	else	// creature.type == 2
		return (pair<int, int>( 7500, 9999 ));	//	zone 3 : y(7500) - y(9999)
}
