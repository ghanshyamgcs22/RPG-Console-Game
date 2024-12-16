#pragma once

#include"inventory.h"
#include"baseClass.h"
#include"Enemey.h"

using namespace std;

class character :public baseClass
{
public:
	character();
	character(string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int stamina, int statPoints, int skillPoints);

	virtual ~character();

	//Function
	void initialize(const std::string name);
	void restExp(int time) {
		if (this->exp > 0)
		{
			this->exp = this->exp - rand() % time;
		}

	}
	void printStats()const;
	void levelUp();
	virtual string getAsString()const;
	void updateStats();
	void addToStat(int stat, int  value);
	//acessor

	//inline const int& getX()const { return this->xpos; }
	//inline const int& getY()const { return this->yPos; }
	inline const int& getDistanceTravelled()const { return this->distanceTravelled; }
	inline const std::string& getName()const { return this->name; }
	inline const int& getlevel()const { return this->level; }
	inline const int& getExp()const { return this->exp; }
	inline const int& getExpNext()const { return this->expNext; }
	inline const int& getstatPoints()const { return this->statPoints; }
	inline const int& getHp()const { return this->hp; }
	inline const int& getHpMax()const { return this->hpMax; }
	inline const bool isAlive()const { return this->hp > 0; }
	inline const int& getStamina()const { return this->stamina; }
	inline const int& getDamageMin()const { return this->damageMin; }
	inline const int& getDamageMax()const { return this->damageMax; }
	inline const int& getDamage()const { return (rand() % (this->damageMax - this->damageMin)) + this->damageMin; }
	inline const int& getDefence()const { return this->defence; }
	inline const int& getAccuracy()const
	{
		return this->accuracy;
	}



	//modifier
	inline void setDistTravelled(const int& distance) { this->distanceTravelled = distance; }
	inline void travel() { this->distanceTravelled++; }
	inline void gainExp(const int& exp) {
		cout << "your exp is increased by" << exp << "\n";
		this->exp += exp;
	}
	void takeDamage(const int damage);
private:
	//double xpos;
	//double yPos;

	int distanceTravelled;

	inventory Inventory;
	weapon Weapon;
	Armor armor_head;
	Armor armor_chest;
	Armor armor_arms;
	Armor armor_legs;
	int gold;

	std::string name;
	int level;
	int exp;
	int expNext;

	int strength;
	int dexterity;
	int vitality;
	int intelligence;

	int hp;
	int hpMax;
	int stamina;
	int staminaMax;

	int damageMin;
	int damageMax;
	int defence;
	int accuracy;
	int luck;

	int statPoints;
	int skillPoints;
};

