/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/19 09:17:51 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::Data(void)
{
	s_creature	creature = {};

	cin >> creature_count; cin.ignore();

	for (int i = 0; i < creature_count; i++)
	{
		cin >> creature.id >> creature.color >> creature.type; cin.ignore();
		creatures[creature.id] = creature;
	}
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Data::~Data(void)
{
}

/* ************************************************************************** */
/*                                                                            */
/*   OPÉRATEUR																  */
/*                                                                            */
/* ************************************************************************** */

/*   OPÉRATEUR INTERNE   **************************************************** */

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	Data::show_creatures(void)
{
	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		cerr
			<< it->second.id << " : "
			<< "   color : " << it->second.color
			<< "   type : " << it->second.type
			//<< "   x : " << it->second.x
			//<< "   y : " << it->second.y
			//<< "   vx : " << it->second.vx
			//<< "   vy : " << it->second.vy
			<< "   my_scan : " << it->second.my_scan
			<< "   foe_scan : " << it->second.foe_scan
			<< "   dist : " << distance(0, it->second.id)
			<< std::endl;
	}
}

void	Data::update(void)
{
	int 	creature_id;
	int		drone_id;
	string	radar;

	cin >> my_score; cin.ignore();
	cin >> foe_score; cin.ignore();

/* ************************************************************************** */
/*                                                                            */
/*   Créature scaned														  */
/*                                                                            */
/* ************************************************************************** */

	cin >> my_scan_count; cin.ignore();

	for (int i = 0; i < my_scan_count; i++)
	{
		cin >> creature_id; cin.ignore();
		creatures[creature_id].my_scan = true;
	}

	cin >> foe_scan_count; cin.ignore();

	for (int i = 0; i < foe_scan_count; i++)
	{
		cin >> creature_id; cin.ignore();
		creatures[creature_id].foe_scan = true;
	}

/* ************************************************************************** */
/*                                                                            */
/*   Drone																	  */
/*                                                                            */
/* ************************************************************************** */

	cin >> my_drone_count; cin.ignore();

	for (int i = 0; i < my_drone_count; i++)
	{
		cin
			>> drone_id
			>> my_drone[drone_id].x
			>> my_drone[drone_id].y
			>> my_drone[drone_id].emergency
			>> my_drone[drone_id].battery;
		cin.ignore();
		my_drone[drone_id].id = drone_id;
	}

	cin >> foe_drone_count; cin.ignore();

	for (int i = 0; i < foe_drone_count; i++)
	{
		cin
			>> drone_id
			>> foe_drone[drone_id].x
			>> foe_drone[drone_id].y
			>> foe_drone[drone_id].emergency
			>> foe_drone[drone_id].battery;
		cin.ignore();
		foe_drone[drone_id].id = drone_id;
	}

/* ************************************************************************** */

	cin >> drone_scan_count; cin.ignore();

	for (int i = 0; i < drone_scan_count; i++)
	{
		cin >> drone_id >> creature_id; cin.ignore();
	}

/* ************************************************************************** */

	cin >> visible_creature_count; cin.ignore();

	for (int i = 0; i < visible_creature_count; i++)
	{
		cin
			>> creature_id
			>> creatures[creature_id].x
			>> creatures[creature_id].y
			>> creatures[creature_id].vx
			>> creatures[creature_id].vy;
		cin.ignore();
		creatures[creature_id].id = creature_id;
	}

	cin >> radar_blip_count; cin.ignore();

	for (int i = 0; i < radar_blip_count; i++)
	{
		cin >> drone_id >> creature_id >> radar; cin.ignore();
	}

/* ************************************************************************** */

	for (map<int, s_creature> :: iterator it = creatures.begin(); it != creatures.end(); it++)
	{
		for (map<int, s_drone> :: iterator it2 = my_drone.begin(); it2 != my_drone.end(); it2++)
		{
			it->second.distance_my_drone[it2->first] = distance(it2->first, it->first);
		}
	}

}

/*   MÉTHODE PRIVATE   ****************************************************** */


/* ************************************************************************** */
