/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stock.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:50:32 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/21 16:36:23 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../../includes/header.hpp"

	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, 0 });

	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 6249 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 6249 }}, 0 });

	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 8749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 8749 }}, 0 });

/* ************************************************************************** */
/*                                                                            */
/*   CONSTRUCTEUR															  */
/*                                                                            */
/* ************************************************************************** */
Stock::Stock(void)
{
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 0 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 6249 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 6249 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 0 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 6249 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 8749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 8749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 6249 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, 0 });
	// list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 0 }}, 0 });
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

void	Stock::init_list_pos(Data &data)
{	
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 6249 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 8749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 6249 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 3749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 2499, 0 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 6249 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 8749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 6249 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 3749 }}, data.my_drone_count ));
	list_pos.push_back(s_pos_node( (u_tuple){{ 7499, 0 }}, data.my_drone_count ));
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
