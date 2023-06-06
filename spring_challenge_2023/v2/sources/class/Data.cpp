/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:58:53 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/05 02:50:51 by tda-silv         ###   ########.fr       */
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
	this->number_of_cells = 0;
	this->my_score = 0;
	this->opp_score = 0;

	this->total_ant = 0;
	this->my_ant = 0;
	this->opp_ant = 0;

	this->total_res_cryst_start = 0;
	this->total_cell_cryst_start = 0;
	this->total_res_cryst_now = 0;
	this->total_cell_cryst_now = 0;
	this->my_cell_res_cryst_now = 0;
	this->opp_cell_res_cryst_now = 0;

	this->total_res_egg_start = 0;
	this->total_cell_egg_start = 0;
	this->total_res_egg_now = 0;
	this->total_cell_egg_now = 0;
	this->my_cell_res_egg_now = 0;
	this->opp_cell_res_egg_now = 0;

	this->beacon = 0;
	this->beacon_on_res = 0;

	this->signal_res = 0;

	this->data_prev = NULL;
}

/*   COPY CONSTRUCTEUR   **************************************************** */

Data::Data(const Data &src)
{
	this->number_of_cells = src.number_of_cells;

	for (int i = 0; i < src.number_of_cells; i++)
	{
		for (int j = 0; j < 17; j++)
			this->data_of_cells[i].push_back( const_cast<Data &>(src).data_of_cells[i][j] );
		this->conexions.push_back(vector<vector<int> >());
	}

	for (size_t i = 0; i < my_score_history.size(); i++)
	{
		this->my_score_history.push_back( src.my_score_history[i] );
		this->opp_score_history.push_back( src.opp_score_history[i] );
	}

	for (size_t i = 0; i < src.list_my_base_index.size(); i++)
	{
		this->list_my_base_index.push_back( src.list_my_base_index[i] );
		this->list_opp_base_index.push_back( src.list_opp_base_index[i] );
	}

	for (int i = 0; i < src.number_of_cells; i++)
	{
		this->dist_from_my_base.push_back(std::vector<int>());
		this->dist_from_opp_base.push_back(std::vector<int>());
	}

	for (size_t i = 0; i < src.list_my_base_index.size(); i++)
	{
		for (int j = 0; j < src.number_of_cells; j++)
		{
			this->dist_from_my_base[ this->list_my_base_index[i] ].push_back( src.dist_from_my_base[ src.list_my_base_index[i] ][j] );
			this->dist_from_opp_base[ this->list_opp_base_index[i] ].push_back( src.dist_from_opp_base[ src.list_opp_base_index[i] ][j] );
		}
		this->data_of_cells[ this->list_my_base_index[i] ][13] = this->list_my_base_index[i];
	}

	this->my_score = src.my_score;
	this->opp_score = src.opp_score;

	this->total_ant = src.total_ant;
	this->my_ant = src.my_ant;
	this->opp_ant = src.opp_ant;

	this->total_res_cryst_start = src.total_res_cryst_start;
	this->total_cell_cryst_start = src.total_cell_cryst_start;
	this->total_res_cryst_now = src.total_res_cryst_now;
	this->total_cell_cryst_now = src.total_cell_cryst_now;
	this->my_cell_res_cryst_now = src.my_cell_res_cryst_now;
	this->opp_cell_res_cryst_now = src.opp_cell_res_cryst_now;

	this->total_res_egg_start = src.total_res_egg_start;
	this->total_cell_egg_start = src.total_cell_egg_start;
	this->total_res_egg_now = src.total_res_egg_now;
	this->total_cell_egg_now = src.total_cell_egg_now;
	this->my_cell_res_egg_now = src.my_cell_res_egg_now;
	this->opp_cell_res_egg_now = src.opp_cell_res_egg_now;

	this->beacon = src.beacon;
	this->beacon_on_res = src.beacon_on_res;

	this->signal_res = src.signal_res;

	this->data_prev = src.data_prev;
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

Data	&Data::operator = (const Data &right)
{
	this->number_of_cells = right.number_of_cells;

	for (int i = 0; i < right.number_of_cells; i++)
	{
		for (int j = 0; j < 17; j++)
			this->data_of_cells[i][j] = const_cast<Data &>(right).data_of_cells[i][j];

		if (!this->conexions[i].empty())
		{
			for (size_t j = 0; j < this->conexions[i].size(); j++)
			{
				this->conexions[i].push_back(std::vector<int>());
				for (size_t k = 0; k < this->conexions[i][j].size(); k++)
					this->conexions[i].back(). push_back( right.conexions[i][j][k] );
			}
		}
	}

	for (size_t i = 0; i < my_score_history.size(); i++)
	{
		this->my_score_history[i] = right.my_score_history[i];
		this->opp_score_history[i] = right.opp_score_history[i];
	}

	for (size_t i = 0; i < right.list_my_base_index.size(); i++)
	{
		this->list_my_base_index[i] = right.list_my_base_index[i];
		this->list_opp_base_index[i] = right.list_opp_base_index[i];
	}

	for (size_t i = 0; i < right.list_my_base_index.size(); i++)
	{
		for (int j = 0; j < right.number_of_cells; j++)
		{
			this->dist_from_my_base[ this->list_my_base_index[i] ][j] = right.dist_from_my_base[ right.list_my_base_index[i] ][j];
			this->dist_from_opp_base[ this->list_opp_base_index[i] ][j] = right.dist_from_opp_base[ right.list_opp_base_index[i] ][j];
		}
		this->data_of_cells[ this->list_my_base_index[i] ][13] = this->list_my_base_index[i];
	}

	this->my_score = right.my_score;
	this->opp_score = right.opp_score;

	this->total_ant = right.total_ant;
	this->my_ant = right.my_ant;
	this->opp_ant = right.opp_ant;

	this->total_res_cryst_start = right.total_res_cryst_start;
	this->total_cell_cryst_start = right.total_cell_cryst_start;
	this->total_res_cryst_now = right.total_res_cryst_now;
	this->total_cell_cryst_now = right.total_cell_cryst_now;
	this->my_cell_res_cryst_now = right.my_cell_res_cryst_now;
	this->opp_cell_res_cryst_now = right.opp_cell_res_cryst_now;

	this->total_res_egg_start = right.total_res_egg_start;
	this->total_cell_egg_start = right.total_cell_egg_start;
	this->total_res_egg_now = right.total_res_egg_now;
	this->total_cell_egg_now = right.total_cell_egg_now;
	this->my_cell_res_egg_now = right.my_cell_res_egg_now;
	this->opp_cell_res_egg_now = right.opp_cell_res_egg_now;

	this->beacon = right.beacon;
	this->beacon_on_res = right.beacon_on_res;

	this->signal_res = right.signal_res;

	this->data_prev = right.data_prev;

	return (*this);
}

/*   OPÉRATEUR EXTERNE   **************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   MÉTHODE																  */
/*                                                                            */
/* ************************************************************************** */

/*   MÉTHODE PUBLIC   ******************************************************* */

void	Data::assign_beacon(int index, int power)
{
	if (this->data_of_cells[index][POWER] > power)
		power = this->data_of_cells[index][POWER];
	this->data_of_cells[index][POWER] = power;

	if (this->data_of_cells[index][BEACON_THIS_LOOP] == -1)
		this->beacon++;
	this->data_of_cells[index][BEACON_THIS_LOOP] = 1;

//	cout << "BEACON" << " " << index << " " << power << ";";
}

int		Data::give_total_beacon_power(void)
{
	int	ret;

	ret = 0;
	for (int i = 0; i < this->number_of_cells; i++)
		if (this->data_of_cells[i][BEACON_THIS_LOOP] > 0)
			ret += this->data_of_cells[i][POWER];
	return (ret);
}

int		Data::give_total_cell_my_ant(void)
{
	int	ret;

	ret = 0;
	for (int i = 0; i < this->number_of_cells; i++)
		if (this->data_of_cells[i][MY_ANTS] > 0)
			ret ++;
	return (ret);
}

int		Data::check_opp_base(int index)
{
	for (size_t i = 0; i < this->list_opp_base_index.size(); i++)
		if (this->list_opp_base_index[i] == index)
			return (index);
	return (-1);
}

int		Data::check_base(int index)
{	
	for (size_t i = 0; i < this->list_my_base_index.size(); i++)
		if (this->list_my_base_index[i] == index)
			return (index);
	return (-1);
}

int		Data::give_dist_from_opp_base(int index)
{
	int	size_dist_from_opp_base = 1000;

	for (size_t i = 0; i < this->list_opp_base_index.size(); i++)
	{
		if (this->dist_from_opp_base[ this->list_opp_base_index[i] ][index] < size_dist_from_opp_base)
			size_dist_from_opp_base = this->dist_from_opp_base[ this->list_opp_base_index[i] ][index];
	}
	return (size_dist_from_opp_base);
}

int		Data::give_dist_from_base(int index)
{
	int	size_dist_from_my_base = 1000;

	for (size_t i = 0; i < this->list_my_base_index.size(); i++)
	{
		if (this->dist_from_my_base[ this->list_my_base_index[i] ][index] < size_dist_from_my_base)
			size_dist_from_my_base = this->dist_from_my_base[ this->list_my_base_index[i] ][index];
	}
	return (size_dist_from_my_base);
}

double	Data::ratio_dist(int index)
{
	double	base_dist;
	double	dist_total;
	double	ratio;

	base_dist = (double) this->give_dist_from_base(index);
	dist_total = base_dist + this->give_dist_from_opp_base(index);
	ratio = dist_total / base_dist;
	return (ratio);
}

double	Data::ratio_dist_from_zero(int index)
{
	double	base_dist;
	double	dist_total;
	double	ratio;

	base_dist = (double) this->give_dist_from_base(index);
	dist_total = base_dist + index;
	ratio = dist_total / base_dist;
	return (ratio);
}

double	Data::ratio_opp_dist(int index)
{
	double	base_dist;
	double	dist_total;
	double	ratio;

	base_dist = (double) this->give_dist_from_opp_base(index);
	dist_total = base_dist + this->give_dist_from_base(index);
	ratio = dist_total / base_dist;
	return (ratio);
}

int		Data::calculate_number_ant_desired(int index)
{
	double	ret;

	if (this->give_total_beacon_power() > 0)
		ret = (double)this->data_of_cells[index][POWER] / (double)this->give_total_beacon_power() * (double)this->my_ant;
	else
		ret = 0;
	return (ret);
}

int		Data::all_other_number_ant_desired(int index_exclude)
{
	double	ret;
	int		desired_ant;

	ret = 0;
	for (int i = 0; i < this->number_of_cells; i++)
	{
		if (this->data_of_cells[i][BEACON_THIS_LOOP] == 1 && i != index_exclude)
		{
			desired_ant = this->calculate_number_ant_desired(i);
			if (this->data_of_cells[i][MY_ANTS] < desired_ant)
			{
				if (this->data_of_cells[i][MY_ANTS] == -1)
					this->data_of_cells[i][MY_ANTS] = 0;
				ret += std::abs(this->data_of_cells[i][MY_ANTS] - desired_ant);
			}
		}
	}
	return (ret);
}

void	Data::move_ant_to_resource(int index_res)
{
	std::vector<int>	path;
	int					index_ant;
	int					desired_ant;
	int					all_n_ant_desired;

	cerr << "+-----------+\n";

	desired_ant = this->calculate_number_ant_desired(index_res);

	cerr << "index_res : " << index_res << " | power :" << this->data_of_cells[index_res][POWER] << " | desired : " << desired_ant << endl;

	path = find_next_ant(*this, index_res, 30);
	index_ant = path.front();
	
	cerr << "index_ant : " << index_ant << " | power :" << this->data_of_cells[index_ant][POWER] << " | desired : " << this->calculate_number_ant_desired(index_ant) << endl;

	all_n_ant_desired = all_other_number_ant_desired(-1);

	cerr << "n1 ------ " << this->data_of_cells[index_ant][MY_ANTS] - calculate_number_ant_desired(index_ant) << endl;
	cerr << "n2 ------ " << all_n_ant_desired << endl;
	cerr << "n3 ------ " << desired_ant << endl;

	for (int i = 0; i < this->number_of_cells; i++)
	{
		if (this->data_of_cells[i][MY_ANTS] > 0)
		{
			for (int j = 0; j < this->number_of_cells; j++)
			{
				if (this->data_of_cells[i][BEACON_THIS_LOOP] == 1
					&& this->data_of_cells[i][MY_ANTS] < this->calculate_number_ant_desired(i))
				{
					
				}
			}
		}
	}


	//cerr <<  "all n ant desired : " << all_other_number_ant_desired(-1) << endl;



//	total_cell_my_ant = this->give_total_cell_my_ant();
//	for (int i = 0; i < total_cell_my_ant; i++)
//	{
//		path_next_ant = find_next_ant(*this, index_res, 30);
//
//		index_ant = path_next_ant.front();
//
//		desired_ant = this->calculate_number_ant_desired(index_ant);
//
//		if (this->data_of_cells[ path_next_ant.front() ][MY_ANTS] > this->data_of_cells[ path_next_ant.front() ][desired_ant])
//		{	
//			cerr << "index_ant : " << index_ant << endl;
//
//			cerr << "index_ant MY_ANTS : " << this->data_of_cells[index_ant][MY_ANTS] << endl;
//
//			cerr << "index desired : " << index_res << endl;
//
//			cerr << "desired_ant : " << desired_ant << " power :" << this->data_of_cells[desired_ant][POWER] << endl;
//
//			cerr << "total desired : " << this->all_other_number_ant_desired(index_res)<< endl;
//
//			cerr << "total desired without desired_ant : " << this->all_other_number_ant_desired(desired_ant) << endl;
//
//			int	ant_mooved = this->data_of_cells[index_ant][MY_ANTS] - this->data_of_cells[index_ant][desired_ant];

//			cerr << "minus : " << ant_mooved << endl;
//			cerr << "to : " << path_next_ant[1] << endl;
//		}
//	}	
	cerr << "+-----------+\n";
}

/*   MÉTHODE PRIVATE   ****************************************************** */

/* ************************************************************************** */
