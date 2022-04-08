#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <math.h>
#include <chrono>
#include <thread>
#include "Header.h"


using namespace std;



void start_menu(int& c) {
	c = 0;
	cout << "                     THE DUNGEON\n";
	cout << "---------------------------------------------------------\n";
	cout << "---------------------------------------------------------\n";
	cout << "1) Start a new game\n";
	cout << "2) Exit the game\n";
	cin >> c;
	if (c >= 1 && c <= 2) {
	}
	else {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "\n";
		c = 0;
	}
}

void Player::get_name(Player& Player) {
	cout << "Please enter your name\n";
	cin >> Player.character_name;
	cout << "\n\nWell hello " << Player.character_name << "!  It's nice to meet you! *Although I'll probably never see you again...*\n";
}
void Player::get_attributes(Player& Player) {
	Player.strength = 0;
	Player.dexterity = 0;
	Player.constitution = 0;
	Player.agility = 0;
	Player.luck = 0;
	bool finish = false;
	do {
		int x = 20 - Player.strength - Player.dexterity - Player.constitution - Player.agility - Player.luck;
		int y = 0;
		cout << "What are your skills, brave warrior?\n\n";
		cout << "You have " << x << " skill points left to distribute. Choose which skill to add or remove points from.\n\n";
		cout << "1) Strength (Affects damage) " << Player.strength << " points currently in Strength.\n";
		cout << "2) Dexterity (Affects defense) " << Player.dexterity << " points currently in Dexterity.\n";
		cout << "3) Constitution (Affects total health) " << Player.constitution << " points currently in Constitution.\n";
		cout << "4) Agility (Affects chance to dodge) " << Player.agility << " points currently in Agility.\n";
		cout << "5) Luck (Affects loot from chests and experience gain) " << Player.luck << " points currently in Luck.\n";
		cout << "6) Finish distributing attributes\n";
		cin >> y;
		if (y == 1) {
			cout << "How many points would you like to put into Strength?\n\n";
			cin >> Player.strength;
			cout << "\n\n";
			if (Player.strength < 0) {
				cout << "You cannot enter a negative value. Try again.\n\n\n";
				Player.strength = 0;
			}
			else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > 20) {
				cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
				Player.strength = 0;
			}
			else if (Player.strength >= 0 || Player.strength <= 20) {
				cout << "Strength has been set to " << Player.strength << ".\n\n\n";
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				Player.strength = 0;
			}
		}
		else if (y == 2) {
			cout << "How many points would you like to put into Dexterity?\n\n";
			cin >> Player.dexterity;
			cout << "\n\n";
			if (Player.dexterity < 0) {
				cout << "You cannot enter a negative value. Try again.\n\n\n";
				Player.dexterity = 0;
			}
			else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > 20) {
				cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
				Player.dexterity = 0;
			}
			else if (Player.dexterity >= 0 || Player.dexterity <= 20) {
				cout << "Dexterity has been set to " << Player.dexterity << ".\n\n\n";
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				Player.dexterity = 0;
			}
		}
		else if (y == 3) {
			cout << "How many points would you like to put into Constitution?\n\n";
			cin >> Player.constitution;
			cout << "\n\n";
			if (Player.constitution < 0) {
				cout << "You cannot enter a negative value. Try again.\n\n\n";
				Player.constitution = 0;
			}
			else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > 20) {
				cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
				Player.constitution = 0;
			}
			else if (Player.constitution >= 0 || Player.constitution <= 20) {
				cout << "Constitution has been set to " << Player.constitution << ".\n\n\n";
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				Player.constitution = 0;
			}
		}
		else if (y == 4) {
			cout << "How many points would you like to put into Agility?\n\n";
			cin >> Player.agility;
			cout << "\n\n";
			if (Player.agility < 0) {
				cout << "You cannot enter a negative value. Try again.\n\n\n";
				Player.agility = 0;
			}
			else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > 20) {
				cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
				Player.agility = 0;
			}
			else if (Player.agility >= 0 || Player.agility <= 20) {
				cout << "Agility has been set to " << Player.agility << ".\n\n\n";
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				Player.agility = 0;
			}
		}
		else if (y == 5) {
			cout << "How many points would you like to put into Luck?\n\n";
			cin >> Player.luck;
			cout << "\n\n";
			if (Player.luck < 0) {
				cout << "You cannot enter a negative value. Try again.\n\n\n";
				Player.luck = 0;
			}
			else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > 20) {
				cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
				Player.luck = 0;
			}
			else if (Player.luck >= 0 || Player.luck <= 20) {
				cout << "Luck has been set to " << Player.luck << ".\n\n\n";
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				Player.luck = 0;
			}
		}
		else if (y == 6) {
			int z = 0;
			cout << "Are you sure that you are finished?  You have " << x << " points left to distribute\n\n";
			cout << "1) Yes, I am absolutely sure of how I distributed my attributes\n";
			cout << "2) No, I want to go back and change something\n";
			cin >> z;
			if (z == 1) {
				cout << "Wow, you truly are a mighty warrior.\n";
				finish = true;
			}
			else if (z == 2) {
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				z = 0;
			}
		}
		else {
			cout << "You must enter a valid input. Restart.\n\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n";
			y = 0;
		}

	} while (finish == false);
}



void Player::Monster::encounter(Player& Player, Player::Monster& Monster) {
	int l = rand() % 5;
	if (Player.kills == 25) {
		Monster.name = "King Rat";
		Monster.damage = 60;
		Monster.health = 1650;
		Monster.speed = 10;
		Monster.defense = 18;
	}
	else if (Player.kills == 50) {
		Monster.name = "GOD EMPEROR RAT";
		Monster.damage = 200;
		Monster.health = 4000;
		Monster.speed = 10;
		Monster.defense = 50;
	}
	else if (Player.kills < 25) {
		if (l == 0) {
			Monster.name = "Slime";
			Monster.damage = 5 + (Player.kills * 2);
			Monster.health = 20 + (Player.kills * 5);
			Monster.speed = 5;
			Monster.defense = 3 + (Player.kills / 2);
		}
		else if (l == 1) {
			Monster.name = "Giant Rat";
			Monster.damage = 9 + (Player.kills * 2);
			Monster.health = 17 + (Player.kills * 5);
			Monster.speed = 5;
			Monster.defense = 2 + (Player.kills / 2);
		}
		else if (l == 2) {
			Monster.name = "Giant Spider";
			Monster.damage = 7 + (Player.kills * 2);
			Monster.health = 15 + (Player.kills * 5);
			Monster.speed = 15;
			Monster.defense = 2 + (Player.kills / 2);
		}
		else if (l == 3) {
			Monster.name = "Snake";
			Monster.damage = 4 + (Player.kills * 2);
			Monster.health = 13 + (Player.kills * 5);
			Monster.speed = 50;
			Monster.defense = 2 + (Player.kills / 2);
		}
		else {
			Monster.name = "Crab";
			Monster.damage = 5 + (Player.kills * 2);
			Monster.health = 25 + (Player.kills * 5);
			Monster.speed = 10;
			Monster.defense = 4 + (Player.kills / 2);
		}
	}
	else {
		if (l == 0) {
			Monster.name = "Skeleton";
			Monster.damage = 15 + (Player.kills * 2.5);
			Monster.health = 40 + (Player.kills * 6);
			Monster.speed = 5;
			Monster.defense = 6 + (Player.kills / 1.5);
		}
		else if (l == 1) {
			Monster.name = "Ghost";
			Monster.damage = 10 + (Player.kills * 2.5);
			Monster.health = 25 + (Player.kills * 6);
			Monster.speed = 50;
			Monster.defense = 3 + (Player.kills / 1.5);
		}
		else if (l == 2) {
			Monster.name = "Vampire";
			Monster.damage = 12 + (Player.kills * 2.5);
			Monster.health = 50 + (Player.kills * 6);
			Monster.speed = 10;
			Monster.defense = 4 + (Player.kills / 1.5);
		}
		else if (l == 3) {
			Monster.name = "Possessed Guard";
			Monster.damage = 12 + (Player.kills * 2.5);
			Monster.health = 35 + (Player.kills * 6);
			Monster.speed = 5;
			Monster.defense = 5 + (Player.kills / 1.5);
		}
		else {
			Monster.name = "Massive Slime";
			Monster.damage = 10 + (Player.kills * 2.5);
			Monster.health = 300 + (Player.kills * 6);
			Monster.speed = 0;
			Monster.defense = 6 + (Player.kills / 1.5);
		}
	}
	if (Monster.name == "King Rat") {
		Monster.maxhealth = Monster.health;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nAs you enter the next room, you are faced with the most terrifying of creatures.\n";
		cout << "In front of you stands a truly massive rat with a crown on its head, and death in its eyes.\n";
		cout << "You have a strong feeling that your life is about to come to an end...\n\n\n\n";
		this_thread::sleep_for(chrono::milliseconds(8000));
		boss1();
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		do {
			int i = 0;
			cout << "King Rat\n";
			cout << "King Rat\n";
			cout << "King Rat\n";
			cout << "King Rat\n";
			cout << "King Rat\n";
			cout << "King Rat\n\n\n\n\n";
			cout << "Potions: " << Player.potions << "\n\n";
			cout << "Health: " << Player.health << "/" << Player.healthmax << "\n\n";
			cout << Monster.name << ": " << Monster.health << "/" << Monster.maxhealth;
			cout << "\n\nUpon entering the room, you encounter a " << Monster.name << ".  Do you:\n";
			cout << "1)Attack\n";
			cout << "2)Drink potion to restore 50 health\n\n\n";
			cin >> i;
			if (i == 2) {
				if (Player.potions > 0) {
					if ((Player.health + 50) > Player.healthmax) {
						Player.health = Player.healthmax;
						Player.potions--;
					}
					else {
						Player.health = Player.health + 50;
						Player.potions--;
					}
				}
				else {
					cout << "You don't have any potions to drink!\n\n";
				}
			}
			else if (i == 1) {
				int ma = rand() % 100;
				if (ma + Monster.speed < 100) {
					double pd = 0;
					if (Monster.defense > Player.damage) {
						Monster.health = Monster.health - (0.15 * Monster.defense);
						pd = (0.15 * Monster.defense);
					}
					else {
						Monster.health = Monster.health - (Player.damage - (Monster.defense * 0.85));
						pd = (Player.damage - (Monster.defense * 0.85));
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou hit the monster for " << pd << " damage\n\n";
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe monster dodges out of your way. You miss!\n\n";
				}
				int pa = rand() % 100;
				if (pa + Player.dodge < 100) {
					double md = 0;
					if ((Player.defense * 2) > Monster.damage) {
						Player.health = Player.health - (0.05 * Player.defense);
						md = (0.05 * Player.defense);
					}
					else {
						Player.health = Player.health - (Monster.damage - (Player.defense * 1.8));
						md = (Monster.damage - (Player.defense * 1.8));
					}
					cout << "The " << Monster.name << " attacks and hits you for " << md << " damage\n\n";

					if (Player.health < 1) {
						Player.alive = false;
						return;
					}
				}
				else {
					cout << "The monster attacks but you manage to avoid it!\n\n";
				}

			}
			else {
				cout << "You must enter a valid input. Try again.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				i = 0;
			}
		} while (Monster.health > 0);
		cout << "Congratulations!  You killed the " << Monster.name << " and earned " << ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills))) << " Experience!\n\n";
		Player.experience = Player.experience + ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills)));
		Player.kills++;
		cout << "After killing the " << Monster.name << ", you notice a chest behind it.  You open it and find...\n\n\n\n";
		int w = rand() % 100 + Player.luck;
		if (w > 90) {
			cout << "8 Potions!\n\n";
			Player.potions = Player.potions + 8;
		}
		else if (w > 80) {
			cout << "7 Potions!\n\n";
			Player.potions = Player.potions + 7;
		}
		else if (w > 65) {
			cout << "6 Potions!\n\n";
			Player.potions = Player.potions + 6;
		}
		else if (w > 40) {
			cout << "5 Potions!\n\n";
			Player.potions = Player.potions + 5;
		}
		else if (w > 20) {
			cout << "4 Potions!\n\n";
			Player.potions = Player.potions + 4;
		}
		else {
			cout << "3 Potions!\n\n";
			Player.potions = Player.potions + 3;
		}
		this_thread::sleep_for(chrono::milliseconds(2000));
	}
	else if (Monster.name == "GOD EMPEROR RAT") {
		Monster.maxhealth = Monster.health;
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNo matter the case, you have a strong feeling that your journey is about to come to an end.\n";
		cout << "You take a step into the next room, but at the sight before you, your blood runs cold.\n";
		cout << "The only thing you can see in front of you is a massive wall of fur.  Suddenly, out of nowhere, a\n";
		cout << "claw attacthed to a paw three times bigger than your entire body swipes towards you. You dive out of\n";
		cout << "the way just in time.  You know for a fact that your life is about to come to an end...\n";
		this_thread::sleep_for(chrono::milliseconds(15000));
		boss2();
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		do {
			int i = 0;
			cout << "GOD EMPEROR RAT\n";
			cout << "GOD EMPEROR RAT\n";
			cout << "GOD EMPEROR RAT\n";
			cout << "GOD EMPEROR RAT\n";
			cout << "GOD EMPEROR RAT\n\n\n\n\n";
			cout << "Potions: " << Player.potions << "\n\n";
			cout << "Health: " << Player.health << "/" << Player.healthmax << "\n\n";
			cout << Monster.name << ": " << Monster.health << "/" << Monster.maxhealth;
			cout << "\n\nUpon entering the room, you encounter a " << Monster.name << ".  Do you:\n";
			cout << "1)Attack\n";
			cout << "2)Drink potion to restore 50 health\n\n\n";
			cin >> i;
			if (i == 2) {
				if (Player.potions > 0) {
					if ((Player.health + 50) > Player.healthmax) {
						Player.health = Player.healthmax;
						Player.potions--;
					}
					else {
						Player.health = Player.health + 50;
						Player.potions--;
					}
				}
				else {
					cout << "You don't have any potions to drink!\n\n";
				}
			}
			else if (i == 1) {
				int ma = rand() % 100;
				if (ma + Monster.speed < 100) {
					double pd = 0;
					if (Monster.defense > Player.damage) {
						Monster.health = Monster.health - (0.15 * Monster.defense);
						pd = (0.15 * Monster.defense);
					}
					else {
						Monster.health = Monster.health - (Player.damage - (Monster.defense * 0.85));
						pd = (Player.damage - (Monster.defense * 0.85));
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou hit the monster for " << pd << " damage\n\n";
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe monster dodges out of your way. You miss!\n\n";
				}
				int pa = rand() % 100;
				if (pa + Player.dodge < 100) {
					double md = 0;
					if ((Player.defense * 2) > Monster.damage) {
						Player.health = Player.health - (0.05 * Player.defense);
						md = (0.05 * Player.defense);
					}
					else {
						Player.health = Player.health - (Monster.damage - (Player.defense * 1.8));
						md = (Monster.damage - (Player.defense * 1.8));
					}
					cout << "The " << Monster.name << " attacks and hits you for " << md << " damage\n\n";

					if (Player.health < 1) {
						Player.alive = false;
						return;
					}
				}
				else {
					cout << "The monster attacks but you manage to avoid it!\n\n";
				}

			}
			else {
				cout << "You must enter a valid input. Try again.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				i = 0;
			}
		} while (Monster.health > 0);
		cout << "Congratulations!  You killed the " << Monster.name << " and earned " << ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills))) << " Experience!\n\n";
		Player.experience = Player.experience + ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills)));
		Player.kills++;
		Player.finishgame = true;
	}
	else {
		Monster.maxhealth = Monster.health;
		do {
			int i = 0;
			cout << "Curent Room: " << Player.kills << "\n\n";
			cout << "Potions: " << Player.potions << "\n\n";
			cout << "Health: " << Player.health << "/" << Player.healthmax << "\n\n";
			cout << Monster.name << ": " << Monster.health << "/" << Monster.maxhealth;
			cout << "\n\nUpon entering the room, you encounter a " << Monster.name << ".  Do you:\n";
			cout << "1)Attack\n";
			cout << "2)Drink potion to restore 50 health\n\n\n";
			cin >> i;
			if (i == 2) {
				if (Player.potions > 0) {
					if ((Player.health + 50) > Player.healthmax) {
						Player.health = Player.healthmax;
						Player.potions--;
					}
					else {
						Player.health = Player.health + 50;
						Player.potions--;
					}
				}
				else {
					cout << "You don't have any potions to drink!\n\n";
				}
			}
			else if (i == 1){
				int ma = rand() % 100;
				if (ma + Monster.speed < 100) {
					double pd = 0;
					if (Monster.defense > Player.damage) {
						Monster.health = Monster.health - (0.15 * Monster.defense);
						pd = (0.15 * Monster.defense);
					}
					else {
						Monster.health = Monster.health - (Player.damage - (Monster.defense * 0.85));
						pd = (Player.damage - (Monster.defense * 0.85));
					}
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou hit the monster for " << pd << " damage\n\n";
				}
				else {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nThe monster dodges out of your way. You miss!\n\n";
				}
				int pa = rand() % 100;
				if (pa + Player.dodge < 100) {
					double md = 0;
					if ((Player.defense * 2) > Monster.damage) {
						Player.health = Player.health - (0.05 * Player.defense);
						md = (0.05 * Player.defense);
					}
					else {
						Player.health = Player.health - (Monster.damage - (Player.defense * 1.8));
						md = (Monster.damage - (Player.defense * 1.8));
					}
					cout << "The " << Monster.name << " attacks and hits you for " << md << " damage\n\n";
					
					if (Player.health < 1) {
						Player.alive = false;
						return;
				}
				}
				else {
					cout << "The monster attacks but you manage to avoid it!\n\n";
				}

			}
			else {
				cout << "You must enter a valid input. Try again.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				i = 0;
			}
		} while (Monster.health > 0);
		cout << "Congratulations!  You killed the " << Monster.name << " and earned " << ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills))) << " Experience!\n\n";
		Player.experience = Player.experience + ((Monster.maxhealth * 0.9) + (Player.kills * 25) + ((Player.luck * Player.kills) * (0.1 * Player.luck * Player.kills)));
		Player.kills++;
		if (Player.kills % 5 == 0) {
			cout << "After killing the " << Monster.name << ", you notice a chest behind it.  You open it and find...\n\n\n\n";
			int w = rand() % 100 + Player.luck;
			if (w > 73) {
				cout << "3 Potions!\n\n";
				Player.potions = Player.potions + 3;
			}
			else if (w > 40) {
				cout << "2 Potions!\n\n";
				Player.potions = Player.potions + 2;
			}
			else {
				cout << "1 Potion!\n\n";
				Player.potions = Player.potions + 1;
			}
			this_thread::sleep_for(chrono::milliseconds(2000));
		}
	}
}

void Player::levelup(Player& Player) {
	if (Player.experience >= (Player.level / 0.07) * (Player.level / 0.07)) {
		Player.level = Player.level + 1;
		Player.health = Player.healthmax;
		Player.experience = 0;
		cout << "Congrats!  You have leveled up!  Your stats have increased, and you now have five more attribute points to distribute.\n\n\n";
		bool finish = false;
		do {
			int x = (20 + (Player.level * 5)) - 5 - Player.strength - Player.dexterity - Player.constitution - Player.agility - Player.luck;
			int y = 0;
			cout << "You have " << x << " skill points left to distribute. Choose which skill to add or remove points from.\n\n";
			cout << "1) Strength (Affects damage) " << Player.strength << " points currently in Strength.\n";
			cout << "2) Dexterity (Affects defense) " << Player.dexterity << " points currently in Dexterity.\n";
			cout << "3) Constitution (Affects total health) " << Player.constitution << " points currently in Constitution.\n";
			cout << "4) Agility (Affects chance to dodge) " << Player.agility << " points currently in Agility.\n";
			cout << "5) Luck (Affects loot from chests and enemy drops) " << Player.luck << " points currently in Luck.\n";
			cout << "6) Finish distributing attributes\n";
			cin >> y;
			if (y == 1) {
				cout << "How many points would you like to put into Strength?\n\n";
				int h = 0;
				cin >> h;
				Player.strength = h + Player.strength;
				cout << "\n\n";
				if (Player.strength < 0) {
					cout << "You cannot enter a negative value. Try again.\n\n\n";
					Player.strength = 0;
				}
				else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > (15 + (Player.level * 5))) {
					cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
					Player.strength = 0;
				}
				else if (Player.strength >= 0 || Player.strength <= (20 + (Player.level * 5))) {
					cout << "Strength has been set to " << Player.strength << ".\n\n\n";
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					Player.strength = 0;
				}
			}
			else if (y == 2) {
				cout << "How many points would you like to put into Dexterity?\n\n";
				int h = 0;
				cin >> h;
				Player.dexterity = h + Player.dexterity;
				cout << "\n\n";
				if (Player.dexterity < 0) {
					cout << "You cannot enter a negative value. Try again.\n\n\n";
					Player.dexterity = 0;
				}
				else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > (15 + (Player.level * 5))) {
					cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
					Player.dexterity = 0;
				}
				else if (Player.dexterity >= 0 || Player.dexterity <= (20 + (Player.level * 5))) {
					cout << "Dexterity has been set to " << Player.dexterity << ".\n\n\n";
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					Player.dexterity = 0;
				}
			}
			else if (y == 3) {
				cout << "How many points would you like to put into Constitution?\n\n";
				int h = 0;
				cin >> h;
				Player.constitution = h + Player.constitution;
				cout << "\n\n";
				if (Player.constitution < 0) {
					cout << "You cannot enter a negative value. Try again.\n\n\n";
					Player.constitution = 0;
				}
				else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > (15 + (Player.level * 5))) {
					cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
					Player.constitution = 0;
				}
				else if (Player.constitution >= 0 || Player.constitution <= (20 + (Player.level * 5))) {
					cout << "Constitution has been set to " << Player.constitution << ".\n\n\n";
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					Player.constitution = 0;
				}
			}
			else if (y == 4) {
				cout << "How many points would you like to put into Agility?\n\n";
				int h = 0;
				cin >> h;
				Player.agility = h + Player.agility;
				cout << "\n\n";
				if (Player.agility < 0) {
					cout << "You cannot enter a negative value. Try again.\n\n\n";
					Player.agility = 0;
				}
				else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > (15 + (Player.level * 5))) {
					cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
					Player.agility = 0;
				}
				else if (Player.agility >= 0 || Player.agility <= (20 + (Player.level * 5))) {
					cout << "Agility has been set to " << Player.agility << ".\n\n\n";
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					Player.agility = 0;
				}
			}
			else if (y == 5) {
				cout << "How many points would you like to put into Luck?\n\n";
				int h = 0;
				cin >> h;
				Player.luck = h + Player.luck;
				cout << "\n\n";
				if (Player.luck < 0) {
					cout << "You cannot enter a negative value. Try again.\n\n\n";
					Player.luck = 0;
				}
				else if (Player.strength + Player.dexterity + Player.constitution + Player.agility + Player.luck > (15 + (Player.level * 5))) {
					cout << "Total sum of attributes cannot be greater than 20. Try again.\n\n\n";
					Player.luck = 0;
				}
				else if (Player.luck >= 0 || Player.luck <= (20 + (Player.level * 5))) {
					cout << "Luck has been set to " << Player.luck << ".\n\n\n";
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					Player.luck = 0;
				}
			}
			else if (y == 6) {
				int z = 0;
				cout << "Are you sure that you are finished?  You have " << x << " points left to distribute\n\n";
				cout << "1) Yes, I am absolutely sure of how I distributed my attributes\n";
				cout << "2) No, I want to go back and change something\n";
				cin >> z;
				if (z == 1) {
					finish = true;
				}
				else if (z == 2) {
				}
				else {
					cout << "You must enter a valid input. Restart.\n\n\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					z = 0;
				}
			}
			else {
				cout << "You must enter a valid input. Restart.\n\n\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				y = 0;
			}
		} while (finish == false);
		Player.healthmax = 100 + (Player.level * 10) + (Player.constitution * 10);
		Player.health = Player.healthmax;
	}

}

void boss1() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK         KK                                                 RRRRRRR                     TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK       KK       II                          GGGG            RRR    RR                   TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK     KK                NN    NN           GG    GG          RRR      RR            TTTTTTTTTTTT \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK   KK           II     NN NN    NN      GG        GG        RRR      RR                 TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KKKKK             II     NN         NN      GG    GG GG       RRR    RR        AAA        TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK   KK           II     NN         NN        GGGG   GG       RRRRRRR        AA   AA      TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK     KK         II     NN         NN             GG         RRR    RR     AA     AA     TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK       KK       II     NN         NN     GG     GG          RRR      RR     AAAAAA      TT      \n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "KK         KK     II     NN         NN       GGGGG            RRR       RR         AA     TT      \n";
	this_thread::sleep_for(chrono::milliseconds(2200));
}

void boss2() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	this_thread::sleep_for(chrono::milliseconds(500));
	cout << "                       GGGGGGGGGGGGGGG                  OOOOOOOOOOOO              DDDDDDDDDDDD         \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                     GGGGGGG                        OOOOOOOO     OOOOOOOO         DDDDD   DDDDDDD      \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                   GGGGGGG                        OOOOOOOO         OOOOOOOO       DDDDD     DDDDDDD    \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                 GGGGGGG                        OOOOOOOO             OOOOOOOO     DDDDD       DDDDDD   \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                GGGGGGG     GGGGGGGGGGGGG      OOOOOOO                 OOOOOOO    DDDDD        DDDDDD  \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                 GGGGGGG        GGGGGGGGGGGG    OOOOOOOO             OOOOOOOO     DDDDD       DDDDDD   \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                   GGGGGGG         GGGGGGGG       OOOOOOOO         OOOOOOOO       DDDDD     DDDDDDD    \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                     GGGGGGGGGGGGGGGGGGGGG          OOOOOOOO     OOOOOOOO         DDDDD   DDDDDDD      \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                       GGGGGGGGGGGGGGGG               OOOOOOOOOOOOOOO             DDDDDDDDDDDD         \n";
	this_thread::sleep_for(chrono::milliseconds(600));


	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           EEEEEEEEEEEEEE    MMMMMMM               MMMMMMMMM   PPPPPPPPPPPP     \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEEEEEEEEEEEE    MMMM  MMMM           MMMM  MMMM   PPPP      PPPP   \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEE              MMMM    MMMM       MMMM    MMMM   PPPP        PPPP \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEE              MMMM      MMMM   MMMM      MMMM   PPPP        PPPP \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEEEEEEEE        MMMM        MMMMMMM        MMMM   PPPP      PPPP   \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEE              MMMM          MMM          MMMM   PPPPPPPPPPPP     \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEE              MMMM                       MMMM   PPPP             \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEEEEEEEEEEEE    MMMM                       MMMM   PPPP             \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                           EEEEEEEEEEEEEE    MMMM                       MMMM   PPPP             \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "\n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "\n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEEEEEEEEEEEE   RRRRRRRRR               OOOOOOO         RRRRRRRRR       \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEEEEEEEEEEEE   RRRR   RRRR           OOOO   OOOO       RRRR   RRRR     \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEE             RRRR     RRRR       OOOO       OOOO     RRRR     RRRR   \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEE             RRRR      RRRR    OOOO           OOOO   RRRR      RRRR  \n";
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEEEEEEEE       RRRR     RRRR    OOOO             OOOO  RRRR     RRRR   \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEE             RRRRRRRRR         OOOO           OOOO   RRRRRRRRR       \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEE             RRRR   RRRR         OOOO       OOOO     RRRR   RRRR     \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEEEEEEEEEEEE   RRRR     RRRR         OOOO   OOOO       RRRR     RRRR   \n"; 
	this_thread::sleep_for(chrono::milliseconds(120));
	cout << "                         EEEEEEEEEEEEEE   RRRR       RRRR         OOOOOOO         RRRR       RRRR \n"; 
	this_thread::sleep_for(chrono::milliseconds(600));
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << "                           RRRRRRRRR                  AAAAAAAAA          TTTTTTTTTTTTTTTTTTTTTT   \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR   RRRR               AAAAAAAAAAA         TTTTTTTTTTTTTTTTTTTTTT   \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR     RRRR            AAAA     AAAA                 TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR      RRRR          AAAA       AAAA                TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR     RRRR          AAAAAAAAAAAAAAAAA               TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRRRRRRR             AAAAAAAAAAAAAAAAAAA              TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR   RRRR          AAAA             AAAA             TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR     RRRR       AAAA               AAAA            TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(200));
	cout << "                           RRRR       RRRR    AAAA                 AAAA           TTTT            \n";
	this_thread::sleep_for(chrono::milliseconds(750));



	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	for (int i = 0; i < 40; i++) {
		cout << "PREPARE\n";
		this_thread::sleep_for(chrono::milliseconds(35));
	}

	for (int i = 0; i < 40; i++) {
		cout << "TO\n";
		this_thread::sleep_for(chrono::milliseconds(35));
	}

	for (int i = 0; i < 40; i++) {
		cout << "DIE\n";
		this_thread::sleep_for(chrono::milliseconds(35));
	}
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

}


