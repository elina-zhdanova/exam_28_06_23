#include "Matrix.h"

Matrix::Matrix() {
	this->columns = 0;
	this->arr = nullptr;
}

Matrix::Matrix(int m) {
	this->columns = m;
	this->arr = new double[m * m];
}

Matrix::Matrix(int m, double* matr) {
	this->columns = m;
	this->arr = matr;
}

Matrix::Matrix(const Matrix& matr) {
	this->columns = matr.columns;
	this->arr = new double[this->columns * this->columns];
	for (int i = 0; i < this->columns * this->columns; i++) this->arr[i] = matr.arr[i];
}

Matrix::~Matrix() {
	delete[] this->arr;
}

int Matrix::get_columns() const {
	return this->columns;
}

double Matrix::get_elem(int i, int j) const {
	if (i < 0 || j < 0 || j >= this->columns) throw std::exception("Введенные индексы неверны");
	else return getElem(this, i, j);
}

void Matrix::input(int m) {
	this->columns = m;
	if (this->arr != nullptr) delete[] this->arr;
	this->arr = new double[m * m];
	for (int i = 0; i < this->columns; i++) {
		for (int j = 0; j < this->columns; j++) {
			std::cin >> getElem(this, i, j);
		}
	}
}

void Matrix::input(int m, double* matr) {
	this->columns = m;
	if (this->arr != nullptr) 
		delete[] this->arr;
	this->arr = matr;
}

void Matrix::input(const Matrix& matr) {
	this->columns = matr.columns;
	if (this->arr != nullptr) 
		delete[] this->arr;
	this->arr = new double[matr.columns * matr.columns];
	for (int i = 0; i < matr.columns * matr.columns; i++) this->arr[i] = matr.arr[i];
}

std::string Matrix::print() {
	std::string out = "";
	for (int i = 0; i < this->columns; i++) {
		for (int j = 0; j < this->columns; j++) {
			out += std::to_string(this->get_elem(i, j)) + " ";
		}
		out += "\n";
	}
	return out;
}

Matrix Matrix::sum(const Matrix& mat2) const {
	return this->sum(mat2, this->columns * this->columns);
}

Matrix Matrix::sum(const Matrix& mat2, int size) const {
	Matrix matr(this->columns);
	for (int i = 0; i < size; i++) {
		matr.arr[i] = this->arr[i] + mat2.arr[i];
	}
	return matr;
}

Matrix Matrix::mult(const Matrix& mat2) const {
	return Matrix(this->columns, this->mult(mat2.arr, mat2.columns));
}

double* Matrix::mult(const double* matr, int m) const {
	double sum;
	double* prom = new double[m * m];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			sum = 0.0;
			for (int k = 0; k < m; k++) {
				sum += this->get_elem(i, k) * matr[k * m + j];
			}
			prom[i * m + j] = sum;
		}
	}
	return prom;
}

double Matrix::tr() const {
	double sum = 0;
	for (int i = 0; i < this->columns; i++) {
		sum += this->get_elem(i, i);
	}
	return sum;
}


Matrix Matrix::mult_by_num(double num) const {
	Matrix matr;
	double* V = new double[this->columns * this->columns];
	for (int i = 0; i < this->columns * this->columns; i++) {
		V[i] = this->arr[i] * num;
	}
	matr.input(this->columns, V);
	return matr;
}

Matrix operator-(const Matrix& matr1) {
	return matr1.mult_by_num (-1.0);
}

Matrix operator*(const Matrix& matr1, double num) {
	return matr1.mult_by_num(num);
}

Matrix operator + (const Matrix& matr1, const Matrix& matr2) {
	return Matrix(matr1.sum(matr2));
}

Matrix operator - (const Matrix& matr1, const Matrix& matr2) {
	return Matrix(matr1.sum(-matr2));
}

Matrix operator * (const Matrix& matr1, const Matrix& matr2) {
	return Matrix(matr1.mult(matr2));
}

Matrix Matrix::operator += (Matrix matr2) {
	this->sum(matr2);
	return *this;
}

Matrix Matrix::operator -= (Matrix matr2) {
	return *this += -matr2;
}

std::ostream& operator << (std::ostream& out, Matrix matr) {
	out << matr.print();
	return out;
}

std::istream& operator >> (std::istream& in, Matrix matr) {
	in >> matr.columns;
	matr.input(matr.columns);
	return in;
}