/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/26 15:44:04 by tda-silv         ###   ########.fr       */
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
	u_tuple	L0_surface;	//	= (u_tuple){{ 2499, 0 }};
	u_tuple	L1_center;	//	= (u_tuple){{ 2499, 3749 }};
	u_tuple	L2_center;	//	= (u_tuple){{ 2499, 6249 }};
	u_tuple	L3_center;	//	= (u_tuple){{ 2499, 8749 }};

	u_tuple	R0_surface; //	= (u_tuple){{ 7499, 0 }};
	u_tuple	R1_center;	//	= (u_tuple){{ 7499, 3749 }};
	u_tuple	R2_center;	//	= (u_tuple){{ 7499, 6249 }};
	u_tuple	R3_center;	//	= (u_tuple){{ 7499, 8749 }};

	for (size_t i = 0; i < data.drones_player.size(); i++)
	{
		L0_surface = (u_tuple){{ data.drones_player[i]->pos.x, 500 }};
		L1_center = (u_tuple){{ data.drones_player[i]->pos.x, 3749 }};
		L2_center = (u_tuple){{ data.drones_player[i]->pos.x, 6249 }};
		L3_center = (u_tuple){{ data.drones_player[i]->pos.x, 8749 }};

		R0_surface = (u_tuple){{ data.drones_player[i]->pos.x, 500 }};
		R1_center = (u_tuple){{ data.drones_player[i]->pos.x, 3749 }};
		R2_center = (u_tuple){{ data.drones_player[i]->pos.x, 6249 }};
		R3_center = (u_tuple){{ data.drones_player[i]->pos.x, 8749 }};

		if (data.drones_player[i]->pos.x < 4999)	// left
		{
			list_pos[i].push_back(L1_center);
			list_pos[i].push_back(L2_center);
			list_pos[i].push_back(L3_center);	// remonte
			list_pos[i].push_back(L2_center);
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(L1_center);
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(L0_surface);
			list_pos[i].back().direction_goal = TOP;

			list_pos[i].push_back(move_to_oposite(L1_center));
			list_pos[i].push_back(move_to_oposite(L2_center));
			list_pos[i].push_back(move_to_oposite(L3_center));	// remonte
			list_pos[i].push_back(move_to_oposite(L2_center));
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(move_to_oposite(L1_center));
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(move_to_oposite(L0_surface));
			list_pos[i].back().direction_goal = TOP;
		}
		else	// right
		{
			list_pos[i].push_back(R1_center);
			list_pos[i].push_back(R2_center);
			list_pos[i].push_back(R3_center);	// remonte
			list_pos[i].push_back(R2_center);
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(R1_center);
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(R0_surface);
			list_pos[i].back().direction_goal = TOP;

			list_pos[i].push_back(move_to_oposite(R1_center));
			list_pos[i].push_back(move_to_oposite(R2_center));
			list_pos[i].push_back(move_to_oposite(R3_center));	// remonte
			list_pos[i].push_back(move_to_oposite(R2_center));
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(move_to_oposite(R1_center));
			list_pos[i].back().direction_goal = TOP;
			list_pos[i].push_back(move_to_oposite(R0_surface));
			list_pos[i].back().direction_goal = TOP;		
		}
	}
}

void	Stock::update(Data &data)
{	
	for (size_t i = 0; i < data.drones_player.size(); i++)
	{
		cerr << "stock_update : " << data.drones_player[i]->id << " : " << index_vector_first_visited_false(i) << "  /" << list_pos[i].size() << "" << endl;

		for (size_t j = 0; j < list_pos[i].size(); j++)
		{
			if (list_pos[i][j].visited == false)
			{
				if (list_pos[i][j].pos.y == 500 && data.drones_player[i]->pos.y <= list_pos[i][j].pos.y)
				{
					cerr << data.drones_player[i]->id << " : valided the checkpoint " << list_pos[i][j].pos.y << endl;
					list_pos[i][j].visited = true;
				}
				else if (data.drones_player[i]->pos.y >= list_pos[i][j].pos.y - 300 && data.drones_player[i]->pos.y <= list_pos[i][j].pos.y + 300)
				{
					cerr << data.drones_player[i]->id << ": valided the checkpoint " << list_pos[i][j].pos.y << endl;
					list_pos[i][j].visited = true;
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
