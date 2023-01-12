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
	//ѕерегрузка operator<< аналогична перегрузке operator+ (оба €вл€ютс€ бинарными операторами), за исключением того, что у первого типы параметров разные.
	//–ассмотрим выражение std::cout << pos.≈сли оператор Ц это <</ Ћевый операнд Ц это объект std::cout, 
	//а правый операнд Ц это объект вашего класса Position.
	//std::cout на самом деле €вл€етс€ объектом типа std::ostream.—ледовательно, наша перегруженна€ функци€ будет выгл€деть так :
	friend std::ostream& operator << (std::ostream& out, Position& pos);
	//std::cout стал параметром out (который будет ссылкой на std::cout при вызове функции)
};