#include <iostream>
#include <stdexcept>
#include "Header.h"

using std::cout;
using std::cin;
using std::endl;

void input(int& n, int& m) {
	while (true) {
		cout << "Введите количество строк в матрице: ";
		cin >> n;
		cout << "Введите количество столбцов в матрице: ";
		cin >> m;
		if (n > 0 && m > 0) break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int choise;
	Matrix* matr1 = nullptr, * matr2 = nullptr;
	double mnoj;
	int n, m;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Ввести новую матрицу\n"
			<< "2. Ввести дополнительную матрицу\n"
			<< "3. Вывести матрицу\n"
			<< "4. найти сумму двух матриц\n"
			<< "5. Найти произведение двух матриц\n"
			<< "6. След матрицы\n"
			<< "7. Определитель матрицы\n"
			<< "8. Умножить матрицу на число\n"
			<< "9. Количество строк матрицы\n"
			<< "10. Количество столбцов матрицы\n"
			<< "11. Вывести элемент i строки j столбца\n"
			<< "12. Выход\n"
			<< "Ваш выбор: ";
		cin >> choise;
		switch (choise) 
		{

			case 1:
				input(n, m);
				matr1 = new Matrix(n, m);
				matr1->input();
				break;
			case 2:
				input(n, m);
				matr2 = new Matrix(n, m);
				matr2->input();
				break;
			case 3:
				matr1->print();
				break;
			case 4:
				matr1->sum(matr2);
				matr1->print();
				break;
			case 5:
				matr1->mult(matr2);
				matr1->print();
				break;
			case 6:
				cout << "След матрицы равен: " << matr1->trace() << endl;
				break;
			case 7:
				cout << "Определитель матрицы равен: " << matr1->det() << endl;
				break;
			case 8:
				cout << "Введите множитель: ";
				cin >> mnoj;
				matr1->mult_by_num(mnoj);
				matr1->print();
				break;
			case 9:
				cout << "Количество строк в матрице: " << matr1->get_rows() << endl;
				break;
			case 10:
				cout << "Количество столбцов в матрице: " << matr1->get_columns() << endl;
				break;
			case 11:
				cout << "Введите индексы искомого элемента через пробел: ";
				cin >> n >> m;
				cout << "Элемент matr1[" << n << ", " << m << "] = " << matr1->get_elem(n, m) << endl;
				break;
			case 12:
				return 0;
			default:
				break;
			
		}
	}	
}