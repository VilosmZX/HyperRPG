#include <iostream>
#include "Game.h"

int main()
{
	Game game("Game", 800, 600, 60);
	game.init();
	game.events();
	game.loop();

	return 0;
}