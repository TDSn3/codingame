/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/27 20:20:21 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Stock::Stock(void)
{
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Stock::Stock(const Stock &src)
{
	(void) src;
}

/* ************************************************************************** */
/*                                                                            */
/*   DESTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Stock::~Stock(void)
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

bool	left_or_right_lr(u_tuple pos)
{
	if (pos.x < 4999)		// lr l
	{
		if (pos.x < 2499)
			return (true);	// left_l
		else
			return (false);	// right_l
	}
	else					// lr r
	{
		if (pos.x < 7498)
			return (true);	// left_r
		else
			return (false);	// right_r
	}
}

u_tuple	move_to_oposite(u_tuple pos)
{
	if (left_or_right_lr(pos))	// left_l
	{
		return ((u_tuple){{
			pos.x + 1999,
			pos.y
		}});
	}
	else						// right_l
	{
		return ((u_tuple){{
			pos.x - 1999,
			pos.y
		}});			
	}
}

void	Stock::init_list_pos(Data &data)
{	
	// u_tuple	L0_surface;	//	= (u_tuple){{ 2499, 0 }};
	// u_tuple	L1_center;	//	= (u_tuple){{ 2499, 3749 }};
	// u_tuple	L2_center;	//	= (u_tuple){{ 2499, 6249 }};
	// u_tuple	L3_center;	//	= (u_tuple){{ 2499, 8749 }};

	// u_tuple	R0_surface; //	= (u_tuple){{ 7499, 0 }};
	// u_tuple	R1_center;	//	= (u_tuple){{ 7499, 3749 }};
	// u_tuple	R2_center;	//	= (u_tuple){{ 7499, 6249 }};
	// u_tuple	R3_center;	//	= (u_tuple){{ 7499, 8749 }};

	u_tuple	target_zone_0;
	u_tuple	target_zone_1;
	u_tuple	target_zone_2;
	u_tuple	target_zone_3;

	for (size_t i = 0; i < data.drones_player.size(); i++)
	{
		double	new_x = data.drones_player[i]->pos.x;
		
		if (g_round == 0)
		{			
			if (data.drones_player[i]->pos.x > 2000 && data.drones_player[i]->pos.x < 4999)
				new_x = 2000;
			else if (data.drones_player[i]->pos.x > 4999 && data.drones_player[i]->pos.x < 7999)
				new_x = 7999;
			else
				new_x = data.drones_player[i]->pos.x;
		}
		
		target_zone_0 = (u_tuple){{ new_x, 500 }};
		target_zone_1 = (u_tuple){{ new_x, 3500 }};
		target_zone_2 = (u_tuple){{ new_x, 5300 }};
		target_zone_3 = (u_tuple){{ new_x, 7700 }};

		list_pos[i].push_back(target_zone_1);
		list_pos[i].push_back(target_zone_2);
		list_pos[i].push_back(target_zone_3);	// remonte
		list_pos[i].push_back(target_zone_2);
		list_pos[i].back().direction_goal = TOP;
		list_pos[i].push_back(target_zone_1);
		list_pos[i].back().direction_goal = TOP;
		list_pos[i].push_back(target_zone_0);
		list_pos[i].back().direction_goal = TOP;

		list_pos[i].push_back(move_to_oposite(target_zone_1));
		list_pos[i].push_back(move_to_oposite(target_zone_2));
		list_pos[i].push_back(move_to_oposite(target_zone_3));	// remonte
		list_pos[i].push_back(move_to_oposite(target_zone_2));
		list_pos[i].back().direction_goal = TOP;
		list_pos[i].push_back(move_to_oposite(target_zone_1));
		list_pos[i].back().direction_goal = TOP;
		list_pos[i].push_back(move_to_oposite(target_zone_0));
		list_pos[i].back().direction_goal = TOP;
	}
}

void	Stock::update(Data &data)
{	
	for (size_t i = 0; i < data.drones_player.size(); i++)
	{
		// cerr << "stock_update : " << data.drones_player[i]->id << " : " << index_vector_first_visited_false(i) << "  /" << list_pos[i].size() << "" << endl;

		for (size_t j = 0; j < list_pos[i].size(); j++)
		{
			int	new_x = data.drones_player[i]->pos.x;

			if (g_round < 6)
			{			
				if (data.drones_player[i]->pos.x > 2000 && data.drones_player[i]->pos.x < 4999)
					new_x = 2000;
				else if (data.drones_player[i]->pos.x > 4999 && data.drones_player[i]->pos.x < 7999)
					new_x = 7999;
			}

			list_pos[i][j].pos.x = new_x;
		}

		if (g_round < 20 && (data.get_type_scanned(2) > 1 || data.get_type_scanned(i, 2) > 0))
		{
			for (size_t j = 0; j < 4; j++)
				list_pos[i][j].visited = true;
		}

		for (size_t j = 0; j < list_pos[i].size(); j++)
		{
			if (list_pos[i][j].visited == false)
			{
				if (list_pos[i][j].pos.y == 500)
				{
					if (data.drones_player[i]->pos.y <= list_pos[i][j].pos.y)
					{
						cerr << data.drones_player[i]->id << " : valided the checkpoint " << list_pos[i][j].pos.y << endl;
						list_pos[i][j].visited = true;
					}
				}
				else
				{
					if (data.drones_player[i]->pos.y >= list_pos[i][j].pos.y - 300 && data.drones_player[i]->pos.y <= list_pos[i][j].pos.y + 300)
					{
						cerr << data.drones_player[i]->id << " : valided the checkpoint " << list_pos[i][j].pos.y << endl;
						list_pos[i][j].visited = true;
					}
				}

				break ;
			}
		}

		if (index_vector_first_visited_false(i) == -1)
		{
			cerr << "RESET LIST POS" << endl;
			for (size_t j = 0; j < list_pos[i].size(); j++)
				list_pos[i][j].visited = false;
		}
	}
}

int	Stock::index_vector_first_visited_false(int drone)
{
	for (size_t i = 0; i < list_pos[drone].size(); i++)
		if (list_pos[drone][i].visited == false)	
			return (static_cast<int>(i));
	
	return (-1);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
