#include "../includes/header.hpp"

void strategy(Game &game);
bool compareDistance(Data &data, int landingPadId1, int landingPadId2, int lunarModuleId);

int main()
{
    Game	game;
    
    while (1) {
        game.data.update();
        game.data.printData();

        strategy(game);   

        // game.tube(0, 1);
        // game.tube(0, 2);
        // game.pod(1, {0, 1, 0, 2, 0});
        // game.pod(2, {0, 1, 0, 2, 0});
        // game.pod(3, {0, 1, 0, 2, 0});
        // game.upgrade(0, 1);
        // game.upgrade(0, 2);
        game.wait();

        cerr << "\n\n- DATA AT THE END -\n" << endl;
        game.data.printData();
    }

    return (0);
}

void strategy(Game &game) {
    vector<int> nearestBuildingsIds;

    for (auto &buildingPair : game.data.buildings)
            nearestBuildingsIds.push_back(buildingPair.second->id);

    for (auto &buildingPair : game.data.buildings) {
        s_building &building = *(buildingPair.second);

        if (building.routeCount > 0) continue ;

        sort(nearestBuildingsIds.begin(), nearestBuildingsIds.end(),
            [&game, &building](int xId, int yId) {
                return (compareDistance(game.data, xId, yId, building.id));
            }
        );

        bool found = false;

        for (auto &nearestBuildingId : nearestBuildingsIds) {
            if (nearestBuildingId == building.id) continue ;
            
            if (game.data.buildings[nearestBuildingId]->routeCount < 5
                && game.data.buildings[nearestBuildingId]->routeCount > 0) {
                try {
                    game.tube(building.id, nearestBuildingId);
                } catch (const runtime_error &e) {
                    cerr << e.what() << endl;
                    continue ;
                }

                found = true;
                break;
            }
        }

        if (!found) {
            for (auto &nearestBuildingId : nearestBuildingsIds) {
                if (nearestBuildingId == building.id) continue ;
                
                if (game.data.buildings[nearestBuildingId]->routeCount < 5) {
                    try {
                        game.tube(building.id, nearestBuildingId);
                    } catch (const runtime_error &e) {
                        cerr << e.what() << endl;
                        continue ;
                    }

                    found = true;
                    break;
                }
            }            
        }

        if (!found)
            cerr << "SUSPICIOUS" << endl;
    }
 
    // game.pod(1, mergedRoute);
}

bool compareDistance(Data &data, int xId, int yId, int originId) {
    float distance1 = data.calculateDistance(xId, originId);
    float distance2 = data.calculateDistance(yId, originId);

    return (distance1 < distance2);
}
