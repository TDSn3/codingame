#include "../../../includes/header.hpp"

void	Data::printData() {
    cerr << "resources : " << resources << endl;

    cerr << "num_travel_routes : " << num_travel_routes << endl;

    cerr << "travel_routes : " << endl;
    int	i = 1;
    for (map<pair<int, int>, s_tube> :: iterator it = travel_routes.begin(); it != travel_routes.end(); it++)
        cerr << "|   " << (it->second.capacity ? "tube " : "téléporteur ") << i++ << " ( " << it->first.first << " - " << it->first.second << " )     " << it->second.capacity << endl;

    cerr << "num_pods : " << num_pods << endl;

    cerr << "num_new_buildings : " << num_new_buildings << endl;

    cerr << "buildings : " << endl;
    for (const auto &building : buildings) {
        cerr << "|   ";
        cerr << "id : " << building.second->id << "     ";
        cerr << "type : " << (building.second->type == LANDING_PAD ? "landing_pad" : "lunar_module") << "     ";
        cerr << "xy : (" << building.second->x << ", " << building.second->y << ")" << endl;

        cerr << "|   ";
        if (building.second->type == LANDING_PAD) {
            const s_landing_pad &landing_pad = static_cast<const s_landing_pad&>(*(building.second));

            cerr << "numAstronauts : " << landing_pad.numAstronauts << ", astronautType : ";
            for (const int &astronautType : landing_pad.astronautType)
                cerr << astronautType << " ";
        } else {
            const s_lunar_module &lunar_module = static_cast<const s_lunar_module&>(*(building.second));

            cerr << "moduleType : " << lunar_module.moduleType;
        }
        
        cerr << "\n" << endl;
    }
}
