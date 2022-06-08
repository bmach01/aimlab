#include "Game.h"

int main() {
	std::cout << "START\n";
	
	Shape shape;
	Game game(&shape);
	game.chrset();
	std::cout << shape.gameCurrentSettings.randomColor << "\n";
	game.shareSettings();
	std::cout << shape.gameCurrentSettings.randomColor << "\n";


	while (game.isRunning()) {

		game.update();

		game.draw();
	}

	std::cout << "FINISH\n";
	return 0;
}