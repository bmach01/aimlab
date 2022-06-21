#include "Classic.h"

Classic::Classic()
{
	timer = new sf::Clock;
	init();
}

Classic::~Classic()
{
	delete timer;
}

void Classic::pushClick(sf::Vector2f mousePos, sf::CircleShape currentShape)
{
	double distance{};
	float shape_x = currentShape.getPosition().x + currentShape.getRadius();
	float shape_y = currentShape.getPosition().y + currentShape.getRadius();
	distance = sqrt(pow(mousePos.x - shape_x, 2) + pow(mousePos.y - shape_y, 2)); // Calculates distance between
	clicksRange += distance;
}

void Classic::init()
{
	timer->restart();
	gameLength = 20;
	currentLength = 0;
	clicksRange = 0;
}

const bool Classic::stillPlaying()
{
	if (currentLength >= gameLength)
		return false;
	return true;
}

const double Classic::getAccuracy()
{
	return clicksRange / gameLength;
}

const double Classic::getTime()
{
	return timer->getElapsedTime().asMilliseconds() / gameLength;
}
