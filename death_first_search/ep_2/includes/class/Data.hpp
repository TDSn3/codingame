
#ifndef DATA_HPP
# define DATA_HPP

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

#include "Vertex.hpp"

class Data
{
	public:

	Data(void);
	Data(const Data &src);
	~Data(void);

	int				n;				// the total number of nodes in the level, including the gateways
	int				l;				// the number of links
	int				e;				// the number of exit gateways
	vector<Vertex>	vertices;
	vector<Vertex>	gateways_index;

	protected:

	private:

};

#endif
