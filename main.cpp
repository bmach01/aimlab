#include "Game.h"

int main() {

	Shape shape;
	Game game(&shape);

	while (game.isRunning()) {

		game.update();
		
		game.draw();
	}

	return 0;
}