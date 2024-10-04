#include "../includes/header.hpp"

int main()
{
    Game	game;
    
    while (1) {
        game.data.update();
        game.data.printData();

        game.tube(0, 1);
        game.tube(0, 2);
        game.pod(42, {0, 1, 0, 2, 0, 1, 0, 2});
        game.end();

        // cout << "TUBE 0 1;TUBE 0 2;POD 42 0 1 0 2 0 1 0 2" << endl; // TUBE | UPGRADE | TELEPORT | POD | DESTROY | WAIT
    }

    return (0);
}
