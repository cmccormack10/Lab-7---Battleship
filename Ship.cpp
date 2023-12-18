#include "Ship.h"

Ship::Ship() {
    this->size = 10;
    this->hits = 0;
    this->row = -1; // Initially not placed on the grid
    this->col = -1;
    this->horizontal = false;
    //int CarrierCount = 0;
    //int BattleshipCount = 0;
    //int SubCruiseCount = 0;
    //int DestroyerCount = 0;
}

int Grid::GetWidth() const {
    return 10; // Assuming the grid is always 10x10
}

int Grid::GetHeight() const {
    return 10;
}

bool Ship::CanPlaceShip(const Grid& grid, int row, int col, bool horizontal) const {
    // Check if the ship fits within the grid boundaries
    if (horizontal) {
        if (col + size > grid.GetWidth()) {
            return false;
        }
    }
    else {
        if (row + size > grid.GetHeight()) {
            return false;
        }
    }

    // Check if the ship overlaps with any existing ships (not implemented yet)

    return true;
}


void Ship::PlaceShip(Grid& grid, int row, int col, bool horizontal) {
    // Get user input for ship size
    int size = 0;
    do {
        cout << "Enter ship size (2-5): ";
        cin >> size;
        if (size < 2 || size > 5) {
            cout << "Invalid ship size. Please enter a value between 2 and 5." << endl;
        }
    } while (size < 2 || size > 5);

    // Validate placement coordinates and direction
    if (!CanPlaceShip(grid, row, col, horizontal)) {
        cout << "Invalid ship placement. Please try again." << endl;
        return;
    }

    // Mark the ship cells on the grid
    for (int i = 0; i < size; ++i) {
        if (horizontal) {
            grid.MarkCell(row, col + i, false); // Mark as ship cell, not hit
        }
        else {
            grid.MarkCell(row + i, col, false);
        }
    }

    // Update ship attributes
    this->size = size;
    this->row = row;
    this->col = col;
    this->horizontal = horizontal;

    // Update the grid display
    grid.DisplayGrid();
}



/*bool Ship::IsHitAt(int row, int col) const {
    if (horizontal) {
        return this->row == row && col >= this->col && col < this->col + size;
    }
    else {
        return this->col == col && row >= this->row && row < this->row + size;
    }
}*/

bool Ship::IsSunk() const {
    return hits == size;
}
