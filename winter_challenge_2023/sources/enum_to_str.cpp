/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum_to_str.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:32:13 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/25 15:16:36 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

string	enum_to_str(e_zone token)
{
	if (token == L0)
		return ("L0");
	else if (token == R0)
		return ("R0");
	else if (token == L1)
		return ("L1");
	else if (token == R1)
		return ("R1");
	else if (token == L2)
		return ("L2");
	else if (token == R2)
		return ("R2");
	else if (token == L3)
		return ("L3");
	else	// (token == R3)
		return ("R3");
}

string	enum_to_str(e_radar token)
{
	if (token == TL)
		return ("TL");
	else if (token == TR)
		return ("TR");
	else if (token == BL)
		return ("BL");
	else	// (token == BR)
		return ("BR");

}
