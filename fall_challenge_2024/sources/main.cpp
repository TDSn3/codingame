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
        game.wait();
        game.end();

        cerr << "\n\n- DATA AT THE END -\n" << endl;
        game.data.printData();
    }

    return (0);
}
