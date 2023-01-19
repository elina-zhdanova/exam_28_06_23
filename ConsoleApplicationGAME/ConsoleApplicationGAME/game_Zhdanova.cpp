#include "game_Zhdanova.h"
#include<algorithm>
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

game_Zhdanova::~game_Zhdanova()
{
}

void game_Zhdanova::building(int player)
{
    int choice;
    cout << "�������� ������ �� ������ ���������\n";
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

    phase246_advisor();
    advisor_help();
    building();

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
    int choice = 0;
    int vsego = 0;
    int voins = 0;
    int k = 0;
    for (int i = 0; i < kol; i++)
    {
        vsego = list[i].tree + list[i].rock + list[i].gold;
        cout << "�����" << i + 1 << "������ �� �� ������ �����?\n ���������� �������� " << vsego << "1.��\n 2.���\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "������� ������ �� ������ ������?";
            cin >> voins;
            for (int i = 0; i < voins; i++) {
                k = 2;
                if (vsego >= 2)
                {
                    list[i].military_power += 1;
                    vsego -= 2;
                    while (k > 0)
                    {
                        cout << "�����" << i + 1 << "�������� ����� ������� ������ ����� �� ������\n 1.������\n 2.������\n 3.������\n";
                        cin >> choice;
                        switch (choice)
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
        case 2:
        {

            break;
        }
                }
            }
        }
        vsego = 0;
        }
    }
}

void game_Zhdanova::advisor_help()
{
    int j;
}