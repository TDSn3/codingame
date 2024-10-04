#include "../includes/header.hpp"

int main()
{
    Game	game;
    
    while (1) {
        game.data.update();
        game.data.printData();

        game.tube(0, 1);
        game.tube(0, 2);
        game.pod(42, {0, 1, 0, 2, 0});
        game.end();
    }

    return (0);
}
