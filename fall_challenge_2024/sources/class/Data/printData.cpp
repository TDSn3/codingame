#include "../../../includes/header.hpp"

void	Data::printData() {
	cerr << "resources : " << resources << endl;

	cerr << "num_travel_routes : " << num_travel_routes << endl;

	cerr << "travel_routes : " << endl;
	int	i = 1;
	for (map<pair<int, int>, int> :: iterator it = travel_routes.begin(); it != travel_routes.end(); it++)
		cerr << (it->second ? "tube " : "téléporteur ") << i++ << " : " << it->first.first << " - " << it->first.second << "     " << it->second << endl;

	cerr << "num_pods : " << num_pods << endl;

	cerr << "num_new_buildings : " << num_new_buildings << endl;
}
