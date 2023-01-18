#include "CircleInSquare.h"

CircleInSquare::CircleInSquare() :
	Position() {
	this->setDiameter(0.0);
	this->setSize(0.0);
}

CircleInSquare::CircleInSquare(double x, double y, double side, double diameter) :
	Position(x, y) {
	this->setDiameter(diameter);
	this->setSize(side);
}

std::ostream& operator << (std::ostream& out, CircleInSquare& circleInSquare) {
	out << "X = " << circleInSquare.getX() << std::endl
		<< "Y = " << circleInSquare.getY() << std::endl
		<< "Side     = " << circleInSquare.getSize() << std::endl
		<< "Diameter = " << circleInSquare.getDiameter() << std::endl;
	return out;
}