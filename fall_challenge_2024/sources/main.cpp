#include "../includes/header.hpp"

int main()
{
    Data	data;
	
	// game loop
    while (1) {
        data.update();
		data.printData();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << "TUBE 0 1;TUBE 0 2;POD 42 0 1 0 2 0 1 0 2" << endl; // TUBE | UPGRADE | TELEPORT | POD | DESTROY | WAIT
    }
	
	return (0);
}
