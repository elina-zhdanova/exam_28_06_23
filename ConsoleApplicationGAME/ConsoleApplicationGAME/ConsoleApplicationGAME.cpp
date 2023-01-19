#include <iostream>
#include"game_Zhdanova.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int kol;
	cout << "Напишите количество игроков";
	cin >> kol;
	game_Zhdanova game(kol);
	while (game.year < 5)
	{
		game.phase1();
		game.phase3();
		game.phase5();
		game.phase7();
		game.phase8();
	}
	return 0;
}
