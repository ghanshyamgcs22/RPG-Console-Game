#include "Puzzle.h"

Puzzle::Puzzle(string filename)
{    
	this->correctAnswer = 0;
	ifstream inFile(filename);
	int noOfAns = 0;
	string answer = " ";
	int correctAns = 0;
	if (inFile.is_open())
	{
		getline(inFile, this->question);
		inFile >> noOfAns; 
		inFile.ignore();
		for (size_t i = 0; i < noOfAns; i++)
		{
			getline(inFile, answer);
			this->answer.push_back(answer);
		}
		inFile >> correctAns;
		this->correctAnswer = correctAns;
		inFile.ignore();
	}
	else
		throw("Cold not open puzzle");
	inFile.close();
}
Puzzle::~Puzzle()
{
}

string Puzzle:: getAsstring()
{
	string answer = "";
	for (size_t i = 0; i < this->answer.size(); i++) 
	{
		answer  =answer+ to_string(i) + " : " + this->answer[i] + "\n";
	}
	
	/*return this->question + "\n" + "\n"
		+ answer + "\n"
		+ to_string(this->correctAnswer) + "\n";*/
	return this->question + "\n" + "\n"
		+ answer + "\n"
		 + "\n";

}