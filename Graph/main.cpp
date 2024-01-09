#include <iostream>
#include "Game.h"


int main() {
	// Initialize srand
	std::srand(static_cast<unsigned>(time(NULL)));

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