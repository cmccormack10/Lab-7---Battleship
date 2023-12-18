#ifndef GRID_H
#define GRID_H

#include <iostream>

using namespace std;

class Grid {
public:
	// Grid constructor
	Grid();

	char grid[10][10];

	// Mark a cell as hit or miss
	void MarkCell(int row, int col, bool isHit);

	// Check if a cell is valid
	bool IsValidCoordinate(int row, int col) const;

	// Display the grid with coordinates
	void DisplayGrid() const;

	int GetWidth() const;

	int GetHeight() const;

private:
	int row;
	int col;
	bool isHit;
	char playerShipGrid[10][10];
	char playerShotGRid[10][10];
	char computerShipGrid[10][10];
	char computerShotGrid[10][10];


};



#endif // GRID_H
