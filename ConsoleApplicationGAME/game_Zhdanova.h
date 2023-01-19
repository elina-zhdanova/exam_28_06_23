#pragma once
#include <iostream>
#include <stdlib.h> // нужен для вызова функций rand(), srand()
#include <time.h> // нужен для вызова функции time()
#include <vector>
using namespace std;
bool save_game();
bool game_load();
class game_Zhdanova
{
private:

	int kol;
	struct Player_stats {
		string name;
		int gold, tree, rock, tokens, cube1, cube2, cube3, dop_cube;
		vector <string> buildings_use;
		int military_power = 0;
		int win_socker = 0;
	};
	vector<string> advisors_name = { "jester", "squire","architect", "merchant", "sergeant" };
	vector<pair<string, string>> advisors_use;
	vector<string> bildings = { "Palisad", "stone walls" };

	char enemy; // враг может быть и структура
	vector <Player_stats> list;
	int rand_g();

public:
	bool save_game();
	bool game_load();
	int year;
	int phase = 1;
	game_Zhdanova();
	game_Zhdanova(const game_Zhdanova& temp);
	~game_Zhdanova();
	game_Zhdanova(int kol);
	void phase246_bones();
	void building(int player);
	void phase246_advisor();
	void advisor_help(string name, int player);
	void phase1();
	void phase246();
	void phase3();
	void phase5();
	void phase7();
	void phase8();
	void defense_level(char enemy_name, int king_help);
};