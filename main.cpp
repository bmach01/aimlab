#include "Game.h"

int main() {
	Classic classic;
	Survival survival;
	Shape shape;
	Game game(&shape, &classic, &survival);
	

	while (game.isRunning()) {

		game.update();

		game.draw();
	}

	return 0;
}