#include "game.h"

int main() {
	//init srand
	std::srand(static_cast<unsigned>(time(NULL)));
	 
	Game game;
	Shape shape;
	
	while (game.isRunning()) {

		game.update();
		
		game.draw();
	}

	
	return 0;
}