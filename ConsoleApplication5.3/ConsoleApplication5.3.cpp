#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;
using std::exception;

int main() {
	setlocale(LC_ALL, "Russian");
	int option;
	Matrix matr1, matr2, prom;
	double mnoj;
	int n, m;
	while (true) {
		try {
			cout << "Выберите действие:\n"
				<< "1. Ввести новую матрицу\n"
				<< "2. Ввести дополнительную матрицу\n"
				<< "3. Вывести матрицу\n"
				<< "4. найти сумму двух матриц\n"
				<< "5. Найти разницу двух матриц\n"
				<< "6. Поменять знак элементов матрицы\n"
				<< "7. Умножить основную матрицу на вспомогательную\n"
				<< "8. Умножить матрицу на число\n"
				<< "9. Определитель матрицы\n"
				<< "10. След матрицы\n"
				<< "11. Количество столбцов матрицы\n"
				<< "12. Вывести элемент i строки j столбца\n"
				<< "13. Выход\n"
				<< "Ваш выбор: ";
			cin >> option;
			switch (option) {
			case 1:
				cout << "Введите ранг основной матрицы: ";
				cin >> matr1;
				break;
			case 2:
				cout << "Введите ранг вспомогательной матрицы: ";
				cin >> matr2;
				break;
			case 3:
				cout << "Какую матрицу вы хотите вывести?\n"
					<< "1. Основная\n"
					<< "2. Вспомогательная\n"
					<< "Ваш выбор: ";
				cin >> m;
				if (m == 1) cout << matr1;
				else cout << matr2;
				break;
			case 4:
				cout << matr1 + matr2;
				break;
			case 5:
				cout << matr1 - matr2;
				break;
			case 6:
				cout << -matr1;
				break;
			case 7:
				cout << matr1 * matr2;
				break;
			case 8:
				cout << "Введите множитель: ";
				cin >> mnoj;
				cout << matr1 * mnoj;
				break;
			case 9:
				cout << "След матрицы равен: " << matr1.tr() << endl;
				break;
			case 10:
				cout << "Количество столбцов в матрице: " << matr1.get_columns() << endl;
				break;
			case 11:
				cout << "Введите индексы искомого элемента через пробел: ";
				cin >> n >> m;
				cout << "Элемент matr1[" << n << ", " << m << "] = " << matr1.get_elem(n, m) << endl;
				break;
			case 12:
				return 0;
			default:
				break;
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		n = m = 0;
	}
}