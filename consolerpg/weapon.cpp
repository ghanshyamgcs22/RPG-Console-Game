#include "weapon.h"
weapon::weapon(int damageMin , int damageMax , string name , int level , int buyValue , int sellValue , int rarity ) :Item(name, level, buyValue, sellValue, rarity)
{
	this->damageMax = damageMax;
	this->damageMin = damageMin;
}
weapon::~weapon()
{}

weapon* weapon::clone()const
{
	return new weapon(*this);
 }

string weapon::toString()
{
	string str = to_string(this->damageMin) + " " + to_string(this->damageMax);
	return str;
}