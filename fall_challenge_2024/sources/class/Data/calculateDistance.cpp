#include "../../../includes/header.hpp"

float	Data::calculateDistance (int buildingId1, int buildingId2) {
    if (buildings.find(buildingId1) == buildings.end() || buildings.find(buildingId2) == buildings.end()) {
        cerr << "ERROR calculateDistance" << endl;
        return (-1);
    }

    s_building*	b1 = buildings[buildingId1];
    s_building*	b2 = buildings[buildingId2];
    float		distance = sqrt(pow(b2->x - b1->x, 2) + pow(b2->y - b1->y, 2));

    return (distance);
}
