#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "Rotating", sf::Style::Close);
	window->setFramerateLimit(60);

}

Game::~Game()
{
	delete window;
}

const bool Game::isRunning()
{
	return window->isOpen();
}

void Game::update()
{
	polling();

	shape.chooseShapeAndCustomiseIt();
	

}

void Game::polling()
{
	while (window->pollEvent(event)) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//to do: check the position, options 
			switch (shape.whichShapeToDraw) {
			case 0:
				break;
			case 1:
				
				break;

			}


		}
	}
}



void Game::draw()
{
	window->clear(sf::Color::Black);

	switch (shape.whichShapeToDraw)
	{
	case 0:
		window->draw(shape.rectangle);
		break;
	case 1:
		window->draw(shape.circle);
		break;
	
	}
	window->display();
}

