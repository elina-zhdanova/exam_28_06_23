#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string word;
    int k =0 ;
    map<string, int> mm;
    while (cin >> word) // конец ввода ctrl^z потом enter
    {
        mm[word]++; // считаем слова
        k++; //всего слов
    }

    map<string, int>::iterator it; //явный итератор 
    for (it = mm.begin(); it != mm.end(); ++it) 
        cout << it->first << ':' << double (it->second)/k * 100 << endl;//first-обращение к ключу[word],
    //second-обращаемся к ячейке(к количеству 
    //повторяющихся слов mm
    //преобразуем в double ибо второе число целое, а нам нужны проценты, поделится криво
    system("pause");
    return 0;
}
