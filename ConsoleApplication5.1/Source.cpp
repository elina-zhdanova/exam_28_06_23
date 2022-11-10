#include <iostream>
#include "Header.h"
using namespace std;

Matrix::Matrix()
{
}

Matrix::Matrix(int row, int col)
{
	size_col = col;
	size_row = row;
	elem = new double[row * col];
	for (int i = 0; i < col * row; i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(int size)
{
	size_col = size;
	size_row = size;
	elem = new double[size * size];
	for (int i = 0; i < size * size; i++)
	{
		elem[i] = 0;
	}
}

Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

Matrix::Matrix(const Matrix& temp)
{
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	this->elem = new double[(temp.size_col) * (temp.size_row)];
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = temp.elem[i];
	}
}

void Matrix::sum_matrix(const Matrix& temp) //сумма двух матриц
{
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = this->elem[i] + temp.elem[i];
	}
}

void Matrix::mult_by_num(double num) //умножение на число
{
	for (int i = 0; i < this->size_col * this->size_row; i++)
		this->elem[i] = this->elem[i] * num;
}

void Matrix::mult_matrix(const Matrix& temp) //умножения двух матриц
{
	if (this->size_col != temp.size_row) return *this;

	Matrix res(this->size_row, temp.size_col);

	for (int i=0; i<this->size_row;i++)
		for (int j = 0; j < temp.size_col; j++)
		{
			res.elem[i * res.size_col + j] = 0;
			for (int k = 0; k < this->size_col; k++)
				res.elem[i * res.size_col + j] += this->get_elem(i, k) * temp.get_elem(k, j);
		}

}

double Matrix::trace()
{
	double out = 0;
	for (int i = 0; i < this->size_col; i++) 
	{
		out += this->get_elem(i, i);
	}
	return out;
}