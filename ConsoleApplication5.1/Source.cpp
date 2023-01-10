#include <iostream>
#include <stdexcept>
//есть разные виды исключенйи, например, runtime_error: общий тип исключений, которые возникают во время выполнения
//Также все типы исключений имеют метод what(), который возвращает информацию об ошибке. 
#include "Header.h"
#include "Det.h"

void check(int n, int m) {
	if (n != m) throw std::exception("Матрица не квадратная");//exception-для обработки исключений
	//Некоторые ошибки времени выполнения можно обнаружить заранее с помощью проверок в коде. 
	//Например, такими могут быть ошибки, нарушающие инвариант класса в конструкторе. 
	//Обычно, если ошибка обнаружена, то дальнейшее выполение функции не имеет смысла, 
	//и нужно сообщить об ошибке в то место кода, откуда эта функция была вызвана. Для этого предназначен механизм исключений.
	//Все исключения стандартной библиотеки наследуются от std::exception.
}

Matrix::Matrix(int n, int m) {
	this->rows = n;
	this->columns = m;
	this->arr = new double[n * m];
}

Matrix::Matrix(int n, int m, double* matr) {
	this->rows = n;
	this->columns = m;
	this->arr = matr;
}

Matrix::~Matrix() {
	delete[] this->arr;
}

int Matrix::get_columns() const {
	return this->columns;
}

int Matrix::get_rows() const {
	return this->rows;
}

double Matrix::get_elem(int i, int j) 
	const {return arr[i * columns + j]; }  //вернуть(i, j) элемент

double Matrix::det() {
	check(this->rows, this->columns);
	double determinant;
	determinant = det_Minors(this->arr, this->columns);
	return determinant;
}

void Matrix::mult_by_num(double num) {
	for (int i = 0; i < this->rows * this->columns; i++) {
		this->arr[i] *= num;
	}
}

void Matrix::print() {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

void Matrix::input() {
	std::cout << "Размеры данного массива " << this->rows << "x" << this->columns << "." << std::endl;
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cin >> getElem(this, i, j);
		}
	}
}

double Matrix::trace() {
	check(this->rows, this->columns);
	double sum = 0;
	for (int i = 0; i < this->rows; i++) {
		sum += this->get_elem(i, i);
	}
	return sum;
}

void Matrix::mult(const Matrix* mat2) {
	if (this->columns != mat2->get_rows()) throw std::exception("Количество столбцов первой матрицы не совпадает с количеством строк второй");
	//дальнейшее выполненние бессмысленно 
	double sum;
	double* prom = new double[this->rows * mat2->get_columns()];
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < mat2->get_columns(); j++) {
			sum = 0.0;
			for (int k = 0; k < this->columns; k++) {
				sum += this->get_elem(i, k) * mat2->get_elem(k, j);
			}
			prom[i * mat2->columns + j] = sum;
		}
	}
	this->columns = mat2->get_columns();
	this->arr = prom;
}

void Matrix::sum(const Matrix* mat2) {
	if (this->rows != mat2->get_rows() || this->columns != mat2->get_columns()) throw std::exception("Матрицы не равны");
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			getElem(this, i, j) += getElem(mat2, i, j);
			
		}
	}
	/*for (int i = 0; i < mat2.columns * mat2.rows; i++)//mat2 не имеет тип класса.
	{
		this->arr[i] = this->arr[i] + mat2.arr[i];
	}*/
}