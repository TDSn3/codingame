/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/01 15:20:45 by tda-silv         ###   ########.fr       */
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
	this->my_base_index = 0;
	this->number_of_cells = 0;
	this->total_ants = 0;
	this->total_opp_ants = 0;
	this->max_dist = 0;
	this->beacon = 0;
	this->total_power_beacon = 0;
	this->egg_and_cryst = 0;
	this->power_egg = 2;
	this->limit_egg = 2;
	this->number_egg_cell_start = 0;
	this->egg_cell_now = 0;
	this->signal_for_crystal = 0;
}

Data::Data(int my_base_index, int number_of_cells)
{
	this->my_base_index = my_base_index;
	this->number_of_cells = number_of_cells;
	this->total_ants = 0;
	this->max_dist = 0;
	for (int i = 0; i < number_of_cells; i++)
		for (int j = 0; j < 13; j++)
			this->data_of_cells[i].push_back(-1);
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	(void)src;
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

int	Data::check_opp_base(Data &stock_data, int index)
{
	for (size_t i = 0; i < stock_data.list_opp_base_index.size(); i++)
		if (stock_data.list_opp_base_index[i] == index)
			return (1);
	return (0);
}

int	Data::give_dist_from_opp_base(int index)
{
	int	size_dist_from_opp_base = 1000;

	for (size_t i = 0; i < this->list_opp_base_index.size(); i++)
	{
		if (this->dist_from_opp_base[ this->list_opp_base_index[i] ][index] < size_dist_from_opp_base)
			size_dist_from_opp_base = this->dist_from_opp_base[ this->list_opp_base_index[i] ][index];
	}
	return (size_dist_from_opp_base);
}

int	Data::give_dist_from_base(int index)
{
	int	size_dist_from_base = 1000;

	for (size_t i = 0; i < this->list_base_index.size(); i++)
	{
		if (this->dist_from_base[ this->list_base_index[i] ][index] < size_dist_from_base)
			size_dist_from_base = this->dist_from_base[ this->list_base_index[i] ][index];
	}
	return (size_dist_from_base);
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
