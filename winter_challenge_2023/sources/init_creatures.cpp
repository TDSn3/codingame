/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_creatures.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:44:18 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/18 18:00:06 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	init_creatures(Data &data)
{
	s_creature	creature;

	cin >> data.creature_count; cin.ignore();

	for (int i = 0; i < data.creature_count; i++)
	{
		cin >> creature.id >> creature.color >> creature.type; cin.ignore();
		data.creatures[creature.id] = creature;
	}

	//for (map<int, s_creature> :: iterator it = data.creatures.begin(); it != data.creatures.end(); it++)
	//{
	//	cerr << it->second.id << " - " << it->second.color << " - " << it->second.type << std::endl;
	//}
}
