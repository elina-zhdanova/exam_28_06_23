#pragma once
#include <iostream>

class Position
{
private:
	double x;
	double y;
public:
	Position();
	Position(double x, double y);
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	void setXY(double x, double y);
	void increaseX(double x);
	void increaseY(double y);
	void increaseXY(double x, double y);
	//���������� operator<< ���������� ���������� operator+ (��� �������� ��������� �����������), �� ����������� ����, ��� � ������� ���� ���������� ������.
	//���������� ��������� std::cout << pos.���� �������� � ��� <</ ����� ������� � ��� ������ std::cout, 
	//� ������ ������� � ��� ������ ������ ������ Position.
	//std::cout �� ����� ���� �������� �������� ���� std::ostream.�������������, ���� ������������� ������� ����� ��������� ��� :
	friend std::ostream& operator << (std::ostream& out, Position& pos);
	//std::cout ���� ���������� out (������� ����� ������� �� std::cout ��� ������ �������)
};