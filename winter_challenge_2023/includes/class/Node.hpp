/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 12:07:36 by tda-silv          #+#    #+#             */
/*   Updated: 2023/12/31 14:25:26 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "../utils.hpp"

class Node
{
	public:

		virtual ~Node(void) = 0;

		Node						*parent;
		vector<unique_ptr<Node> >	children;

	protected:

	private:

		Node();
		Node(const Node &src);

		Node	&operator = (const Node &src);
};

#endif
