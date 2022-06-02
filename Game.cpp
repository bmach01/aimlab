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

	chooseShapeAndCustomiseIt();
	

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

	drawCustomShape();
	
	window->display();
}

void Game::chooseShapeAndCustomiseIt()
{
	whichShapeToDraw = rand() % 2;
	switch (whichShapeToDraw)
	{
	case 0:
		randomRectangle();
		break;
	case 1:
		randomCircle();
		break;
	default:
		break;
	}
}

void Game::drawCustomShape()
{
	switch (whichShapeToDraw)
	{
	case 0:
		window->draw(this->rectangle);
		break;
	case 1:
		window->draw(this->circle);
		break;
	default:
		break;
	}
}

void Game::randomRectangle()
{
	float length = static_cast<float>(rand() % 40 + 11);
	this->rectangle.setSize(sf::Vector2f(length,length));
	
	this->rectangle.setPosition(sf::Vector2f(
	static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - length)),
	static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - length))));

	this->rectangle.setFillColor(sf::Color::Red);
}
/* perhaps usefull if done well, custom polygon 
* 
void Game::randomConvex()
{
	float length = static_cast<float>(rand() % 40 + 11);
	this->convex.setPointCount(rand()%3+3);
	this->convex.setPoint(0 ,static_cast<float>( rand() % 3 + 3));

	this->convex.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - length)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - length))));

	this->convex.setFillColor(sf::Color::Red);
}
*/
void Game::randomCircle()
{
	float length = static_cast<float>(rand() % 40 + 11);
	this->circle.setRadius(length);

	this->circle.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - length)),
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - length))));

	this->circle.setFillColor(sf::Color::Red);
}


