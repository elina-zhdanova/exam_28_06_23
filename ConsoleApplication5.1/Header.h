#pragma once
#define getElem(t,x, y) t->arr[(x)*t->columns+(y)] 
//^это директива, которая говорит прцессору, мол, есть в нем какой то файл или еще что, которую надо подключить до компилирования(это в целом)
//define-определить, везде, где будет встречаться getElem, оно будет сразу заменяться на t->arr[(x)*t->columns+(y)] 

class Matrix
{
private:
    int columns;
    int rows;
    double* arr;
public:
    Matrix(int n, int m);//конструктор задает размер матрицы 

    Matrix(int n, int m, double* matr);
    ~Matrix(); // деструктор выполняет освобождение использованных 
    //объектом ресурсов и удаление нестатических переменных объекта.

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