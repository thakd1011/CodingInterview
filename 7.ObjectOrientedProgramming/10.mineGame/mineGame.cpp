#include "Game.h"
#include <iostream>

int main() {
	Game* game = new Game();

	game->initialize();
	game->gameStart();
}
