
#ifndef VERTEX_HPP
# define VERTEX_HPP

# include <iomanip>
# include <list>
# include <stdio.h>
# include <stdlib.h>
# include <iostream>
# include <string>
# include <vector>
# include <map>
# include <algorithm>
# include <queue>
# include <cmath>
# include <array>
# include <memory>

using namespace std;

class Vertex
{
	public:

	Vertex(void);
	Vertex(int vertex_index);
	Vertex(const Vertex &src);
	~Vertex(void);

	const int					index;
	vector<pair<int, Vertex*> >	edges;		// int for edge statue : 1 = active, 0 = cut
	int							gateway;

	int							find_vertex_index_in_edges(int index);

	protected:

	private:

};

#endif
