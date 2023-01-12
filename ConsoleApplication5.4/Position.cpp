#include "Position.h"

Position::Position() {
	this->setXY(0.0, 0.0);
}

Position::Position(double x, double y) {
	this->setXY(x, y);
}

double Position::getX() {//��������� ��������
	return this->x;
}

double Position::getY() {
	return this->y;
}

void Position::setX(double x) {//������������� ��������
	this->x = x;
}

void Position::setY(double y) {
	this->y = y;
}

void Position::setXY(double x, double y) {
	this->setX(x);
	this->setY(y);
}

void Position::increaseX(double x) {
	this->setX(this->getX() + x);
}

void Position::increaseY(double y) {
	this->setY(this->getY() + y);
}

void Position::increaseXY(double x, double y) {
	this->increaseX(x);
	this->increaseY(y);
}

std::ostream& operator << (std::ostream& out, Position& pos)  //��������� operator<< �������� ������ ������ Point,
// �� ����� �������� ���������� � ������ ������ Position.
// ����� ����������� ����������� �����
{
	out << "X = " << pos.getX() << std::endl << "Y = " << pos.getY() << std::endl;
	// ���������� std::ostream, ����� �� �����
	// ���������� � ������� ������ operator<<
	return out;
}		