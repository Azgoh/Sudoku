#include "Grid.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
using namespace std;

Grid::Grid()
{
    squares = new Square **[sizeX];
	for (int i = 0; i < sizeX; i++) {
		squares[i] = new Square * [sizeY];
		for (int j = 0; j < sizeY; j++) {
			squares[i][j] = new Square(i, j,-1);
		}
	}
}
void Grid::setNumberOnSquare(int x, int y, int number)
{
squares[x][y]->setNum(number);
}

bool Grid::allSquaresAreCovered()
{
	int cnt = 0;
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			if (squares[i][j]->hasNumber()) cnt++;
		}
	}
	return cnt == 81;
}

int Grid::getSquareNumber(int x, int y)
{
	return squares[x][y]->getNum();
}

bool Grid::isPresentInCol(int col, int num)
{
	for (int row = 0; row < sizeX; row++) {
		if (squares[row][col]->getNum() == num) return true;
	}
	return false;
}

bool Grid::isPresentInRow(int row, int num)
{
	for (int col = 0; col < sizeY; col++) {
		if (squares[row][col]->getNum() == num) return true;
	}
	return false;
}

bool Grid::isPresentInBox(int boxStartRow, int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++) {
		for (int col = 0; col < 3; col++) {
			if (squares[row + boxStartRow][col + boxStartCol]->getNum() == num) return true;
		}
	}
	return false;
}

bool Grid::findEmptyPlace(int& row, int& col)
{
	for (row = 0; row < sizeX; row++) {
		for (col = 0; col < sizeY; col++) {
			if (!squares[row][col]->hasNumber()) return true;
		}
	}
	return false;

}

bool Grid::isValidPlace(int row, int col, int num)
{
	return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row % 3, col - col % 3, num);
}

bool Grid::solveSudoku()
{
	int row, col;
	if (!findEmptyPlace(row, col)) return true;
	for (int num = 1; num <= 9; num++) {
		if (isValidPlace(row, col, num)) {
			squares[row][col]->setNum(num);
			if (solveSudoku()) 
				return true;
			squares[row][col]->setNum(-1);
		}
	}
	return false;
}

void Grid::setSquares()
{	
	srand(time(NULL));
	for (int row = 0; row < sizeX; row++) {
		for (int col = 0; row < sizeY; col++) {
			int num = 1 + rand() % 9;
			squares[row][col]->setNum(num);
		}
	}
}

bool Grid::squareHasNumber(int x, int y)
{
return squares[x][y]->hasNumber();
}


string Grid::toString()
{
	stringstream sstm;
	sstm<< "     ________________________________ \n"
		<< "    |                                |\n"
		<< "    |      0  1  2  3  4  5  6  7  8 |\n"
		<< "    | _______________________________|\n"
		<< "    |                                |\n";
	for (int i = 0; i < sizeX; i++) {
		sstm << "    |  " << i << "| ";
		for (int j = 0; j < sizeY; j++)
			if (squares[i][j]->hasNumber()) sstm << " " << squares[i][j]->getNum() << " ";
			else sstm << " " << "- ";
		sstm << "|\n";
	}
	sstm << "    |________________________________|\n";
	return sstm.str();
}

int Grid::getSizeX()
{
	return sizeX;
}

int Grid::getSizeY()
{
	return sizeY;
}

void Grid::removeNumber(int x,int y)
{
	squares[x][y]->setNum(-1);
}

Grid::~Grid()
{
	for (int i = 0; i < sizeX; i++) {
		for (int j = 0; j < sizeY; j++) {
			delete squares[i][j];
		}
		delete[] squares[i];
	}
	delete[] squares;
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    