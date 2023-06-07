
#ifndef HEADER_HPP
# define HEADER_HPP

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

#include "./class/Vertex.hpp"
#include "./class/Data.hpp"

pair<int, int>	bfs_nearest_gateway(Data &data, int origin, int max_dist);

#endif
