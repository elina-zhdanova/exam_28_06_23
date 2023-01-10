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
    Matrix(int n, int m);//����������� ������ ������ ������� 

    Matrix(int n, int m, double* matr);
    ~Matrix(); // ���������� ��������� ������������ �������������� 
    //�������� �������� � �������� ������������� ���������� �������.

    void sum(const Matrix* mat2);
    void mult(const Matrix* mat2);
    double trace();
    double det();
    void mult_by_num(double num);
    void input();
    void print();
    int get_columns() const;
    int get_rows() const;
    double get_elem(int i, int j) const;
};