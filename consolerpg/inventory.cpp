#include "inventory.h"
inventory::inventory()
{

	this->capacity=5;
	this->noOfItems = 0;
	this->itemArr = new Item * [capacity];
	this->initialize();
}
inventory::~inventory()
{


	for (size_t i = 0; i < this->noOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}

inventory::inventory(const inventory& obj)
{
	this->capacity = obj.capacity;
	this->noOfItems = obj.noOfItems;
	this->itemArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->noOfItems; i++)
	{

		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->noOfItems);
}

Item& inventory::operator[](const int index)
{
	if (index < 0 || index >= this->noOfItems)
	{
		throw("Bad index!");
	}
	return *this->itemArr[index];
}

void inventory::expand(){

	this->capacity *= 2;

	Item** tempArr = new Item * [this->capacity];

	for (size_t i = 0; i < this->noOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}
	/*for (size_t i = 0; i < noOfItems; i++)
	{
		delete this->itemArr[static_cast<int>(i)];
	}*/
	delete[] this->itemArr;
	this->itemArr = tempArr;

	this->initialize(this->noOfItems);

}
void inventory::initialize(const int from){
for(size_t i=from;i<capacity;i++)
{ 
	this->itemArr[i] = nullptr;

}

}


void inventory:: removeItem(int index)
{

}
void inventory::addItem(const Item& item)

	{
		if (this->noOfItems >= this->capacity)
		{
			expand();
		}

		this->itemArr[this->noOfItems++] = item.clone();
	}
