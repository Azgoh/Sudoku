#include "Square.h"

Square::Square(int x,int y, int number)
{
	this->x=x;
	this->y = y;
	this->number = number;
}

void Square::setNum(int number)
{
	this->number = number; 
}

int Square::getNum()
{
	return number;
}

int Square::getX()
{
	return x;
}

int Square::getY()
{
	return y;
}

bool Square::hasNumber()
{
	return number != -1;
}

