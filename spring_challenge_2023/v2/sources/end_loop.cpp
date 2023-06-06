/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_loop.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:46:03 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/04 14:33:57 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

void	print_cerr(Data &stock_data);

void	end_loop(Data &stock_data)
{
	stock_data.my_score_history.push_back( stock_data.my_score );
	stock_data.opp_score_history.push_back( stock_data.opp_score );

	print_cerr(stock_data);

	cout << "WAIT;" << endl;
}

void	print_cerr(Data &stock_data)
{
	cout << "MESSAGE" << " " 
	<< "c(" << stock_data.total_cell_cryst_start << ")"
	<< "[" << stock_data.total_res_cryst_start << "]"
	<< " " << stock_data.total_cell_cryst_now
	<< " " << stock_data.total_res_cryst_now << "  |  "
	<< "e(" << stock_data.total_cell_egg_start << ")"
	<< "[" << stock_data.total_res_egg_start << "]"
	<< " " << stock_data.total_cell_egg_now
	<< " " << stock_data.total_res_egg_now
	<< ";";

	if (stock_data.total_res_egg_now != 0)
		cerr << "│ " << std::setw(15) << "ratio cryst/egg : " << stock_data.total_res_cryst_start / stock_data.total_res_egg_now << "\n";
	else
		cerr << "│ " << std::setw(15) << "ratio cryst/egg : 0\n";

	cerr << "\nconexion :\n";
	for (size_t i = 0; i < stock_data.conexions.size(); i++)
	{
		if (!stock_data.conexions[i].empty())
		{
			cerr << "┌ " << i << endl;
			for (size_t j = 0; j < stock_data.conexions[i].size(); j++)
			{
				cerr << "└ " << j << " : ";
				for (size_t k = 0; k < stock_data.conexions[i][j].size(); k++)
					cerr << stock_data.conexions[i][j][k] << " ";
				cerr << "\n";
			}
			cerr << "\n";
		}
	}
	cerr << endl;

}