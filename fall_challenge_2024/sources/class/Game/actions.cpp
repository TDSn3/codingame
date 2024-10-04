#include "../../../includes/header.hpp"

void	Game::tube(int buildingId1, int buildingId2) {
    float	distance = data.calculateDistance(buildingId1, buildingId2);

    if (distance == -1)
        return ;

    if (data.travel_routes.find({buildingId1, buildingId2}) != data.travel_routes.end()) {
        cerr << "ERROR TUBE : Tube already exists between " << buildingId1 << " and " << buildingId2 << endl;
        return ;
    }

    int		cost = static_cast<int>(floor(distance * 10));

    if (data.resources >= cost) {
        data.resources -= cost;
        data.num_travel_routes++;
        data.travel_routes[{buildingId1, buildingId2}].buildingId1 = buildingId1;
        data.travel_routes[{buildingId1, buildingId2}].buildingId2 = buildingId2;
        data.travel_routes[{buildingId1, buildingId2}].capacity = 1;
        data.travel_routes[{buildingId1, buildingId2}].cost = cost;

        cout << "TUBE " << buildingId1 << " " << buildingId2 << ";";
        cerr << "New tube : " << buildingId1 << " - " << buildingId2 << "     cost : " << cost << endl;
    } else {
        cerr << "ERROR TUBE : Insufficient resources to creat new tube between " << buildingId1 << " and " << buildingId2 << endl;
    }
}

void	Game::upgrade(int buildingId1, int buildingId2) {
    auto route = data.travel_routes.find({buildingId1, buildingId2});

    if (route != data.travel_routes.end()) {
        int cost = ((route->second.capacity + 1) * route->second.cost);

        if (data.resources >= cost) {
            data.resources -= cost;
            route->second.capacity += 1;

             cout << "UPGRADE " << buildingId1 << " " << buildingId2 << ";";
             cerr << "Tube upgrade : " << buildingId1 << " - " << buildingId2 << "     cost : " << cost << endl;
        } else {
            cerr << "ERROR UPGRADE : Insufficient resources to upgrade the tube between " << buildingId1 << " and " << buildingId2 << endl;
        }
    } else {
        cerr << "ERROR UPGRADE : Np tube between " << buildingId1 << " and " << buildingId2 << endl;
    }
}

void	Game::teleport(int buildingIdEntrance, int buildingIdExit) {

}

void	Game::pod(int podId, initializer_list<int> buildingIds) {
    if (data.pods.find(podId) != data.pods.end()) {
        cerr << "ERROR POD : Pod with ID " << podId << " already exists" << endl;
        return ;
    }

    const int podCost = 1000;

    if (data.resources >= podCost && podId >= 1 && podId <= 500) {
        data.resources -= podCost;
        data.num_pods++;
        data.pods[podId].id = podId;
        data.pods[podId].numStopsCount = buildingIds.size();
        data.pods[podId].numStopsList = buildingIds;

        auto    it = buildingIds.begin();
        int     firstBuilding = *it;
        int     lastBuilding = *(buildingIds.end());

        cout << "POD " << podId;
        for (auto &buildingId : buildingIds)
            cout << " " << buildingId;
        cout << ";";

        if (firstBuilding == lastBuilding)
            cerr << "New Capsule : " << podId << "     cost : 1000" << "     LOOP" << std::endl;
        else
            cerr << "New Capsule : " << podId << "     cost : 1000" << "     LINE" << std::endl;
    } else {
        cerr << "ERROR POD : Insufficient resources or invalid pod ID" << endl;
    }
}

void	Game::destroy(int podId) {

}

void	Game::wait() {
    cout << "WAIT" << endl;
}
