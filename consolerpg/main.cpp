#include "Game.h"
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(NULL)));
	//int level = 2;
	//int i= static_cast<int>((50.0 / 3.0) * (pow(static_cast<double>(level), 3.0) - 6.0 * pow(static_cast<double>(level), 2.0) + (17.0 * static_cast<double>(level)) - 11.0));
	//cout << i << "\n";
	Game game;
	game.initGame();
	inventory inv;
	//inv.addItem(Item());
	//inv.addItem(Item());
	//inv.addItem(Item());
	inv.debugPrint();
	while (game.getPlaying())
	{
		game.mainMenu();
	}
	return 0;
}