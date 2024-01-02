#pragma once
#include<stdlib.h>
#include"Puzzle.h"
#include"character.h"
#include"ghanshyam.h"
class Event
{
	int noOfEvents;
public:
	virtual ~Event();
	Event();
    void generateEvent(character &character, dArr<Enemey>& enemies);
	void enemyEncounter(character& charactr, dArr<Enemey>& enemies);
	void puzzleEncounter(character& charactr);
};

