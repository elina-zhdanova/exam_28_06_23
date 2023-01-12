#include <iostream>
#include <stdexcept>
//���� ������ ���� ����������, ��������, runtime_error: ����� ��� ����������, ������� ��������� �� ����� ����������
//����� ��� ���� ���������� ����� ����� what(), ������� ���������� ���������� �� ������. 
#include "Matrix.h"

void check(int n, int m) {
	if (n != m) throw std::exception("������� �� ����������");//exception-��� ��������� ����������
	//��������� ������ ������� ���������� ����� ���������� ������� � ������� �������� � ����. 
	//��������, ������ ����� ���� ������, ���������� ��������� ������ � ������������. 
	//������, ���� ������ ����������, �� ���������� ��������� ������� �� ����� ������, 
	//� ����� �������� �� ������ � �� ����� ����, ������ ��� ������� ���� �������. ��� ����� ������������ �������� ����������.
	//��� ���������� ����������� ���������� ����������� �� std::exception.
}

Matrix::Matrix() {
	std::cout << "������� ���������� ����� � �������: ";
	std::cin >> this->rows;
	std::cout << "������� ���������� �������� � �������: ";
	std::cin >> this->columns;
	this->arr = new double[this->rows * this->columns];
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

double Matrix::get_elem(int i, int j) const {
	if (i >= this->rows || i < 0 || j < 0 || j >= this->columns) throw std::exception("��������� ������� �������");
	else return getElem(this, i, j);
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
	std::cout << "������� ������� ������� " << this->rows << "x" << this->columns << "." << std::endl;
	std::cout << "������� �������� ������� ��������� (�������� �������� ���������)\n";
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cin >> getElem(this, i, j);
		}
	}
}

void Matrix::input(int n, int m) {
	this->rows = n;
	this->columns = m;
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cin >> getElem(this, i, j);
		}
	}
}

void Matrix::input(int n, int m, double* matr) {
	this->rows = n;
	this->columns = m;
	this->arr = matr;
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
	if (this->columns != mat2->get_rows()) throw std::exception("���������� �������� ������ ������� �� ��������� � ����������� ����� ������");
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

void Matrix::mult(const double* matr, int n, int m) {
	if (this->columns != n) throw std::exception("���������� �������� ������ ������� �� ��������� � ����������� ����� ������");
	double sum;
	double* prom = new double[this->rows * m];
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < m; j++) {
			sum = 0.0;
			for (int k = 0; k < this->columns; k++) {
				sum += this->get_elem(i, k) * matr[k * m + j];
			}
			prom[i * m + j] = sum;
		}
	}
	this->columns = m;
	this->arr = prom;
}

void Matrix::sum(const Matrix* mat2) {
	if (this->rows != mat2->get_rows() || this->columns != mat2->get_columns()) throw std::exception("������� �� �����");
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			getElem(this, i, j) += getElem(mat2, i, j);
		}
	}
}

void Matrix::sum(const Matrix* mat2, int size) {
	for (int i = 0; i < size; i++) {
		this->arr[i] += mat2->arr[i];
	}
}