/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/05/31 22:16:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	recursive_priority(Data &stock_data);
void	recursive_print(Data &stock_data);

int main()
{
	Data					stock_data;
	unsigned long long int	i;

	i = 0;
	cerr << "Start main" << endl;	
	start(stock_data);
	while (1)
	{	
		start_2(stock_data);
		cout << "MESSAGE" << " " << "Hello :)" << ";";
		bfs_from_base(stock_data);
		recursive_priority(stock_data);
		recursive_print(stock_data);
		debug(stock_data);
		cerr << "-LOOP " << i <<  " -" << endl;
		i++;
	}
}

t_tuple	find_connect(Data &stock_data, int i_src, int index)
{
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty() && i != i_src)
		{
			for (size_t j = 0; j< stock_data.conexions[i].size(); j++)
			{
				for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
				{
					if (stock_data.conexions[i][j][k] == index)
						return ((t_tuple){i, j , k});
				}
			}
		}
	}
	return ((t_tuple){-1, -1 , -1});
}

int	check_base2(Data& stock_data, int index)
{	
	for (size_t i = 0; i < stock_data.list_base_index.size(); i++)
		if (stock_data.list_base_index[i] == index)
			return (index);
	return (-1);
}

void	recursive_assign(Data &stock_data, size_t i, size_t j, size_t k)
{
	while (k < stock_data.conexions[i][j].size())		
	{
		stock_data.priority_cell[ stock_data.conexions[i][j][k] ]++;
		k++;
	}

	t_tuple stock = find_connect(stock_data, i, stock_data.conexions[i][j].back());
	if (stock.x != -1 && check_base2(stock_data, stock_data.conexions[stock.x][stock.y].back()) == -1)
		recursive_assign(stock_data, stock.x, stock.y, stock.z);
}

void	recursive_priority(Data &stock_data)
{
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			for (size_t j = 0; j< stock_data.conexions[i].size(); j++)
					recursive_assign(stock_data, i, j, 0);
		}
	}
}

void	recursive_print(Data &stock_data)
{
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			cerr << "┌ " << i << endl;
			for (size_t j = 0; j< stock_data.conexions[i].size(); j++)
			{
				cerr << "└ " << j << " : ";
					for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
						cerr << stock_data.conexions[i][j][k] << "(" << stock_data.priority_cell[ stock_data.conexions[i][j][k] ] << ") ";
				cerr << "\n";
			}
			cerr << "\n";
		}
	}
}
