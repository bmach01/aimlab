#include "Shape.h"
std::mt19937 mt;
Shape::Shape()
{
	//std::cout << gameCurrentSettings.randomSize << "shape struct\n";
}

void Shape::chooseShapeAndCustomiseIt()
{
	//std::cout << gameCurrentSettings.randomShape << " choosehsape random shape\n";
	//std::cout << isShapeNeeded << "is shape needed " << "\n";
	if (true) {
		//std::cout << "is shape needed " << isShapeNeeded << "\n";
		isShapeNeeded = false;
		if (gameCurrentSettings.randomShape) {
			whichShapeToDraw = mt() % 3;
			//std::cout << "WHICH SHAPE TO DRAW AAAAAA " << whichShapeToDraw << "\n";
			switch (whichShapeToDraw)
			{
			case 0:
				//std::cout << "WhichShapeToDraw " << whichShapeToDraw << "\n";
				randomRectangle();
				break;
			case 1:
				//std::cout << "WhichShapeToDraw " << whichShapeToDraw << "\n";

				randomCircle();
				break;
			case 2:
				randomConvex();
				//std::cout << "WhichShapeToDraw " << whichShapeToDraw << "\n";

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
	float length = static_cast<float>(mt()%50+50);
	if (gameCurrentSettings.randomColor) {
		int colorNum = mt() % 4;
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
	this->rectangle.setPosition(sf::Vector2f(
		static_cast<float>(mt() % static_cast<int>(width - length)),
		static_cast<float>(mt() % static_cast<int>(height - length))));
	//this->rectangle.setPosition(sf::Vector2f(0,0));
}

void Shape::randomConvex()
{

	convex.setPointCount(3);

	float length = static_cast<float>(mt() % 50 + 50);

	if (gameCurrentSettings.randomColor) {
		std::cout << "random kolor" << gameCurrentSettings.randomColor << "\n";
		int colorNum = (mt() % 4);
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

	this->convex.setPosition(sf::Vector2f(
		static_cast<float>(mt() % static_cast<int>(width - length)),
		static_cast<float>(mt() % static_cast<int>(height- ((length / 2) * 1.7f)))+ ((length / 2) * 1.7f)));


}

void Shape::randomCircle()
{
	//std::cout << "JA jebix\n";
	float length = static_cast<float>(mt() % 50 + 50);
	//float length = 50.f;
	if (gameCurrentSettings.randomColor) {
		int colorNum = (mt() % 4);
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
		//std::cout << gameCurrentSettings.randomSize << "RANDOM_SIZE\n";
		this->circle.setRadius(length);
	}
	else {
		//std::cout << gameCurrentSettings.randomSize << "NONRANDOM_SIZE\n";

		length = gameCurrentSettings.targetSize.x;
		this->circle.setRadius(gameCurrentSettings.targetSize.x);
	}

	this->circle.setPosition(sf::Vector2f(
		static_cast<float>(mt() % static_cast<int>(width - length*2)),
		static_cast<float>(mt() % static_cast<int>(height - length*2))));
	//this->circle.setPosition(sf::Vector2f(0,0));


}

void Shape::onClick()
{
	this->isShapeNeeded = true;
	this->circle.setRadius(0);
	this->rectangle.setSize(sf::Vector2f(0, 0));
	this->rectangle.setPosition(sf::Vector2f(-1.f, -1.f));
	this->circle.setPosition(sf::Vector2f(-1.f, -1.f));
	this->convex.setPoint(0, sf::Vector2f(0, 0));
	this->convex.setPoint(1, sf::Vector2f(0, 0));
	this->convex.setPoint(2, sf::Vector2f(0, 0));
	this->convex.setPosition(sf::Vector2f(-1.f, -1.f));
}