#include "../../../includes/header.hpp"

void	Game::tube(int buildingId1, int buildingId2) {
    float	distance = data.calculateDistance(buildingId1, buildingId2);

    if (distance == -1)
        return ;

    int		cost = static_cast<int>(floor(distance * 10));

    if (data.resources >= cost) {
        data.resources -= cost;
        data.travel_routes[{buildingId1, buildingId2}].capacity = 1;
        data.travel_routes[{buildingId1, buildingId2}].cost = cost;

        cout << "TUBE " << buildingId1 << " " << buildingId2 << ";";
        cerr << "New tube : " << buildingId1 << " - " << buildingId2 << "     cost : " << cost << endl;
    } else {
        cerr << "ERROR TUBE : Failed to creat new tube ( " << buildingId1 << " - " << buildingId2 << " )" << endl;
    }
}

void	Game::upgrade(int buildingId1, int buildingId2) {

}

void	Game::teleport(int buildingIdEntrance, int buildingIdExit) {

}

void	Game::pod(int podId, initializer_list<int> buildingIds) {
    const int podCost = 1000;

    if (data.resources >= podCost && podId >= 1 && podId <= 500) {
        data.resources -= podCost;

        auto    it = buildingIds.begin();
        int     firstBuilding = *it;
        int     lastBuilding = *(buildingIds.end());

        cout << "POD " << podId;
        for (auto &buildingId : buildingIds)
            cout << " " << buildingId;
        cout << ";";

        if (firstBuilding == lastBuilding)
            cerr << "New Capsule : " << podId << "     LOOP" << std::endl;
        else
            cerr << "New Capsule : " << podId << "     LINE" << std::endl;
    } else {
        cerr << "ERROR POD" << endl;
    }
}

void	Game::destroy(int podId) {

}

void	Game::wait() {
    cout << "WAIT";
}

void	Game::end() {
    cout << endl;
}
