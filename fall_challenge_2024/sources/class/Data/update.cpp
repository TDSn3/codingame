#include "../../../includes/header.hpp"

void	Data::update() {
    cin >> resources; cin.ignore();

    cin >> num_travel_routes; cin.ignore();
    for (int i = 0; i < num_travel_routes; i++) {
        s_tube tube;

        cin >> tube.buildingId1 >> tube.buildingId2 >> tube.capacity; cin.ignore();

    	float	distance = calculateDistance(tube.buildingId1, tube.buildingId2);

    	if (distance == -1)
    		return ;

        tube.cost = static_cast<int>(floor(distance * 10));

        travel_routes[make_pair(tube.buildingId1, tube.buildingId2)] = tube;
    }

    cin >> num_pods; cin.ignore();
    for (int i = 0; i < num_pods; i++) {
        string  pod_properties;

        getline(cin, pod_properties);
    }

    cin >> num_new_buildings; cin.ignore();
    for (int i = 0; i < num_new_buildings; i++) {
        string              building_properties;

        getline(cin, building_properties);

        istringstream       iss(building_properties);
        vector<int>         properties;
        int                 value;

        while (iss >> value)
            properties.push_back(value);

        if (properties[0] == 0) {
            s_landing_pad*   landing_pad = new s_landing_pad();;

            landing_pad->type = LANDING_PAD;
            landing_pad->id = properties[1];
            landing_pad->x = properties[2];
            landing_pad->y = properties[3];
            landing_pad->numAstronauts = properties[4];
            
            for (size_t j = 5; j < properties.size(); j++)
                landing_pad->astronautType.push_back(properties[j]);
            buildings[landing_pad->id] = landing_pad;
        } else {
            s_lunar_module*  lunar_module = new s_lunar_module();

            lunar_module->type = LUNAR_MODULE;
            lunar_module->id = properties[1];
            lunar_module->x = properties[2];
            lunar_module->y = properties[3];
            lunar_module->moduleType = properties[0];

            buildings[lunar_module->id] = lunar_module;
        }
    }
}
