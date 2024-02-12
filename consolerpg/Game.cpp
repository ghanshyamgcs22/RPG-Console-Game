#include "Game.h"
#include"function.h"
#include"ghanshyam.h"

#include<ctime>
#include<iomanip>
#include<iostream>
#include<sstream>

using namespace std;

Game::Game()
{
	choice = 0;
	playing = true;
	activeChar = 0;
	fileName = "characters.txt";
}
Game::~Game()
{

}

// Functions
void Game::initGame()
{

	/*inventory inv;
	inv.addItem(weapon(0,0,"wep1"));
	inv.addItem(weapon(0, 0, "wep2"));
	inv.addItem(weapon(0, 0, "wep3"));
	inv.addItem(Armor(0, 0, "arm1"));
	inv.addItem(Armor(0, 0, "arm2"));
	inv.addItem(Armor(0, 0, "arm3"));

	for (size_t i = 0; i < inv.size(); i++)
	{
		cout << inv[i].debugPrint() << "\n";
	}
	Enemey e(rand()&10 + 1);
	cout << e.getAsString();
	*/


	creatNewCharacter();
	//dArr<int>ints;
	//for (size_t i = 0; i < 20; i++)
	//{
	//	ints.push(rand() % 10); 
	//	cout << ints[i] << "\n";
	//}


	//Puzzle p("lel.txt");
	//cout<<p.getAsstring()<<"\n";
	//weapon w1(, 5, "ddk", 1, 100, 100, 1);
	//cout << w1.toString() << "\n";

}
void Game::mainMenu()

{
	cout << "Enter to continue..\n";
	cin.get();
	system("CLS");
	if (this->chartr[activeChar].getExp() >= this->chartr[activeChar].getExpNext())
	{
		cout << "Level up available" << "\n" << "\n";

	}
	cout << "Main Menu\n" << "\n";

	cout << "Active character name : " << this->chartr[this->activeChar].getName() << " No. " << this->activeChar + 1 << "/" << this->chartr.size() << "\n\n";
	cout << "0: Quit" << "\n";
	cout << "1: Travel" << "\n";
	//cout << "2: Shop" << "\n";
	cout << "3: Level Up" << "\n";
	cout << "4: Rest \n \n";
	cout << "5: Character sheet" << "\n";
	cout << "6: Creat new character" << "\n";
	cout << "7: Save Character" << "\n";
	cout << "8: Load Character" << "\n";
	cout << "9: select character" << "\n";
	cout << "\n";
	cout << "\n" << "Choice: " << "\n";

	cin >> this->choice;
	cout << "\n";

	while (cin.fail())
	{
		cout << "Faulty input" << "\n";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << "Choice:" << "\n";
		cin >> this->choice;;

	}
	cout << "\n";

	switch (this->choice)
	{
	case 0://Quit
		playing = false;
		break;
	case 1://Travel
		Travel();
		cin.get();

		break;


	case 3://level up
		this->levelUpCharacter();
		cin.get();
		break;

	case 4://Rest
		cout << "how much time you want to rest in minutes!" << endl;
		int time;
		cin >> time;
		if (time > 60)
		{
			chartr[activeChar].restExp(time);
		}
		cout << "You rested " << endl;
		cout << "Now you Exp decreased ! " << endl;

		cin.get();

		break;
	case 5://Character sheet
		chartr[activeChar].printStats();
		cin.get();
		break;
	case 6://New Chracter
		cin.ignore();
		creatNewCharacter();
		saveNewCharacters();
		cin.get();

		break;
	case 7://Save character

		chartr[activeChar].printStats();
		cin.get();

		break;
	case 8://Load charater

		loadNewCharacters();
		cin.get();

		break;

	case 9:
		selectCharacter();
		cin.get();

	default:
		break;
	}
}
void Game::creatNewCharacter()
{
	string name = "";
	cout << "Character Name" << "\n";
	getline(cin, name);

	for (size_t i = 0; i < this->chartr.size(); i++)
	{
		if (name == this->chartr[i].getName())
		{
			cout << "Error! Character already exists" << "\n";
			cout << "Character Name" << "\n";
			getline(cin, name);
			i = 0;
		}
	}
	chartr.push_back(character());
	activeChar = static_cast<int>(chartr.size() - 1);
	chartr[activeChar].initialize(name);
}
void Game::saveNewCharacters()
{
	ofstream outFile(fileName);
	if (outFile.is_open())
	{
		for (size_t i = 0; i < chartr.size(); i++)
		{
			outFile << chartr[i].getAsString() << "\n";
		}
	}
	outFile.close();
}

void Game::levelUpCharacter()
{
	this->chartr[activeChar].levelUp();
	if (this->chartr[activeChar].getstatPoints() > 0)
	{
		cout << "You have statpoints to allocate !" << "\n" << "\n";
		cout << "\n" << "Stat to upgrade: " << "\n";
		cout << "\n" << "0 : Strength " << "\n";
		cout << "\n" << "1 : Vitality " << "\n";
		cout << "\n" << "2 : Dexterity " << "\n";
		cout << "\n" << "3 : Intelligence " << "\n";
		// cout << "\n" << "4 :  " << "\n";
		// cout << "\n" << "5 :  " << "\n";

		cin >> this->choice;
		cout << "\n";

		while (cin.fail() || this->choice > 3)
		{
			cout << "Faulty input" << "\n";
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n" << "Stat to upgrade: " << "\n";

			cin >> this->choice;

		}
		cin.ignore(100, '\n');
		cout << "\n";

		switch (this->choice)
		{
		case 0://strength
			this->chartr[activeChar].addToStat(0, 1);

			break;

		case 1://vitality
			this->chartr[activeChar].addToStat(1, 1);

			break;

		case 2://dexterity
			this->chartr[activeChar].addToStat(2, 1);

			break;

		case 3://intelligence
			this->chartr[activeChar].addToStat(3, 1);
			break;

		default:
			break;
		}
	}

}

void Game::loadNewCharacters()
{

	std::string name = " ";
	int distanceTravelled = 0;
	int gold = 0;
	int level = 0;
	int exp = 0;
	//int expNext=0;

	int strength = 0;
	int dexterity = 0;
	int vitality = 0;
	int intelligence = 0;

	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int skillPoints = 0;
	ifstream inFile(fileName);
	this->chartr.clear();
	string line = "";
	stringstream str;
	if (inFile.is_open())
	{
		while (getline(inFile, line))
		{
			str.str(line);
			str >> name >> distanceTravelled >>
				gold >>
				level >>
				exp >>
				strength >>
				vitality >>
				dexterity >>
				intelligence >>
				hp >>
				stamina >>
				statPoints >>
				skillPoints;

			character temp(name, distanceTravelled, gold, level, exp, strength, vitality, dexterity, intelligence, hp, stamina, statPoints, skillPoints);
			this->chartr.push_back(character(temp));
			cout << "Character " << name << " loaded" << "\n";
			str.clear();
		}
		cin.get();

	}
	inFile.close(); if (this->chartr.size() <= 0)
	{
		throw"Error ! no character loaded";
	}
}
void Game::selectCharacter()
{
	cout << "Select character : " << "\n\n";
	for (int i = 0; i < this->chartr.size(); i++)
	{
		cout << "Character number " << i + 1 << " : " << this->chartr[i].getName() << " Level : " << this->chartr[i].getlevel() << " " << "\n";
	}
	cout << "\n";
	cout << "\n" << "Choice: " << "\n";

	cin >> this->choice;
	cout << "\n";

	while (cin.fail() || this->choice >= this->chartr.size() + 1 || this->choice < 1)
	{
		cout << "Faulty input" << "\n";
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\n" << "Select Character" << "\n";
		cin >> this->choice;

	}
	cin.ignore();
	cout << "\n";
	this->activeChar = this->choice - 1;
	cout << this->chartr[this->activeChar].getName() << " is selected!\n" << "\n";
}

void Game::Travel()
{
	character& currentCharacter = this->chartr[activeChar];
	currentCharacter.travel();

	Event ev;
	ev.generateEvent(currentCharacter, this->enemies);
}
