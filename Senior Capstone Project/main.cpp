


#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>
#include <thread>
#include "Header.h"


using namespace std;
int main(void) {
	srand(time(NULL));
	Player Player;
	Player.character_name = " ";
	Player.health = 110;
	Player.strength = 0;
	Player.dexterity = 0;
	Player.constitution = 0;
	Player.agility = 0;
	Player.luck = 0;
	Player.experience = 0;
	Player.level = 1;
	Player.dodge = 5;
	Player.defense = 1;
	Player.damage = 4;
	Player.finishgame = false;
	Player.potions = 2;
	Player.kills = 0;
	Player.healthmax = 100;
	Player.alive = true;
	Player::Monster Monster;
	Monster.name = "";
	Monster.health = 0;
	Monster.damage = 0;
	Monster.speed = 0;
	Monster.defense = 0;
	Monster.maxhealth = 0;




	int start_menu_input = 0;
	bool start_game = false;


	bool F1 = false;


	do {
		int start_menu_input = 0;
		start_menu(start_menu_input);
		if (start_menu_input == 2) {

			return (0);

		}
		else if (start_menu_input == 1) {
			start_game = true;
			cout << "\n\n\n\n\n\n\n\n\n\n\n**************************************************************\n";
			cout << "\n\nHello?  Are you awake?  Good.  It's morning, which means it's time to enter.\n";
			cout << "By the way, I never caught your name?\n\n\n\n\n";
			Player.get_name(Player);
			cout << "I must say, you are very brave to attempt this dungeon.  Many heroes have tried and never returned.\n";
			Player.get_attributes(Player);
			Player.healthmax = 100 + (Player.level * 10) + (Player.constitution * 10);
			Player.health = Player.healthmax;
			cout << "Goodbye " << Player.character_name << ", and good luck!  *You'll need it.*\n\n\n";
			system("pause");
			cout << "\n\n\n\n\n\n                     THE DUNGEON                                \n\n";
			cout << "*****************************************************************\n\n";
			do {
				int p = 0;
				Player.damage = 4 + Player.level + Player.strength;
				Player.defense = 1 + Player.defense;
				Player.healthmax = 100 + (Player.level * 10) + (Player.constitution * 10);
				Player.dodge = 0;
				for (int i = 0; i < (Player.agility+1); i++) {
					Player.dodge = Player.dodge + (pow((450 / (Player.agility + 1)), 0.27));
				}
				cout << "\n\n\n\n\n\n";
				cout << "\nLevel == " << Player.level << "\n\n";
				cout << "Progress to next level == " << Player.experience << "/" << (Player.level / 0.07) * (Player.level / 0.07) << "\n\n";
				Monster.encounter(Player, Monster);
				if (Player.alive == false) {
					cout << "GAME OVER.  You have been slain by the " << Monster.name << "\n\n\n";
					cout << "Score = " << Player.kills << "/50\n\n\n\n\n";
					return(0);
				}
				if (Player.finishgame == true) {
					cout << "By some miraculous twist of fate, you have somehow managed to slay the terrifying beast.\n";
					cout << "You are left broken and battered, but you are alive, and stand over a titanic corpse.\n";
					cout << "On the other side, however, you see heaps of treasure!  You did it, you were the first person\n";
					cout << "to ever defeat the dungeon, and now you have riches for life.  Congratulations " << Player.character_name << ", you win!!\n";
					cout << "Score = 100/50\n\n\n\n";
					return(0);
				}
				Player.levelup(Player);
				cout << "\n\n\nAfter defeating the beast, you find yourself in a small room with 3 passages.  Which do you choose to enter?\n\n\n";
				cout << "1) Left passage\n";
				cout << "2) Forward passage\n";
				cout << "3) Right passage\n";
				cin >> p;
				if (p == 1 || p == 2 || p == 3) {

				}
				else {
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					p = 0;
					cout << "Invalid input, please try again\n";
				}
			} while (Player.finishgame == false);
		}
			else {
				cout << "\n\n\n\n\nInvalid input, please try again.\n\n\n\n\n";
			}
		}
		while (start_game == false);




	return (0);
}
