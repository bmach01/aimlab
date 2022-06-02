#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>

class Game
{
private:
	// SFML window
	sf::RenderWindow* window;
	sf::Event event;
	sf::RectangleShape rectangle;
	sf::ConvexShape convex;
	sf::CircleShape circle;
	//is needed to cordinate customization and drawing
	unsigned int whichShapeToDraw{};
public:
	// (De)Constructor
	Game();
	virtual ~Game();

	// Access
	const bool isRunning();

	// Public functions
	void update();
	void polling();
	void draw();
	// chooseing a shape 
	void chooseShapeAndCustomiseIt();
	// drawing a shape
	void drawCustomShape();
	// shape customization
	void randomRectangle();
	void randomConvex();// deletable
	void randomCircle();
	
	
};


