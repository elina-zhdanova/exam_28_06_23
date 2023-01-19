#include <iostream>
#include"game_Zhdanova.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int kol;
	int t;
	cout << "Напишите количество игроков больше одного";
	cin >> kol;
	game_Zhdanova game(kol);
	while (game.year < 5)
	{
		game.phase1();
		game.phase += 1;
		game.phase246();
		game.phase += 1;
		cout << "Не желаете сохраниться\n 1.ДА 2.Нет\n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			save_game();
			break;
		}
		case 2:
		{
			break;
		}
		}

		game.phase3();
		game.phase += 1;
		game.phase246();
		game.phase += 1;
		cout << "Не желаете сохраниться\n 1.ДА 2.Нет\n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			save_game();
			break;
		}
		case 2:
		{
			break;
		}
		}
		game.phase5();
		game.phase += 1;
		game.phase246();
		game.phase += 1;
		cout << "Не желаете сохраниться\n 1.ДА 2.Нет\n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			save_game();
			break;
		}
		case 2:
		{
			break;
		}
		}
		game.phase7();
		game.phase += 1;
		game.phase8();
		game.phase = 0;
		cout << "Не желаете сохраниться\n 1.ДА 2.Нет\n";
		cin >> t;
		switch (t)
		{
		case 1:
		{
			save_game();
			break;
		}
		case 2:
		{
			break;
		}
		}
	}

	return 0;
}
