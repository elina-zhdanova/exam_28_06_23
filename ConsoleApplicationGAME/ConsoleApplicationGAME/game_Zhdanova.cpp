#include "game_Zhdanova.h"


game_Zhdanova::game_Zhdanova()
{
}

game_Zhdanova::game_Zhdanova(const game_Zhdanova& game)
{
    this->phase = game.phase;
    this->year = game.year;
    this->enemy = game.enemy;
    this->advisors = game.advisors;
    this->list = game.list;
}

game_Zhdanova::game_Zhdanova(int kol)
{
    this->kol = kol;
    string name;
    list.resize(kol);
    for (int i = 0; i < kol; i++) {
        cout << "������� ��� ������";
        cin >> name;
        list[i].name = name;
    }
    this->year = 1;
}

game_Zhdanova::~game_Zhdanova()
{
}


void game_Zhdanova::phase1()
{
    int choice = 0;
    for (int i = 0; i < kol; i++) 
    {
        cout << "�����" << i + 1 << "�������� ����� ������� ��������\n 1.������\n 2.������\n 3.������\n"; 
        cin >> choice;
        switch(choice)
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

void game_Zhdanova::phase3()
{
    int maxi = -1;

    for (int i = 0; i < kol; i++) {
        if (list[i].buildings.size() > maxi) {
            maxi = list[i].buildings.size();
        }
    }
    for (int i = 0; i < kol; i++) {
        if (list[i].buildings.size() == maxi and maxi == 0) {
            list[i].win_socker += 1;
        }
    }
}

void game_Zhdanova::phase7()
{
    int choice = 0;
    int voins = 0;
    
    for (int i = 0; i < kol; i++)
    {
        cout << "�����" << i + 1 << "������ �� �� ������ �����?\n 1.��\n 2.���\n";
        cin >> choice;
        int vsego = list[i].tree + list[i].rock + list[i].gold;
        switch (choice)
        {
        case 1:
        {
            cout << "������� ������ �� ������ ������?";
            cin >> voins;
            for (int j=0; j<=voins; j++)
            {
                
                if (vsego >= 2)
                {
                    list[i].military_power += 1;
                    vsego -= 2;
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