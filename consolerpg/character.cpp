#include "character.h"

#include<iostream>
#include<iomanip>

character::character() {
	this->gold = 0;
	this->distanceTravelled = 0;

	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->expNext = 0;

	this->strength = 0;
	this->dexterity = 0;
	this->vitality = 0;
	this->intelligence = 0;

	this->hp = 0;
	this->hpMax = 0;
	this->stamina = 0;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;
	this->statPoints = 0;
	this->skillPoints = 0;
}

character::character(string name, int distanceTravelled, int gold, int level, int exp, int strength, int vitality, int dexterity, int intelligence, int hp, int stamina, int statPoints, int skillPoints) {
	this->gold = gold;
	this->distanceTravelled = distanceTravelled;

	this->name = name;
	this->level = level;
	this->exp = exp;
	this->expNext = 0;

	this->strength = strength;
	this->dexterity = dexterity;
	this->vitality = vitality;
	this->intelligence = intelligence;

	this->hp = hp;
	this->hpMax = 0;
	this->stamina = stamina;
	this->staminaMax = 0;
	this->damageMin = 0;
	this->damageMax = 0;
	this->defence = 0;
	this->accuracy = 0;
	this->luck = 0;
	this->statPoints = statPoints;
	this->skillPoints = skillPoints;
	this->updateStats();
}

character::~character() {}

void character::initialize(std::string name)
{
	this->distanceTravelled = 0;

	this->gold = 100;

	this->name = name;
	this->level = 1;
	this->exp = 0;
	this->expNext = static_cast<int>((50.0 / 3.0) * (pow(static_cast<double>(level), 3.0) - 6.0 * pow(static_cast<double>(level), 2.0) + (17.0 * static_cast<double>(level)) - 11.0)) + 100;

	this->strength = 5;
	this->dexterity = 5;
	this->vitality = 5;
	this->intelligence = 5;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->hp = this->hpMax;
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->stamina = this->staminaMax;
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->luck = this->intelligence;
	this->defence = 1;

	this->accuracy = this->dexterity / 2;
	this->statPoints = 0;
	this->skillPoints = 0;
}

void character::printStats()const {
	std::cout << "Character sheet=" << "\n";
	cout << "=Name: " << this->name << "\n";
	cout << "=Lavel: " << this->level << "\n";
	cout << "=Exp: " << this->exp << "\n";
	cout << "=Exp to Next level: " << this->expNext << "\n";
	cout << "=Strength: " << this->strength << "\n";
	cout << "=Vitality: " << this->vitality << "\n";
	cout << "=Dexterity: " << this->dexterity << "\n";
	cout << "=Hp: " << this->hp << '/' << this->hpMax << "\n";
	cout << "=Intelligence: " << this->intelligence << "\n";
	cout << "=Stamina: " << this->stamina << '/' << this->staminaMax << "\n";
	cout << "=Damage: " << this->damageMin << "-" << this->damageMax << "\n";
	cout << "=Defence: " << this->defence << "\n";
	cout << "=Accuracy: " << this->accuracy << "\n";
	cout << "=Luck: " << this->luck << "\n";
	cout << "\n";
}

void character::updateStats()
{
	this->expNext = static_cast<int>((50.0 / 3.0) * (pow(static_cast<double>(level), 3.0) - 6.0 * pow(static_cast<double>(level), 2.0) + (17.0 * static_cast<double>(level)) - 11.0)) + 100;

	this->hpMax = (this->vitality * 2) + (this->strength / 2);
	this->staminaMax = this->vitality + (this->strength / 2) + (this->dexterity / 3);
	this->damageMin = this->strength;
	this->damageMax = this->strength + 2;
	this->luck = this->intelligence;
}

void character::addToStat(int stat, int  value) {
	if (this->statPoints < value)
	{
		cout << "Error! Not enough statpoint!";
	}
	else {
		switch (stat)
		{
		case 0:
			this->strength += value;
			cout << "STRENGTH INCREASED" << "\n";
			break;

		case 1:
			cout << "VITALITY INCREASED" << "\n";
			this->vitality += value;

			break;

		case 2:
			cout << "DEXTERITY INCREASED" << "\n";
			this->dexterity += value;

			break;

		case 3:
			cout << "INTELLIGENCE INCREASED" << "\n";
			this->intelligence += value;

			break;

		default:
			cout << "No such stat!" << "\n";
			break;
		}
	}

	this->statPoints -= value;
}

void character::levelUp() {
	if (this->exp >= this->expNext)
	{
		this->exp -= this->expNext;

		this->level++;
		this->exp = this->expNext;
		this->expNext = static_cast<int>((50.0 / 3.0) * (pow(static_cast<double>(this->level), 3.0) - 6.0 * pow(static_cast<double>(this->level), 2.0) + (17.0 * static_cast<double>(this->level)) - 11.0));
		this->skillPoints++;
		this->statPoints++;
		this->updateStats();
		cout << "YOU ARE NOW LEVEL " << this->level << " !\n\n";
	}
	else
	{
		cout << "NOT ENOUGH EXP!\n\n";
	}
}

string character::getAsString()const
{
	return  name +
		" " + to_string(distanceTravelled) +
		" " + to_string(gold) +
		" " + to_string(level) +
		" " + to_string(exp) +
		" " + to_string(strength) +
		" " + to_string(vitality) +
		" " + to_string(dexterity) +
		" " + to_string(intelligence) +
		" " + to_string(hp) +
		" " + to_string(stamina) +
		" " + to_string(statPoints) +
		" " + to_string(skillPoints);
}

void character::takeDamage(const int damage)
{
	this->hp -= damage;

	if (this->hp <= 0)
	{
		this->hp = 0;
	}
}
