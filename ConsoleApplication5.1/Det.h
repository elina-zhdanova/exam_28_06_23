#pragma once
//#ifndef Det_H//#ifndef ��������� ��������� ������� ���������������� �������, �������������� #ifdef
//���� ������������� �� ��� ��������� ��� ��� ����������� ���� ������� � �������, ������� ����� �������� true (�������� �� #undef ����)
//� ��������� ������ ������� �� ����������� (false, �������� ����� 0).
#define Det_H
//#define � ������ ������ ���������� ����������, ���� ���� ������������ �������.
#define elem(t, x, y, n) t[(x)*(n)+(y)]

void free_memory(double* matr);

double* create(double* matr, int n, int iskI, int iskJ);

double det_Minors(double* matr, int n);

//#endif
//��������� #ifndef ... #endif ������� ��� ����, ��� �� ������������� ������������ ��������� ������������� �����