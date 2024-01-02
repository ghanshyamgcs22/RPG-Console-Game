#include "Event.h"
#
Event::Event()
{
	this->noOfEvents = 2;
}
Event::~Event()
{

}
void Event::generateEvent(character &character,dArr<Enemey>& enemies)
{
	int i = rand()%this->noOfEvents;
	switch (i)
	{
	case 0:
		//enemy encounter
		enemyEncounter(character,enemies);
			break;
	case 1:
		//puzzle
		puzzleEncounter(character);
		break;

	default:
		break;
	}
}
//Different events
void Event::enemyEncounter(character& charactr, dArr<Enemey>& enemies)
{
	//while()
	bool playerTurn = false;

	//coin toss for turn
	int coinToss = rand() % 2 + 1;
	if (coinToss == 1)
	{
		playerTurn = true;
	}
	

	//end condditions
	bool escape = false;
	bool playerDefeated = false;
	bool enemyDefeated = false; 
	int choice;

	//Enemeies
	int noOfenemies = rand() % 5 + 1;


	for(int i=0;i<noOfenemies;i++)
	{
		enemies.push(Enemey(charactr.getlevel()));
	}
	
	//battle variable
	
	int damage=0;
	int gainExp = 0;
	
	int combatRoll=0;

	while (!escape&&!playerDefeated&&!enemyDefeated)
	{

		if(playerTurn&&!playerDefeated)
		{
			//Menue
			cout << " = BATTLE MENU = \n\n";
			cout << " 0: Escape\n";
			cout << " 1: Attack\n";
			cout << " 2: Defend\n";
			//cout << " 3: Use Item\n";
			cout << "\n";
			cout << "Choice : ";
			cin >> choice;
			while (cin.fail() || choice < 0||choice>3)
			{
				cout << "Faulty input" << "\n";
				cin.clear();
				cin.ignore(100, '\n');

				cout << " = BATTLE MENU = \n\n";
				cout << " 0: Escape\n";
				cout << " 1: Attack\n";
				cout << " 2: Defend\n";
				//cout << " 3: Use Item\n";
				cout << "\n";
				cout << "Choice : ";
				cin >> choice;

			}
			cin.ignore();
			cout << "\n";
			//Move

			switch (choice)
			{
			case 0://escape
				escape = true;
				break;

			case 1://attack

				//slect enemy
				cout << "Select Enemy: \n\n";
				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << " : " << " Level: " << enemies[i].getLevel() << " - " << " HP: " << enemies[i].getHp() << "/" << enemies[i].getHpMax() << endl;

				}
				cout << "\n";
				cout << "Choice : ";
				cin >> choice;
				while (cin.fail() || choice < 0 || choice>=enemies.size() )
				{
					
					cout << "Faulty input" << "\n";
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Select Enemy: \n\n";

					cout << "\n";
					cout << "Choice : ";
					cin >> choice;

				}
				cin.ignore();
				cout << "\n";
				
				//attack roll
				combatRoll = rand() % 100 + 1;
				if (combatRoll > 50)
					//hit
				{
					cout<<"\n\nHIT!\n\n";
					damage = charactr.getDamage();
					enemies[choice].takeDamage(charactr.getDamage());
					cout << "DAMAGE: " << damage << endl;
					if (!enemies[choice].isAlive())
					{
						cout << "ENEMY DEFEATED ! " << "\n\n";
						gainExp= enemies[choice].getExp();
						charactr.gainExp(enemies[choice].getExp());
						cout << "EXP Gained: " << gainExp << "\n\n";
						enemies.remove(choice);
					}
				}
				else//Miss
				{
					cout <<  "MISSED!\n\n";
				}
				break;

			case 2://defend
				break;

			//case 3://use item
				//break;


			default:
				break;
			}
		
			//Leave Turn
			playerTurn = false;
		}

		else if(!playerTurn&&!escape&&!enemyDefeated)
		{   //Enmemy attack
			for (int i = 0; i < enemies.size(); i++)
			{

			}
			//end turn
			playerTurn = true;
		}

		//conditions
		if (!charactr.isAlive())
		{
			playerDefeated = true;
		}
		else if (enemies.size() <= 0)
		{
			enemyDefeated = true;

		}
	}
}
void Event::puzzleEncounter(character& charactr)
{  
	cin.ignore();
	bool completed = false;
	int userAns = 0;
	int chances = 3;
	int getExp = rand() % (chances * charactr.getlevel() * rand() % 10 + 1)+50;

    Puzzle puzzle("Puzzles/1.txt");
	while (!completed&&chances>=0)
	{
		cout <<"Chances" << chances << "\n\n";
		chances--;

		cout<<puzzle.getAsstring()<<"\n";
		cout << "\n Your answer:";
		cin >> userAns;
		cout << "\n";
		while (cin.fail())
		{

			cout << "Faulty input" << "\n";
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n" << "choice" << "\n";
			cin >> userAns;
		}

		cin.ignore(100, '\n');
		cout << "\n";
		if (puzzle.grtcorrectAns() == userAns)
		{
			 completed = true;


			 charactr.gainExp(getExp);
			//Give user exp etc and continue

		}
		if (completed)
			cout << "Correct You succeded! \n \n";

		else
		{
			cout<< "You Failed Brah\n \n";
		}
	}
}