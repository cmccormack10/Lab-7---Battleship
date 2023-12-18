
#include <iostream>
#include "Grid.h"

using namespace std;



Grid::Grid() {
    int row = 0;
    int col = 0;
    bool isHit = false;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            grid[i][j] = '~';
        }
    }
};

void Grid::MarkCell(int row, int col, bool isHit) {
    if (IsValidCoordinate(row, col)) {
        Grid::grid[row][col] = isHit ? 'X' : 'S';
    }
}

void Grid::DisplayGrid() const
{
    cout << "   ";
    for (int col = 0; col < 10; ++col) {
        cout << col << " ";
    }
    cout << endl;

    for (int row = 0; row < 10; ++row) {
        cout << row << "  ";
        for (int col = 0; col < 10; ++col) {
            cout << Grid::grid[row][col] << " ";
        }
        cout << std::endl;
    }
}

bool Grid::IsValidCoordinate(int row, int col) const {
    if (row >= 0 && row < 10 && col >= 0 && col < 10) {
        return true;
    }
    else {
        return false;
    }
}


