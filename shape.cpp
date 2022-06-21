#include "Shape.h"
std::mt19937 mt(time(nullptr));
std::uniform_int_distribution<int> genShapeType(0, 2);
std::uniform_int_distribution<int> genColor(0, 3);
std::uniform_real_distribution<float> genLength(50, 100);
std::uniform_real_distribution<float> genWidth(150, 1250);
std::uniform_real_distribution<float> genHeight(150, 650);

void Shape::chooseShapeAndCustomiseIt()
{
	if (isShapeNeeded) {
		isShapeNeeded = false;
		if (gameCurrentSettings.randomShape) {
			whichShapeToDraw = genShapeType(mt);
			switch (whichShapeToDraw)
			{
			case 0:
				randomRectangle();
				break;
			case 1:
				randomCircle();
				break;
			case 2:
				randomConvex();
				break;
			}
		}
		else {
			switch (gameCurrentSettings.targetShape)
			{
			case 0:
				randomCircle();
				break;
			case 1:
				randomRectangle();
				break;
			case 2:
				randomConvex();
				break;
			}
		}
	}
}

void Shape::randomRectangle()
{
	float length = genLength(mt);
	if (gameCurrentSettings.randomColor) {
		int colorNum = genColor(mt);
		switch (colorNum)
		{
		case 0:
			this->rectangle.setFillColor(sf::Color::White);
			break;
		case 1:
			this->rectangle.setFillColor(sf::Color::Red);
			break;
		case 2:
			this->rectangle.setFillColor(sf::Color::Blue);
			break;
		case 3:
			this->rectangle.setFillColor(sf::Color::Green);
			break;
		}
	}
	else {
		this->rectangle.setFillColor(gameCurrentSettings.targetColor);
	}
	if (gameCurrentSettings.randomSize) {
		this->rectangle.setSize(sf::Vector2f(length, length));
	}
	else {
		length = gameCurrentSettings.targetSize.x;
		this->rectangle.setSize(gameCurrentSettings.targetSize);
	}
	this->rectangle.setPosition(sf::Vector2f(genWidth(mt), genHeight(mt)));
}

void Shape::randomConvex()
{
	convex.setPointCount(3);

	float length = genLength(mt);

	if (gameCurrentSettings.randomColor) {
		int colorNum = genColor(mt);
		switch (colorNum)
		{
		case 0:
			this->convex.setFillColor(sf::Color::White);
			break;
		case 1:
			this->convex.setFillColor(sf::Color::Red);
			break;
		case 2:
			this->convex.setFillColor(sf::Color::Blue);
			break;
		case 3:
			this->convex.setFillColor(sf::Color::Green);
			break;
		}
	}
	else {
		this->convex.setFillColor(gameCurrentSettings.targetColor);
	}
	if (gameCurrentSettings.randomSize) {

		this->convex.setPoint(0, sf::Vector2f(0, 0));
		this->convex.setPoint(1, sf::Vector2f(length, 0));
		this->convex.setPoint(2, sf::Vector2f(length / 2, -(length / 2) * 1.7f));
	}
	else {
		length = gameCurrentSettings.targetSize.x;
		this->convex.setPoint(0, sf::Vector2f(0, 0));
		this->convex.setPoint(1, sf::Vector2f(length, 0));
		this->convex.setPoint(2, sf::Vector2f(length / 2, -(length / 2) * 1.7f));
	}

	this->convex.setPosition(sf::Vector2f(genWidth(mt), genHeight(mt)));
}

void Shape::randomCircle()
{
	float length = genLength(mt);
	if (gameCurrentSettings.randomColor) {
		int colorNum = genColor(mt);
		switch (colorNum)
		{
		case 0:
			this->circle.setFillColor(sf::Color::White);
			break;
		case 1:
			this->circle.setFillColor(sf::Color::Red);
			break;
		case 2:
			this->circle.setFillColor(sf::Color::Blue);
			break;
		case 3:
			this->circle.setFillColor(sf::Color::Green);
			break;
		}
	}
	else {
		this->circle.setFillColor(gameCurrentSettings.targetColor);
	}
	if (gameCurrentSettings.randomSize) {
		this->circle.setRadius(length);
	}
	else {
		length = gameCurrentSettings.targetSize.x;
		this->circle.setRadius(length / 2);
	}

	this->circle.setPosition(sf::Vector2f(genWidth(mt), genHeight(mt)));
}

void Shape::onClick()
{
	this->isShapeNeeded = true;
	this->circle.setRadius(0);
	this->rectangle.setSize(sf::Vector2f(0, 0));
	this->rectangle.setPosition(sf::Vector2f(0, 0));
	this->circle.setPosition(sf::Vector2f(0, 0));
	this->convex.setPosition(sf::Vector2f(0, 0));
}