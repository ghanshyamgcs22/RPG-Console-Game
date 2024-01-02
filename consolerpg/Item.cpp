#include "Item.h"

Item::Item(string name,int level,int buyvalue,int  sellValue,int rarity)
{
	this->name = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->level=level;
	this->rarity=rarity;
}
Item::~Item()
{

}

