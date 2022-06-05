#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
class Game;
class Shape {
private:
	Game game;
public:

	bool isShapeNeeded = true;
	sf::RectangleShape rectangle;
	sf::ConvexShape convex;//deletable
	sf::CircleShape circle;
	//is needed to cordinate customization and drawing
	short int whichShapeToDraw{};

	// chooseing a shape 
	void chooseShapeAndCustomiseIt();
	// drawing a shape
	//void drawCustomShape();
	// shape customization
	void randomRectangle();
	void randomConvex();// deletable
	void randomCircle();
	
	void onClick();
};