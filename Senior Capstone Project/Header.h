#pragma once


#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;


class Player {
public:
	string character_name;
	double health;
	int strength;
	int dexterity;
	int constitution;
	double agility;
	int luck;
	double experience;
	int level;
	double dodge;
	int defense;
	int damage;
	bool finishgame;
	int potions;
	int kills;
	int healthmax;
	bool alive;
	void get_name(Player& Player);
	void get_attributes(Player& Player);
	void levelup(Player& Player);
	class Monster {
	public:
		string name;
		double damage;
		double defense;
		double health;
		int speed;
		int maxhealth;
		void encounter(Player& Player, Player::Monster& Monster);
	};

};




void start_menu(int& c);
void boss1();
void boss2();