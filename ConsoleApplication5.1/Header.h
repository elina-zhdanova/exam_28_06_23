#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int size_row, size_col;
	double* elem;
public:
	Matrix(); // конструуктор по умолчанию
	Matrix(int row, int col); //конструктор задает размер матрицы
	Matrix(int size);
	Matrix(const Matrix& temp); //конструктор копирования
	~Matrix(); // деструктор

	void sum_matrix(const Matrix& temp); // сложения матриц

	void mult_matrix(const Matrix& temp); //умножения двух матриц

	double trace(); //след матрицы(сумма диагональных элементов квадратной матрицы)

	double det(); //определитель матрицы(для квадратных)

	void mult_by_num(double num); //умножение матрицы на число

	void input() //ввести матрицу с клавиатуры
	{
		int k = 0;
		cout << "Размеры данного массива " << this->size_row << "x" << this->size_col << "." << endl;
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < this->size_col; j++) {
				elem[k] << " ";
				k++;
			}
		}
		cout << endl;
	}

	void print() //печать матрицы в консоль
	{
		int k = 0;
		for (int i = 0; i < size_col; i++)
			for (int j = 0; j < size_row; j++)
			{
				cout << elem[k] << " ";
				k++;
			}
		cout << endl;
	}

	int get_columns() { return size_col; }//количество столбцов

	int get_rows() { return size_row; }//количество строк

	double get_elem(int i, int j) const { return elem[i * size_col + j]; }	//вернуть(i, j) элемент


};