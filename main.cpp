#include "Grid.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
int main(void) {
start: 
	system("cls");
	srand(time(NULL));

	Grid* g = new Grid();
	int InvisNumbers[9][9];
	for (int i = 0; i < 9; i=i+3) {
		for (int j = 0; j < 9; j = j + 3) {
			again: 
			int num = 1 + rand() % 9;
			if (g->isValidPlace(i, i, num)) {
			g->setNumberOnSquare(i, i, num);
			}
			else goto again;
		}
	}
	if(g->solveSudoku()){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			InvisNumbers[i][j] = g->getSquareNumber(i, j);
		}
	}

	int cnt, difficulty;
	cout << "Please select the game's difficulty[Easy(0), Medium(1), Hard(2), Very Hard(3), Extreme(4)]: ";
	cin >> difficulty;
	switch (difficulty) {
		case 0:
			cnt = 55;
			break;
		case 1:
			cnt = 60;
			break;
		case 2:
			cnt = 65;
			break;
		case 3:
			cnt = 70;
			break;
		case 4:
			cnt = 75;
			break;
	}
	while (cnt>=0) {
		int x = rand() % 9;
		int y = rand() % 9;
		if (g->squareHasNumber(x, y)) {
			g->removeNumber(x, y);
			cnt--;
		}
	}
	
	for (;;) {
		int n, xin, yin;
		cout << endl << g->toString() << endl;
		if (g->allSquaresAreCovered()) break;
		cout << "Enter a number and its x and y coordinates on the grid: ";
		cin >> n >> xin >> yin;
		while(cin.fail()) {
			cout << "Invalid Input" << endl << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a number and its x and y coordinates on the grid: ";
			cin >> n >> xin >> yin;
		}
		if (n == InvisNumbers[xin][yin]) g->setNumberOnSquare(xin, yin, n);
		else cout <<"This number can't be placed in: (" << xin << "," << yin <<")"<< endl;
	}
	cout << "Congratulations! Do u want to play again? Press Y(yes) or N(no)" << endl;
	char choice;
	cin >> choice;
	if (choice == 'Y' || choice == 'y') goto start;
	}
	return 0;
}