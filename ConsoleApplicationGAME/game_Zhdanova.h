#pragma once
#include <iostream>
#include <vector>
using namespace std;

class game_Zhdanova
{
private:
	int kol;
	struct Player_stats 
	{
		string name;
		int gold, tree, rock, tokens, cube1, cube2, cube3, dop_cube;
		vector <string> buildings;
		int military_power=0;
		int win_socker=0;
	};

	vector<pair<string,string>> advisors;
	int year;
	int phase;
	string enemy; // враг может быть и структура пока не понял 
	vector <Player_stats> list;

public:

	game_Zhdanova();
	game_Zhdanova(const game_Zhdanova& game);
	~game_Zhdanova();
	game_Zhdanova(int kol);
	void phase1();
	void phase3();
	void phase5();
	void phase7();
	void phase9();
	void defense_level(const char* enemy_name, int king_help, SomeDataStructForPlaye r& player);
};