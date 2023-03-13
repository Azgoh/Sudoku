#include "Square.h"
#include <string>
#include <cstdlib>
using namespace std;
#pragma once

class Grid
{
	Square*** squares;
	int sizeX = 9;
	int sizeY = 9;

public:
	Grid();
	string toString();
	int getSizeX();
	int getSizeY();
	void removeNumber(int x, int y);
	bool squareHasNumber(int x, int y);
	void setNumberOnSquare(int x, int y, int num);
	bool allSquaresAreCovered();
	int getSquareNumber(int x, int y);
	bool isPresentInCol(int col, int num);
	bool isPresentInRow(int row, int num);
	bool isPresentInBox(int boxStartRow, int boxStartCol, int num);
	bool findEmptyPlace(int& row, int& col);
	bool isValidPlace(int row, int col, int num);
	bool solveSudoku();
	void setSquares();
	~Grid();
};

