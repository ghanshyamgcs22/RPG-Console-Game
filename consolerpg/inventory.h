#pragma once
//#include"Item.h"
#include "Armor.h"
#include "weapon.h"

class inventory
{
private:
	int capacity;
	void expand();
	Item** itemArr;
	void initialize(const int from=0);
	int noOfItems;
public:
	inventory();
	~inventory();
	inventory(const inventory& obj);
	inline int size()const { return this->noOfItems;
	};

	Item& operator [](const int index);
	void removeItem(int index); 
	void addItem(const Item& item);
	inline void debugPrint()const
	{
		for (size_t i = 0; i < noOfItems; i++)
		{
			std::cout << this->itemArr[i]->debugPrint ()<< "\n";
		}
	}
};

