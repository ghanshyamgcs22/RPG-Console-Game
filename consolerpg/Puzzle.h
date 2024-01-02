#pragma once
#include<stdlib.h>
#include <string>
#include<vector>
#include<fstream>
#include"baseClass.h"
using namespace std;

class Puzzle
{
private:
	string question;
	vector<string>answer;
	int correctAnswer;


public:
	Puzzle(string filename);
	virtual ~Puzzle();
	 string getAsstring();
	inline const int& grtcorrectAns() const{ return this->correctAnswer; }
};

