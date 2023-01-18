#pragma once

#include "Position.h"
#define PI 3.14

class Circle :
	virtual public Position
{
private:
	double diameter;
public:
	Circle();
	Circle(double x, double y, double diameter);
	void setDiameter(double size);
	double getDiameter();
	double S();
	double P();
	friend std::ostream& operator << (std::ostream& out, Circle& pos);
};