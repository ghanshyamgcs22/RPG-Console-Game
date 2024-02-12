#pragma once

#include"Event.h"

#include<vector>
//#include<fstream>

using namespace std;

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
	int activeChar;
	vector<character> chartr;
	string fileName;

	//enemies
	dArr<Enemey>enemies;
};


