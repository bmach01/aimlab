#include "Game.h"

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Rotating", sf::Style::Close);
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

}

void Game::polling()
{
	while (window->pollEvent(event)) {

		switch (event.type) {

		case sf::Event::Closed:
			window->close();
			break;

		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);



	window->display();
}
