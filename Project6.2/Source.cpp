#include <iostream>
#include <deque>

using std::string;
using std::cout;
using std::cin;
using std::endl;

void z1() {
	std::deque<char> deq;
	string s;
	bool f = true;
	int n;
	cout << "Введите строку: ";
	system("chcp 1251>nul");
	cin >> s;
	system("chcp 65001 > nul");
	for (char c : s) deq.push_front(c);
	n = deq.size() / 2;
	for (int i = 0; i < n; i++) {
		if (deq.back() != deq.front()) {
			f = false;
			deq.pop_back();
			deq.pop_front();
		}
	}
	cout << "Строка " << (f ? "" : "не ") << "является палиндромом\n";
}

struct _coords { double x; double y; };

double rotate(_coords A, _coords B, _coords C)
{
	return (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
}

void sort(_coords* A, std::deque<int>& P) {
	int temp, j;
	for (int i = 2; i < P.size(); i++) {
		j = i;
		while (j > 1 && rotate(A[P[0]], A[P[j - 1]], A[P[j]]) < 0) {
			temp = P[j];
			P[j] = P[j - 1];
			P[j - 1] = temp;
			j--;
		}
	}
}

void z2() {
	_coords* coords;
	int n, min;
	double x, y;
	std::deque<int> P, S;
	cout << "Введите количество точек: ";
	cin >> n;
	coords = new _coords[n];
	for (int i = 0; i < n; i++) {
		cout << "Введите координаты " << i + 1 << "-ой точки (через пробел): ";
		cin >> x >> y;
		coords[i].x = x;
		coords[i].y = y;
	}
	min = 0;
	for (int i = 1; i < n; i++) if (coords[min].x > coords[i].x) min = i;
	P.push_back(min);
	for (int i = 0; i < n; i++) if (i != min) P.push_back(i);
	sort(coords, P);
	S.push_back(P[0]);
	S.push_back(P[1]);
	for (int i = 2; i < P.size(); i++) {
		while (rotate(coords[S[S.size() - 2]], coords[S[S.size() - 1]], coords[P[i]]) < 0)
			S.pop_back();
		S.push_back(P[i]);
	}
	for (auto x : S) {
		cout << coords[x].x << "; " << coords[x].y << endl;
	}
}

int main() {
	system("chcp 65001 > nul");
	int option;
	while (true) {
		cout << "Выберите действие:\n"
			<< "1. Проверка на палиндром\n"
			<< "2. Алгоритм Грэхема\n"
			<< "3. Выход\n"
			<< "Ваш выбор: ";
		cin >> option;
		switch (option) {
		case 1:
			z1();
			break;
		case 2:
			z2();
			break;
		case 3:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
