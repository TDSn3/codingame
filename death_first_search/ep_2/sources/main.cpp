
#include "../includes/header.hpp"

using namespace std;

int main()
{
	Data			data;
	int				si;						// The index of the node on which the Bobnet agent is positioned this turn
	pair<int, int>	nearest_edge_gateway;
	Vertex			*v1;
	Vertex			*v2;
	int				v1_index_edges;
	int				v2_index_edges;

	while (1)
	{
		cin >> si; cin.ignore();

		nearest_edge_gateway = bfs_nearest_gateway(data, si, 20);
		v1 = &(data.vertices[ nearest_edge_gateway.first ]);
		v2 = &(data.vertices[  nearest_edge_gateway.second ]);
		v1_index_edges = v1->find_vertex_index_in_edges(nearest_edge_gateway.second);
		v2_index_edges = v2->find_vertex_index_in_edges(nearest_edge_gateway.first);

		cout << nearest_edge_gateway.first << " " << nearest_edge_gateway.second << endl;

		v1->edges[v1_index_edges].first = 0;
		v2->edges[v2_index_edges].first = 0;
	}
}
