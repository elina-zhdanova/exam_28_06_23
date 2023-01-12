#pragma once
#include "Position.h"

class Square :
	virtual public Position//решение алкмаза смерти
{
private:
	double side;
public:
	Square();
	Square(double x, double y, double side);
	void setSize(double size);
	double getSize();
	double S();
	double P();
	friend std::ostream& operator << (std::ostream& out, Square& pos);
};