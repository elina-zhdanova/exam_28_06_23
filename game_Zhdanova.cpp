#include "game_Zhdanova.h"
#include<algorithm>
#include <fstream>
using namespace std;

int game_Zhdanova::rand_g()
{
	int min = 1, max = 6;
	srand(time(NULL));
	return  (min + rand() % (max - min + 1));
}


game_Zhdanova::game_Zhdanova()
{
}

game_Zhdanova::game_Zhdanova(const game_Zhdanova& temp)
{
	string name;
	for (int i = 0; i < kol; i++) {
		this->list[i].name = temp.list[i].name;
	}
}

game_Zhdanova::game_Zhdanova(int kol)
{
	this->kol = kol;
	string name;
	list.resize(kol);
	for (int i = 0; i < kol; i++) {
		cout << "������� ��� ������\n";
		cin >> name;
		list[i].name = name;
	}
	this->year = 0;
}

void game_Zhdanova::phase246_bones()
{
	vector<int> m;
	m.resize(5);
	cout << "������ ������� ��� ��������� ������� �������\n";
	for (int i = 0; i < kol; i++) {
		list[i].cube1 = rand_g();
		list[i].cube2 = rand_g();
		list[i].cube3 = rand_g();
		cout << "����� " << i + 1 << " ������ ��� ������ ������ " << list[i].cube1 + list[i].cube2 + list[i].cube3 << "\n";
		m[i] = list[i].cube1 + list[i].cube2 + list[i].cube3;
	}
	cout << "��������� ������� ����\n";
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5 - (i + 1); j++) {
			if (m[j] > m[j + 1]) {
				flag = false;
				swap(m[j], m[j + 1]);
				swap(list[j], list[j + 1]);
			}
		}
		if (flag) {
			break;
		}
	}
	cout << "����� ������� ����\n";
	for (int i = 0; i < 5; i++) {
		cout << list[i].name << " ";
	}
	cout << "\n";
}

game_Zhdanova::~game_Zhdanova()
{
}

void game_Zhdanova::building(int player)
{
	int choice;
	cout << "�����" << list[player].name << " �������� ������ �� ������ ���������\n";
	for (int i = 1; i <= bildings.size(); i++) {
		cout << i << " " << bildings[i] << "\n";
	}
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		list[player].buildings_use.push_back(bildings[1]);
		list[player].military_power += 1;
		break;
	}
	case 2:
	{
		list[player].buildings_use.push_back(bildings[2]);// �������� ����� ����������� ��� ��� ��� ������ ���� �� ��������.
		break;
	}
	}
}
void game_Zhdanova::phase246_advisor()
{
	for (int i = 0; i < kol; i++) {
		//advisor_help(name, i); ��� ������������� ���������� �� ���� ������ ���������� 
	}
}

void game_Zhdanova::advisor_help(string name, int player)
{
	int chouse;
	for (int j = 0; j < advisors_name.size(); j++) {
		if (name == advisors_name[j])
			chouse = j;
		break;
	}

	switch (chouse) {

	case 1:
	{
		advisors_use.push_back(make_pair(name, list[player].name));

		list[player].win_socker += 1;
		break;
	}
	case 2:
	{
		advisors_use.push_back(make_pair(name, list[player].name));

		list[player].gold += 1;
		break;
	}
	case 3:
	{
		advisors_use.push_back(make_pair(name, list[player].name));

		list[player].tree += 1;
		break;
	}
	case 4:
	{
		advisors_use.push_back(make_pair(name, list[player].name));
		cout << "����� �������� ������\n 1.������ 2.������\n";
		int t;
		cin >> t;
		if (t == 1) {
			list[player].gold += 1;
		}
		else
		{
			list[player].tree += 1;
		}
		break;
	}
	case 5:
	{
		advisors_use.push_back(make_pair(name, list[player].name));

		list[player].military_power += 1;
		break;
	}
	}

}
void game_Zhdanova::phase1()
{
	int choice = 0;
	int mini = 1000000;
	int vsego_min = 100000;
	if (year == 1) {
		for (int i = 0; i < kol; i++)
		{
			cout << "�����" << i + 1 << "�������� ����� ������� ��������\n 1.������\n 2.������\n 3.������\n";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				list[i].tree += 1;
				break;
			}
			case 2:
			{
				list[i].rock += 1;
				break;
			}
			case 3:
			{
				list[i].gold += 1;
				break;
			}
			}
		}
	}
	else {
		for (int i = 0; i < kol; i++) {
			if (list[i].buildings_use.size() < mini) {
				mini = list[i].buildings_use.size();
				vsego_min = list[i].tree + list[i].rock + list[i].gold;
			}
		}
		for (int i = 0; i < kol; i++) {
			if (list[i].buildings_use.size() == mini and (list[i].tree + list[i].rock + list[i].gold) == vsego_min) {
				cout << "����� " << i + 1 << " �������� ����� ������� ��������\n 1.������\n 2.������\n 3.������\n";
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					list[i].tree += 1;
					break;
				}
				case 2:
				{
					list[i].rock += 1;
					break;
				}
				case 3:
				{
					list[i].gold += 1;
					break;
				}
				}
			}
		}
	}
}

void game_Zhdanova::phase246()
{
	phase246_bones();
	phase246_advisor();

	for (int i = 0; i < 5; i++) {
		building(i);
	}

}

void game_Zhdanova::phase3()
{
	int maxi = -1;

	for (int i = 0; i < kol; i++) {
		if (list[i].buildings_use.size() > maxi) {
			maxi = list[i].buildings_use.size();
		}
	}
	for (int i = 0; i < kol; i++) {
		if (list[i].buildings_use.size() == maxi) {
			list[i].win_socker += 1;
			cout << "����� " << i + 1 << " �������� ���� ������";
		}
	}
}

void game_Zhdanova::phase5()
{

}

void game_Zhdanova::phase7()
{
	int choice = 0, foo = 0;
	int vsego = 0;
	int voins = 0;
	int k = 0;
	for (int i = 0; i < kol; i++)
	{
		vsego = list[i].tree + list[i].rock + list[i].gold;
		cout << " ����� " << i + 1 << " ������ �� �� ������ �����?\n ���������� �������� " << vsego << " 1.��\n 2.���\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������� ������ �� ������ ������?";
			cin >> voins;
			for (int j = 0; j < voins; j++) {
				k = 2;
				if (vsego >= 2)
				{
					list[i].military_power += 1;
					vsego -= 2;
					while (k > 0)
					{
						cout << "�����" << i + 1 << " �������� ����� ������� ������ ����� �� ������\n 1.������\n 2.������\n 3.������\n";
						cin >> foo;
						switch (foo)
						{
						case 1:
						{
							if (list[i].tree > 0) {
								list[i].tree -= 1;
								k -= 1;
							}
							else
							{
								cout << "� ��� ��� ����� �������\n";
							}
							break;
						}
						case 2:
						{
							if (list[i].rock > 0) {
								list[i].rock -= 1;
								k -= 1;
							}
							else
							{
								cout << "� ��� ��� ����� �������\n";
							}
							break;
						}
						case 3:
						{
							if (list[i].gold > 0) {
								list[i].gold -= 1;
								k -= 1;
							}
							else
							{
								cout << "� ��� ��� ����� �������\n";
							}
							break;
						}
						}
					}
				}
			}
		}
		case 2:
		{

			break;
		}


		}
		vsego = 0;
	}
}
void game_Zhdanova::phase8()
{
	int win_kol = 0;
	int win_playr[5]{ 0 };
	for (int i = 0; i < kol; i++) {
		defense_level(enemy, rand_g());
	}
	if (year == 5) {
		int maxi = -1;
		for (int i = 0; i < kol; i++) {
			if (list[i].win_socker > maxi) {
				maxi = list[i].win_socker;
			}
		}
		for (int i = 0; i < kol; i++) {
			if (list[i].win_socker == maxi) {
				win_kol += 1;
				win_playr[i] = i + 1;

			}
		}
		for (int i = 0; i < kol; i++) {
			if (list[i].win_socker == maxi) {
				cout << "������� �����" << i + 1 << "\n";
			}
		}
	}
	year += 1;
}


void game_Zhdanova::defense_level(char enemy_name, int king_help)
{
}

bool game_Zhdanova::save_game()
{
	ofstream file("data_save.txt");
	if (file.is_open()) {

		file << year << " " << phase;
		for (int i = 0; i < kol; i++) {
			file << list[i].name << list[i].military_power << list[i].gold << list[i].tree << list[i].rock << list[i].tokens << list[i].win_socker;
			if (list[i].buildings_use.size() > 0)
				for (int j = 0; j < list[i].buildings_use.size(); j++)
					file << list[i].buildings_use[j];
		}
		for (int i = 0; i < advisors_use.size(); i++) {
			file << advisors_use[i].first << advisors_use[i].second;
		}
		return true;
	}
	else
	{
		return false;
	}