#include "../../../includes/header.hpp"

void	Game::tube(int buildingId1, int buildingId2) {
    auto building1 = data.buildings.find(buildingId1);
    auto building2 = data.buildings.find(buildingId2);

    if (building1 ==  data.buildings.end() || building2 ==  data.buildings.end())
        throw runtime_error("ERROR TUBE : Invalid buildingId for " + to_string(buildingId1) + " or " + to_string(buildingId2));

    if (building1->second->routeCount >= 5 || building2->second->routeCount >= 5)
        throw runtime_error("ERROR TUBE : Maximum of 5 tube connected to " + to_string(buildingId1) + " or " + to_string(buildingId2));

    auto route = data.travel_routes.find({buildingId1, buildingId2});

    if (route != data.travel_routes.end() && route->second.capacity != 0)
        throw runtime_error("ERROR TUBE : Tube already exists between " + to_string(buildingId1) + " and " + to_string(buildingId2));

    float	distance = data.calculateDistance(buildingId1, buildingId2);

    if (distance == -1)
        return ;

    int		cost = static_cast<int>(floor(distance * 10));

    if (data.resources >= cost) {
        data.resources -= cost;
        data.num_travel_routes++;
        data.travel_routes[{buildingId1, buildingId2}].buildingId1 = buildingId1;
        data.travel_routes[{buildingId1, buildingId2}].buildingId2 = buildingId2;
        data.travel_routes[{buildingId1, buildingId2}].capacity = 1;
        data.travel_routes[{buildingId1, buildingId2}].cost = cost;

        data.buildings[buildingId1]->routeCount++;
        data.buildings[buildingId1]->connectedRoute.push_back(&data.travel_routes[{buildingId1, buildingId2}]);

        data.buildings[buildingId2]->routeCount++;
        data.buildings[buildingId2]->connectedRoute.push_back(&data.travel_routes[{buildingId1, buildingId2}]);

        cout << "TUBE " << buildingId1 << " " << buildingId2 << ";";
        cerr << "New tube : " << buildingId1 << " - " << buildingId2 << "     cost : " << cost << endl;
    } else {
        throw runtime_error("ERROR TUBE : Insufficient resources to creat new tube between " + to_string(buildingId1) + " and " + to_string(buildingId2));
    }
}

void	Game::upgrade(int buildingId1, int buildingId2) {
    auto route = data.travel_routes.find({buildingId1, buildingId2});

    if (route != data.travel_routes.end() && route->second.capacity != 0) {
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
    auto building1 = data.buildings.find(buildingIdEntrance);
    auto building2 = data.buildings.find(buildingIdExit);

    if (building1 ==  data.buildings.end() || building2 ==  data.buildings.end()) {
        cerr << "ERROR TUBE : Invalid buildingId for " << buildingIdEntrance << " or " << buildingIdExit << endl;
        return ;
    }    

    if (building1->second->routeCount >= 5 || building2->second->routeCount >= 5) {
        cerr << "ERROR TUBE : Maximum of 1 teleporter connected to " << buildingIdEntrance << " or " << buildingIdExit << endl;
        return ;        
    }

    if (data.travel_routes.find({buildingIdEntrance, buildingIdExit}) != data.travel_routes.end()
        && data.travel_routes.find({buildingIdEntrance, buildingIdExit})->second.capacity == 0) {
        cerr << "ERROR TELEPORT : Teleporter already exists between " << buildingIdEntrance << " and " << buildingIdExit << endl;
        return ;
    }

    const int teleportCost = 5000;

    if (data.resources >= teleportCost) {
        data.resources -= teleportCost;
        data.num_travel_routes++;
        data.travel_routes[{buildingIdEntrance, buildingIdExit}].buildingId1 = buildingIdEntrance;
        data.travel_routes[{buildingIdEntrance, buildingIdExit}].buildingId2 = buildingIdExit;
        data.travel_routes[{buildingIdEntrance, buildingIdExit}].capacity = 0;
        data.travel_routes[{buildingIdEntrance, buildingIdExit}].cost = teleportCost;

        data.buildings[buildingIdEntrance]->teleporterCount++;
        data.buildings[buildingIdEntrance]->connectedRoute.push_back(&data.travel_routes[{buildingIdEntrance, buildingIdExit}]);

        data.buildings[buildingIdExit]->teleporterCount++;
        data.buildings[buildingIdExit]->connectedRoute.push_back(&data.travel_routes[{buildingIdEntrance, buildingIdExit}]);

        cout << "TELEPORT " << buildingIdEntrance << " " << buildingIdExit << ";";
        cerr << "New teleporter : " << buildingIdEntrance << " - " << buildingIdExit << "     cost : " << teleportCost << endl;
    } else {
        cerr << "ERROR TELEPORT : Insufficient resources to creat new teleporter between " << buildingIdEntrance << " and " << buildingIdExit << endl;
    }
}

void	Game::pod(int podId, vector<int> buildingIds) {
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
    auto pod = data.pods.find(podId);

    if (pod == data.pods.end()) {
        cerr << "ERROR DESTROY : Pod with ID " << podId << " doesn't exist" << endl;
        return ;
    }

    const int destroyRefund = 750;

    data.resources += destroyRefund;
    data.pods.erase(podId);
    
    cout << "DESTROY " << podId << ";";
}

void	Game::wait() {
    cout << "WAIT" << endl;
}
