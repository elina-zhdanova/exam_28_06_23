#include "Square.h"

Square::Square() : Position() {
	this->setSize(0.0);
}

Square::Square(double x, double y, double side) :
	Position(x, y) {
	this->setSize(side);
}

void Square::setSize(double size) {
	this->side = size;
}

double Square::getSize() {
	return this->side;
}

double Square::S() {
	return this->getSize() * this->getSize();
}

double Square::P() {
	return this->getSize() * 4.0;
}

std::ostream& operator << (std::ostream& out, Square& square) {
	out << "X = " << square.getX() << std::endl
		<< "Y = " << square.getY() << std::endl
		<< "side = " << square.getSize() << std::endl;
	return out;
}
