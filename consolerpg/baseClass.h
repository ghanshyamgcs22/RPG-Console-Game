#pragma once
#include<string>
class baseClass
{
public:
	virtual std::string getAsString() const =0;

	inline int getDamage()const;
	inline int getExp()const;
	inline int getHp()const;
	inline int getHpMax()const;

};

