#pragma once
#include "Item.h"
class weapon:public Item
{
private:
	int damageMin;
	int damageMax;
public:
	weapon(int damageMin = 0, int damageMax = 0, string name = "None", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~weapon();
	//pure virtual 
	virtual weapon* clone() const override;
	//function
	string toString();
};

