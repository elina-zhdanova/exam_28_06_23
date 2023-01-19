#include "game_Zhdanova.h"


int game_Zhdanova::rand_g()
{
    int min = 1, max = 6;
    srand(time(NULL));
    return  (min + rand() % (max - min + 1));
}

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
        cout << "Введите Имя игрока";
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
        if (year = 1)
        {
            cout << "Игрок" << i + 1 << "выбирете товар который получите\n 1.Дерево\n 2.Камень\n 3.Золото\n";
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
    int vsego = 0;
    int voins = 0;
    int k = 0;
    for (int i = 0; i < kol; i++)
    {
        vsego = list[i].tree + list[i].rock + list[i].gold;
        cout << "Игрок" << i + 1 << "Хотите ли вы нанять воина?\n количество ресурсов " << vsego << "1.Да\n 2.Нет\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Сколько воинов вы хотите нанять?";
            cin >> voins;
            for (int i = 0; i < voins; i++) {
                k = 2;
                if (vsego >= 2)
                {
                    list[i].military_power += 1;
                    vsego -= 2;
                    while (k > 0)
                    {
                        cout << "Игрок" << i + 1 << "выбирете товар который хотите одать по одному\n 1.Дерево\n 2.Камень\n 3.Золото\n";
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
                                cout << "У вас нет этого ресурса\n";
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
                                cout << "У вас нет этого ресурса\n";
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
                                cout << "У вас нет этого ресурса\n";
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

void game_Zhdanova::phase8()
{
    int win_kol = 0;
    int win_playr[5]{ 0 };
    for (int i = 0; i < kol; i++) {
        defense_level(enemy, rand_g());
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
                if (list[i].win_socker == maxi and win_kol == 1) {
                    cout << "Победил игрок" << i + 1 << "\n";
                }
            }
        }
        year += 1;
    }
}