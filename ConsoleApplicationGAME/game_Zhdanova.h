#pragma once
#include <iostream>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()
#include <vector>
using namespace std;

class game_Zhdanova
{
private:
	int kol;
	struct Player_stats {
		string name;
		int gold = 0, tree = 0, rock, tokens, cube1, cube2, cube3, dop_cube;
		vector <string> buildings;
		int military_power = 0;
		int win_socker = 0;
	};

	vector<pair<string, string>> advisors;
	int year;
	int phase;
	char enemy; // враг может быть и структура
	vector <Player_stats> list;
	int rand_g();

public:

	game_Zhdanova();
	game_Zhdanova(const game_Zhdanova& temp);
	~game_Zhdanova();
	game_Zhdanova(int kol);
	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void defense_level(char enemy_name, int king_help);
};