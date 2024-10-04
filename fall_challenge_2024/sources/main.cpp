#include "../includes/header.hpp"

int main()
{
    Game	game;
    
    while (1) {
        game.data.update();
        game.data.printData();

        game.tube(0, 1);
        game.tube(0, 2);
        game.pod(1, {0, 1, 0, 2, 0});
        game.pod(2, {0, 1, 0, 2, 0});
        game.pod(3, {0, 1, 0, 2, 0});
        game.upgrade(0, 1);
        game.upgrade(0, 2);
        game.wait();

        cerr << "\n\n- DATA AT THE END -\n" << endl;
        game.data.printData();
    }

    return (0);
}
