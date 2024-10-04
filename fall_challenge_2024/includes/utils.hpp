#ifndef UTILS_HPP
# define UTILS_HPP

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
# include <ctgmath>
# include <memory>

using namespace std;

struct s_route {
    int	buildingId1;
    int	buildingId2;
    int	capacity;
    int cost;
};

enum e_building_type
{
    LANDING_PAD,
    LUNAR_MODULE
};

struct s_building {
    e_building_type type;
    int             id;
    int             x;
    int             y;
    int             routeCount;
    int             teleporterCount;
    list<s_route*>  connectedRoute;
};

struct s_landing_pad : s_building {
    int         numAstronauts;
    vector<int>	astronautType;
};

struct s_lunar_module : s_building {
    int moduleType;
};

struct s_pod {
    int         id;
    int     	numStopsCount;
    vector<int>	numStopsList;
};

#endif
