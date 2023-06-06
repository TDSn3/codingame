/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:46:21 by tda-silv          #+#    #+#             */
/*   Updated: 2023/06/06 22:09:53 by tda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.hpp"

using namespace std;

int main()
{
	int		n;							// the total number of nodes in the level, including the gateways
	int		l;							// the number of links
	int		e;							// the number of exit gateways

	int		n1;							// N1 and N2 defines a link between these nodes
	int		n2;

	int		ei;							// the index of a gateway node

	int		si;							// The index of the node on which the Bobnet agent is positioned this turn

	Data	data;

	cin >> n >> l >> e; cin.ignore();

	for (int i = 0; i < n; i++)
		data.vertices.push_back(Vertex(i));

	for (int i = 0; i < l; i++)
	{
		cin >> n1 >> n2; cin.ignore();
		data.vertices[n1].edges.push_back(pair<int, Vertex*>(1, &data.vertices[n2]));
		data.vertices[n2].edges.push_back(pair<int, Vertex*>(1, &data.vertices[n1]));
	}
	for (int i = 0; i < e; i++)
	{
		cin >> ei; cin.ignore();
		data.vertices[ei].gateway = 1;
		data.gateways_index.push_back(ei);
	}

	while (1)
	{
		cin >> si; cin.ignore();

		for (size_t i = 0; i < data.vertices.size(); i++)
		{
			cerr << "[" << i << "], gateway : " << data.vertices[i].gateway << endl;
			for (size_t j = 0; j < data.vertices[i].edges.size(); j++)
				cerr << data.vertices[i].edges[j].second->index << " ("<< data.vertices[i].edges[j].first << ") " << endl;
		}

		pair<int, int>	nearest_edge_gateway = bfs_nearest_gateway(data, si, 5);
		Vertex			*v1;
		Vertex			*v2;

		v1 = &(data.vertices[ nearest_edge_gateway.first ]);
		v2 = &(data.vertices[  nearest_edge_gateway.second ]);
		cout << nearest_edge_gateway.first << " " << nearest_edge_gateway.second << endl;

		data.vertices[ nearest_edge_gateway.first ].edges[ v1->find_vertex_index_in_edges(nearest_edge_gateway.first) ].first = 0;
		data.vertices[ nearest_edge_gateway.second ].edges[ v2->find_vertex_index_in_edges(nearest_edge_gateway.second) ].first = 0;
	}
}
