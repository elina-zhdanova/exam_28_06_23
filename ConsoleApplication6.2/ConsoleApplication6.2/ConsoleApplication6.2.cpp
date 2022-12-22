#include <deque>
#include <iostream>
using namespace std;
#include <string>

bool pal(string str)
{
    deque <char> pol;
    bool flag = true;
    for (int i = 0; i < str.length(); i++) str[i] = tolower(str[i]);
    for (int i = 0; i < str.length(); i++) pol.push_back(str[i]);
    for (int i = 0; i < (str.length())/2; i++)
    {
        
        if (pol.back() == pol.front())
        {
            flag = true;
            pol.pop_front();
            pol.pop_back();
        }
        else return 0;

    }
    return 1;
}


int main()
{
    string str;
    getline(cin, str);
    cout << pal(str);
    return 0;
}
