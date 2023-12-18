#include "Grid.h"
#include "Ship.h"

using namespace std;

int main() {
    Grid grid;
    Ship ship;

    // Display initial grid
    grid.DisplayGrid();

    // Allow user to place multiple ships
    for (int i = 0; i < 5; ++i) {
        // Get user input for ship coordinates
        int row, col;
        bool horizontal;
        char direction;

        do {
            cout << "Enter starting row (0-9): ";
            cin >> row;
            cout << "Enter starting column (0-9): ";
            cin >> col;
            cout << "Enter direction (h for horizontal, v for vertical): ";
            cin >> direction;
            horizontal = (direction == 'h' || direction == 'H');

            if (!ship.CanPlaceShip(grid, row, col, horizontal)) {
                cout << "Invalid ship placement. Please try again." << endl;
            }
        } while (!ship.CanPlaceShip(grid, row, col, horizontal));

        // Place the ship on the grid
        ship.PlaceShip(grid, row, col, horizontal);
    }

    return 0;
}
