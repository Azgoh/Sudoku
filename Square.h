#include <iostream>
#include <string>
#pragma once

class Square
{
	int x;
	int y;
	int number;
public: 

	Square(int x, int y, int number);
	void setNum(int number);
	int getNum();
	int getX();
	int getY();
	bool hasNumber();
	virtual ~Square() = default;
};

