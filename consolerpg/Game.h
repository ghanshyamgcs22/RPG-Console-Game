#pragma once
#include<sstream>
#include"function.h"
#include"Event.h"
#include"ghanshyam.h"
#include<iomanip>
#include<vector>
#include<iostream>
//#include<fstream>
using namespace std;
#include<ctime>
class Game
{
public:
	Game();
	virtual ~Game();

	//operators
	//functions
	void initGame();
	void mainMenu();
	void creatNewCharacter();
	void saveNewCharacters();
	void loadNewCharacters();

	void endGame();
	void Travel();

	void levelUpCharacter();

	void selectCharacter();


		//accessors
	inline bool getPlaying()const { return this->playing; }
	//modifiers
private:
	int choice;
	bool playing;
  

	//character related
	int activeveChar;
	vector<character> chartr;
	string fileName;

	//enemies
	dArr<Enemey>enemies;

};


