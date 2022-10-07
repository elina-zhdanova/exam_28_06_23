#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <bitset>
using namespace std;

int main()
{
    std::cout << "Zhdanova Elina Gazizovna 221-351"<<endl;
   
   std::cout << "min int = " << INT_MIN << ", max int = " << INT_MAX << ", size of int = " << sizeof(int) << std::endl;
    std::cout << "min unsigned int = 0" << ", max unsigned int = " << UINT_MAX << ", size of unsigned int = " << sizeof(unsigned int) << std::endl;
    std::cout << "min short = " << SHRT_MIN << ", max short = " << SHRT_MAX << ", size of short = " << sizeof(short) << std::endl;
    std::cout << "min unsigned short = 0"<< ", max unsigned short = " << USHRT_MAX << ", size of unsigned short = " << sizeof(unsigned short) << std::endl;
    std::cout << "min long = " << LONG_MIN << ", max long = " << LONG_MAX << ", size of  long = " << sizeof(long) << std::endl;
    std::cout << "min unsigned long = 0"<< ", max unsigned long = " << ULONG_MAX << ", size of unsigned long = " << sizeof(unsigned long) << std::endl;
    std::cout << "min long long = " << LLONG_MIN << ", max long long = " << LLONG_MAX << ", size of long long = " << sizeof(long long) << std::endl;
    std::cout << "min unsigned long long = 0" << ", max unsigned long long = " << ULONG_MAX << ", size of unsigned long long = " << sizeof(unsigned long long) << std::endl;
    std::cout << "min char = " << CHAR_MIN << ", max char = " << CHAR_MAX << ", size of char = " << sizeof(char) << std::endl;
    std::cout << "min unsigned char = 0"<< ", max unsigned char = " << UCHAR_MAX << ", size of unsigned char = " << sizeof(unsigned char) << std::endl;
    std::cout << "min double = " << DBL_MIN << ", max double = " << DBL_MAX << ", size of double = " << sizeof(double) << std::endl;
    std::cout << "min bool = 0"<< ", max bool = 1" << ", size of bool = " << sizeof(bool) << std::endl;
    std::cout << "min float = " << FLT_MIN<<", max float = " << FLT_MAX<<", size of float = " << sizeof(float) << std::endl;

    int a, b;
    cout << "Enter the coordinates of the segment on the line: ";
    cin >> a >> b;
    cout << "The middle of the segment is at the point with the coordinate: " << float(a + b) / 2 << endl; 

    int a1, b1;
    cout << "Enter the coefficients a * x = b: ";
    cin >> a1>>b1;
    cout << a1 << " * x = " << b1 << endl;
    cout << "x = " << b1 << " / " << a1 << endl;
    cout << "x = " << double(b1) / a1 << endl;
    cout << "Answer: " << double(b1) / a1 << endl;

    int n;
    cin >> n;
    cout<<"v 16 ss "<<hex << n << dec << endl;
    cout<<"bin "<<bitset<8 * sizeof(n)>(n) << endl;
    cout <<"bool "<< bool(n) << endl;
    cout << "char "<<char(n) << endl;
    cout << "double "<<double(n) << endl;
}
