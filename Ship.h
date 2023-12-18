
#ifndef SHIP_H
#define SHIP_H

#include "Grid.h"

class Ship {
public:
	// Ship constructor
	Ship();

	// Check if a ship can be placed at a given position and direction
	bool CanPlaceShip(const Grid& grid, int row, int col, bool horizontal) const;

	// Place the ship on the grid
	void PlaceShip(Grid& grid, int row, int col, bool horizontal);

	// Check if the ship is hit at a specific coordinate
	bool IsHitAt(int row, int col) const;

	// Check if the ship is sunk
	bool IsSunk() const;

private:
	int size;
	int hits;
	int row;
	int col;
	bool horizontal;
	//int CarrierCount;
	//int BattleshipCount;
	//int SubCruiseCount;
	//int DestroyerCount;
};

#endif