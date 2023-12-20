/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/20 14:16:59 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

volatile unsigned int	g_round = 0;

// Marquez des points en scannant des poissons précieux plus rapidement que votre adversaire.

int main()
{
	Data	data;

	game_loop(data);
}
