#include "../../../includes/header.hpp"

void	Data::update() {
    cin >> resources; cin.ignore();

    cin >> num_travel_routes; cin.ignore();
    for (int i = 0; i < num_travel_routes; i++) {
    	int buildingId1;
    	int buildingId2;
    	int capacity;

        cin >> buildingId1 >> buildingId2 >> capacity; cin.ignore();
        travel_routes[make_pair(buildingId1, buildingId2)] = capacity;
    }

    cin >> num_pods; cin.ignore();
    for (int i = 0; i < num_pods; i++) {
        string  pod_properties;

        getline(cin, pod_properties);
    }

    cin >> num_new_buildings; cin.ignore();
    for (int i = 0; i < num_new_buildings; i++) {
        string  building_properties;

        getline(cin, building_properties);
    }
}
