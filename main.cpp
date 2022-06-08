#include "Game.h"

int main() {
	std::cout << "START\n";
	
	Shape shape;
	Game game(&shape);
	

	while (game.isRunning()) {

		game.update();

		game.draw();
	}

	std::cout << "FINISH\n";
	return 0;
}