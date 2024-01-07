#include <iostream>
#include "Game.h"


const int W = 1240, H = 720;

int main() {
	// initialize Game
	Game game;

	// Loop
	while (game.running()) {
		

		// Update
		game.update();

		// Render
		game.render();

		
	}
	return 0;
}