#include "Shape.h"

int main() {
	std::cout << "START\n";

	Game game;
	Shape shape(&game);
	//game.shape = &shape;

	while (game.isRunning()) {

		game.update();

		game.draw();
	}

	std::cout << "FINISH\n";
	return 0;
}