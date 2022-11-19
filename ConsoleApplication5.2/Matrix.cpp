#include <iostream>
#include "Matrix.h"
using namespace std;

Matrix::Matrix()
{
	this->cols = 0;
	this->row = 0;
	this->arrg = nullptr;
}

Matrix::Matrix(int size)
{
	cols = size;
	row = size;
	arrg = new double[size * size];
	for (int i = 0; i < size * size; i++)
	{
		arrg[i] = 0;
	}
}


Matrix::Matrix(int i, int j)
{
	this->cols = i;
	this->row = j;
	this->arrg = new double[i * j];
	for (int k = 0; k < i * j; k++)
	{
		arrg[k] = 0;
	}
}


Matrix::Matrix(const Matrix& temp)
{
	this->cols = temp.cols;
	this->row = temp.row;
	this->arrg = new double[(temp.cols) * (temp.row)];
	for (int i = 0; i < temp.cols * temp.row; i++)
	{
		this->arrg[i] = temp.arrg[i];
	}
}

Matrix::~Matrix()
{
	if (arrg != nullptr)
		delete[]arrg;
}

Matrix::Matrix(int i, int j, const double* arr)
{
	if (arrg != nullptr)
		delete[]arrg;
	cols = i;
	row = j;
	arrg = new double[i * j];
	for (int k = 0; k < i * j; k++) 
		arrg[k] = arr[k];
}

void Matrix::resize(int i, int j)
{
	this->cols = i;
	this->row = j;
	if (this->arrg != nullptr) delete[] this->arrg;
	this->arrg = new double[this->row * this->cols];
}

void Matrix::input(int i, int j)
{
	this->resize(i, j);
	for (int k = 0; k < this->row * this->cols; k++)
		this->arrg[i] = (k * 123654 * k - 321231) % 29;
	//std::cin>> this->elem[i];
}

void Matrix::input(int i, int j, double* arr)
{
	this->resize(i, j);
	for (int i = 0; i < this->row * this->cols; i++)
		this->arrg[i] = arr[i];
}
