#pragma once
#define getElem(t,x, y) t->arr[(x)*t->columns+(y)] 
//^��� ���������, ������� ������� ���������, ���, ���� � ��� ����� �� ���� ��� ��� ���, ������� ���� ���������� �� ��������������(��� � �����)
//define-����������, �����, ��� ����� ����������� getElem, ��� ����� ����� ���������� �� t->arr[(x)*t->columns+(y)] 

class Matrix
{
private:
    int columns;
    int rows;
    double* arr;
public:
	Matrix();
	Matrix(int n, int m); //����������� ������ ������ �������
	Matrix(int n, int m, double* matr);
	~Matrix();// ���������� ��������� ������������ �������������� 
    //�������� �������� � �������� ������������� ���������� �������.
	void sum(const Matrix* mat2);
	void sum(const Matrix* mat2, int size);
	void mult(const Matrix* mat2);
	void mult(const double* matr, int n, int m);
	double trace();
	void mult_by_num(double num);
	void input();
	void input(int n, int m);
	void input(int n, int m, double* matr);
	void print();
	int get_columns() const;
	int get_rows() const;
	double get_elem(int i, int j) const;
};