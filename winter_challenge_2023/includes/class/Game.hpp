/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 12:29:40 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 16:09:11 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "../utils.hpp"
# include "./Data.hpp"

class Game
{
	public:

		Game();
		Game(const unsigned int round, const Data &data);
		Game(const Game &src);
		~Game();

		Game	&operator=(const Game &src);

		unsigned int	get_round(void) const;
		Data			&get_data(void);

	protected:

	private:

		unsigned int	_round;
		Data			_data;

};

#endif
