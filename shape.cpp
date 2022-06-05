#include "Game.h"
void Shape::chooseShapeAndCustomiseIt()
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
	}
}
/*
void Shape::drawCustomShape()
{
	switch (whichShapeToDraw)
	{
	case 0:
		game.window->draw(this->rectangle);
		break;
	case 1:
		window->draw(this->circle);
		break;
	default:
		break;
	}
}*/

void Shape::randomRectangle()
{
	float length = static_cast<float>(rand() % 40 + 11);
	this->rectangle.setSize(sf::Vector2f(length, length));

	this->rectangle.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(width - length)),
		static_cast<float>(rand() % static_cast<int>(height - length))));

	this->rectangle.setFillColor(sf::Color::Red);
}
/* perhaps usefull if done well, custom polygon
*
void Shape::randomConvex()
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
void Shape::randomCircle()
{
	float length = static_cast<float>(rand() % 40 + 11);
	this->circle.setRadius(length);

	this->circle.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(width - length)),
		static_cast<float>(rand() % static_cast<int>(height - length))));

	this->circle.setFillColor(sf::Color::Red);
}


