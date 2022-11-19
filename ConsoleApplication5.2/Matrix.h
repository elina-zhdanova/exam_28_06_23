#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int cols, row;
	double* arrg;
	void resize(int i, int j);
public:
	Matrix(); // конструуктор по умолчанию
	Matrix(int i, int j); //конструктор задает размер матрицы
	Matrix(int size);
	Matrix(const Matrix& temp); //конструктор копировани€
	~Matrix(); // деструктор

	Matrix(int i, int j, const double* arr); //констуктор, i - количество строк, j - количество столбцов, элементы определ€ютс€ массивом arr;

	Matrix sum(const double* arr);
	Matrix sum(const double* arr, int size); //сложени€ матриц, результат возвращаетс€ или записываетс€ в текущую матрицу соответственно;

	Matrix mult(const double* arr);
	Matrix mult(const double* arr, int size); //умножени€ двух матриц, результат возвращаетс€ или записываетс€ в текущую матрицу соответственно;

	void input(int i, int j); //ввести матрицу с клавиатуры c заданными размерами, i - количество строк, j - количество столбцов;

	void input(int i, int j, double* arr); //инициализировать матрицу заданным массивом arr, i - количество строк, j - количество столбцов.
};