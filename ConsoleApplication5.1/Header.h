#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int size_row, size_col;
	double* elem;
	int i1, j1;
public:
	Matrix(); // конструуктор по умолчанию
	Matrix(int row, int col); //конструктор задает размер матрицы
	Matrix(int size);
	Matrix(const Matrix& temp); //конструктор копировани€
	~Matrix(); // деструктор

	void sum_matrix(const Matrix& temp); // сложени€ матриц

	Matrix mult_matrix(const Matrix& temp); //умножени€ двух матриц

	double trace(); //след матрицы(сумма диагональных элементов квадратной матрицы)

	void mult_by_num(double num); //умножение матрицы на число

	void input(int col, int row) //ввести матрицу с клавиатуры
	{
		i1 = 0;
		j1 = 0;
		if (elem != nullptr)
			delete[]elem;
		size_col = col;
		size_row = row;
		elem = new double[size_col * size_row];
		for (int i = 0; i < size_col * size_row; i++)
		{
			std::cin >> elem[i];
		}

	}

	void print() //печать матрицы в консоль
	{
		int k = 0;
		for (int i = 0; i < size_col; i++)
		{
			for (int j = 0; j < size_row; j++)
			{
				cout << elem[k] << " ";
				k++;
			}
			cout << endl;
		}
		cout << endl;
	}

	int get_columns() { return size_col; }//количество столбцов

	int get_rows() { return size_row; }//количество строк

	double get_elem(int i, int j) const { return elem[i * size_col + j]; }	//вернуть(i, j) элемент


};