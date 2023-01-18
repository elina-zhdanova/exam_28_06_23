#include "Circle.h"

Circle::Circle() : Position() {
	this->setDiameter(0.0);
}

Circle::Circle(double x, double y, double diameter) :
	Position(x, y) {
	this->setDiameter(diameter);
}

void Circle::setDiameter(double diameter) {
	this->diameter = diameter;
}

double Circle::getDiameter() {
	return this->diameter;
}

double Circle::S() {
	return PI * this->getDiameter() * this->getDiameter() / 4.0;;
}

double Circle::P() {
	return this->getDiameter() * PI;
}

std::ostream& operator << (std::ostream& out, Circle& circle) {
	out << "X = " << circle.getX() << std::endl
		<< "Y = " << circle.getY() << std::endl
		<< "diameter = " << circle.getDiameter() << std::endl;
	return out;
}
