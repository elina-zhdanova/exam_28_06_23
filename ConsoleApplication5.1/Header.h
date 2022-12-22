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
	Matrix(); // ������������ �� ���������
	Matrix(int row, int col); //����������� ������ ������ �������
	Matrix(int size);
	Matrix(const Matrix& temp); //����������� �����������
	~Matrix(); // ����������

	void sum_matrix(const Matrix& temp); // �������� ������

	Matrix mult_matrix(const Matrix& temp); //��������� ���� ������

	double trace(); //���� �������(����� ������������ ��������� ���������� �������)

	void mult_by_num(double num); //��������� ������� �� �����

	void input(int col, int row) //������ ������� � ����������
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

	void print() //������ ������� � �������
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

	int get_columns() { return size_col; }//���������� ��������

	int get_rows() { return size_row; }//���������� �����

	double get_elem(int i, int j) const { return elem[i * size_col + j]; }	//�������(i, j) �������


};