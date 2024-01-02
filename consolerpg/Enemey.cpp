#include "Enemey.h"
Enemey::Enemey(int level)
{
	this->level = level;
	this->hpMax = 10 * level;
	this->hp = this->hpMax;
	this->damgeMin = this->level * 4;
	this->damageMax = this->level * 5;
	this->dropChance = rand() % 100;
	this->defence = rand() % 100;
	this->accuracy = rand() % 100;

}
Enemey::~Enemey()
{

}
string Enemey::getAsString()const
{
	return "Level"+ to_string(this->level) + "\n " +" Hp:" + to_string(this->hp) + " /"+to_string(this->hpMax)+"\n" +
		+ " damage:" + to_string(this->damgeMin) + " -" + to_string(this->damageMax)+ "\n" +
		"Defence:"+to_string(this->defence)+"\n"+
		"accuracy"+to_string(this->accuracy)+ "\n" +
		"Drop Chance"+to_string(this->dropChance);
}
void Enemey::takeDamage(int damage)
{
	this->hp -= damage;
	if (this->hp <= 0)
	{
		this->hp = 0;
	}

}