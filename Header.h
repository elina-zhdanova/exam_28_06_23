#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int size_row, size_col;
	double* elem;
public:
	Matrix(); // ������������ �� ���������
	Matrix(int row, int col); //����������� ������ ������ �������
	Matrix(int size);
	Matrix(const Matrix& temp); //����������� �����������
	~Matrix(); // ����������

	void sum_matrix(const Matrix& temp); // �������� ������

	void mult_matrix(const Matrix& temp); //��������� ���� ������

	double trace(); //���� �������(����� ������������ ��������� ���������� �������)

	double det(); //������������ �������(��� ����������)

	void mult_by_num(double num); //��������� ������� �� �����

	void input() //������ ������� � ����������
	{
		int k = 0;
		cout << "������� ������� ������� " << this->size_row << "x" << this->size_col << "." << endl;
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < this->size_col; j++) {
				elem[k] << " ";
				k++;
			}
		}
		cout << endl;
	}

	void print() //������ ������� � �������
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

	int get_columns() { return size_col; }//���������� ��������

	int get_rows() { return size_row; }//���������� �����

	double get_elem(int i, int j) const { return elem[i * size_col + j]; }	//�������(i, j) �������


};