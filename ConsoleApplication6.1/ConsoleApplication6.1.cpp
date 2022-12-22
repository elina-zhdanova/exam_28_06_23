#include <stack>
#include <iostream>
using namespace std;


bool check(string str)
{
    stack <char> stek; //создание стека
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' or str[i] == '{' or str[i] == '[')
        {
            stek.push(str[i]);//добавили символ в стек
        }
        
        if (str[i] == '}') {
            if (stek.empty() == 1) return 0;
            if ('{' == stek.top()) stek.pop();
            else return 0;
        }
        if (str[i] == ')') {
            if ('(' == stek.top()) stek.pop();
            else return 0;
        }
        if (str[i] == ']') {
            if ('[' == stek.top()) stek.pop();
            else return 0;
        }
    }
    if (stek.empty()==1) return 1;
    else return 0;
}
//2+4-5(87192479_7348){72648]76823[] - 0


int main()
{
    string str;
    cin >> str;
    cout << check(str);
}


