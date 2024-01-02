#pragma once
#include<stdlib.h>
#include<string>
#include"baseClass.h"
using namespace std;
class Enemey:baseClass
{
private:
	int hp;
	int hpMax;
	int level;
	int damgeMin;
	int damageMax;
	float dropChance;
	int defence;
	int accuracy;
	 
public:
	Enemey(int level = 0);
	virtual ~Enemey();

	inline bool isAlive() {
		return this->hp > 0;
	}

	virtual string getAsString()const;
	void takeDamage(int damage);
    inline int getLevel()const { return this->level; }

	inline int getDamage()const { return rand() % this->damageMax-this->damgeMin; }
	inline int getExp()const { return this->level * 100; }
	inline int getHp()const { return this->hp; }
	inline int getHpMax()const { return this->hpMax; }
};

