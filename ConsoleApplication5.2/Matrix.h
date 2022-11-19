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
	Matrix(); // ������������ �� ���������
	Matrix(int i, int j); //����������� ������ ������ �������
	Matrix(int size);
	Matrix(const Matrix& temp); //����������� �����������
	~Matrix(); // ����������

	Matrix(int i, int j, const double* arr); //����������, i - ���������� �����, j - ���������� ��������, �������� ������������ �������� arr;

	Matrix sum(const double* arr);
	Matrix sum(const double* arr, int size); //�������� ������, ��������� ������������ ��� ������������ � ������� ������� ��������������;

	Matrix mult(const double* arr);
	Matrix mult(const double* arr, int size); //��������� ���� ������, ��������� ������������ ��� ������������ � ������� ������� ��������������;

	void input(int i, int j); //������ ������� � ���������� c ��������� ���������, i - ���������� �����, j - ���������� ��������;

	void input(int i, int j, double* arr); //���������������� ������� �������� �������� arr, i - ���������� �����, j - ���������� ��������.
};