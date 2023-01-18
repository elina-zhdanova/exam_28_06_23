#include <iostream>
#include "Position.h"
#include "Square.h"
#include "Circle.h"
#include "CircleInSquare.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	setlocale(LC_ALL, "Russian");
	int option;
	int x, y, side, diameter;
	Position pos;
	Circle circle;
	Square square;
	CircleInSquare C_I_S;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Создание точки\n"
			<< "2. Создание квадрата\n"
			<< "3. Создание круга\n"
			<< "4. Создание круга в квадрате\n"
			<< "5. Вывод\n"
			<< "6. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Введите координаты точки: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			pos.setXY(x, y);
			break;
		case 2:
			cout << "Введите координаты квадрата: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Введите длину стороны квадрата: ";
			cin >> side;
			square.setXY(x, y);
			square.setSize(side);
			break;
		case 3:
			cout << "Введите координаты круга: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Введите диаметр круга: ";
			cin >> diameter;
			circle.setXY(x, y);
			circle.setDiameter(diameter);
			break;
		case 4:
			cout << "Введите координаты вписанной в квадрат окружности: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Введите длину стороны квадрата: ";
			cin >> side;
			cout << "Введите диаметр круга: ";
			cin >> diameter;
			C_I_S.setXY(x, y);
			C_I_S.setSize(side);
			C_I_S.setDiameter(diameter);
			break;
		case 5:
			system("cls");
			cout << "Выберите объект, который желаете вывести:\n"
				<< "1. Точка\n"
				<< "2. Квадрат\n"
				<< "3. Круг\n"
				<< "4. Вписанная в квадрат окружность\n"
				<< "5. Сторона квадрата\n"
				<< "6. Диаметр круга\n"
				<< "7. Сторона квадрата, в который вписана окружность\n"
				<< "8. Диаметр вписанного круга\n"
				<< "9. Назад\n"
				<< "Ваш выбор: ";
			cin >> option;
			switch (option) {
			case 1:
				cout << pos;
				break;
			case 2:
				cout << square;
				break;
			case 3:
				cout << circle;
				break;
			case 4:
				cout << C_I_S;
				break;
			case 5:
				cout << square.getSize() << endl;
				break;
			case 6:
				cout << circle.getDiameter() << endl;
				break;
			case 7:
				cout << C_I_S.getSize() << endl;
				break;
			case 8:
				cout << C_I_S.getDiameter() << endl;
				break;
			case 9:
			default:
				break;
			}
			break;
		case 6:
			return 0;
		default:
			break;
		}
	}
}