#include <iostream>
#include <deque>
#include <string>;
using namespace std;

void pal() 
{
	setlocale(LC_ALL, "Russian");
	deque <char> pol;
	bool f = true;
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++) str[i] = tolower(str[i]);
	for (int i = 0; i < str.length(); i++) pol.push_back(str[i]);
	for (int i = 0; i < (str.length()) / 2; i++)
	{

		if (pol.back() != pol.front()) {
			f = false;
			pol.pop_back();
			pol.pop_front();
		}

	}
	cout << "Строка " << (f ? "" : "не ") << "является палиндромом\n";
}


int main() 
{
	pal();
}
