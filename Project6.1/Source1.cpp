#include <iostream>
#include <stack>
#include "Stack.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

bool checkSym(char sym1, char sym2) {
	switch (sym1) {
	case '[':
		return ']' == sym2;
	case '(':
		return ')' == sym2;
	case '{':
		return '}' == sym2;
	default:
		return false;
	}
}

template <class T>
bool check(string s) {
	T st;
	for (char sym : s) {
		if (sym == '(' || sym == '[' || sym == '{') st.push(sym);
		else if (sym == ')' || sym == ']' || sym == '}') {
			if (!st.empty() && checkSym(st.top(), sym)) st.pop();
			else return false;
		}
	}
	if (!st.empty()) {
		while (!st.empty()) st.pop();
		return false;
	}
	return true;
}

int main() {
	system("chcp 65001 > nul");
	int option;
	string s;
	while (true) {
		cout << "�������� ��������:\n"
			<< "1. ������ ������\n"
			<< "2. ������� ������\n"
			<< "3. ��������� ������ �� ������������ ���������� ������� �����\n"
			<< "4. ��������� ������ �� ������������ ����������� ������� �����\n"
			<< "5. �����\n"
			<< "��� �����: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "������� ������: ";
			cin >> s;
			break;
		case 2:
			cout << "������: " << s << endl;
			break;
		case 3:
			if (check<std::stack<char>>(s)) cout << "������ � ������ ����������� �����\n";
			else cout << "������ � ������ ����������� �������\n";
			break;
		case 4:
			if (check<Stack<char>>(s)) cout << "������ � ������ ����������� �����\n";
			else cout << "������ � ������ ����������� �������\n";
			break;
		case 5:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}