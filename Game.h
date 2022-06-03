#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>

//window size
constexpr int width = 800, height = 600;

class Game
{
private:
	// SFML window
	
	sf::Event event;
	sf::RenderWindow* window;
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
	
	void returmWindow();
	
};

class Shape {
private:
	sf::RectangleShape rectangle;
	sf::ConvexShape convex;
	sf::CircleShape circle;
	//is needed to cordinate customization and drawing
	unsigned int whichShapeToDraw{};
public:
	// chooseing a shape 
	void chooseShapeAndCustomiseIt();
	// drawing a shape
	//void drawCustomShape();
	// shape customization
	void randomRectangle();
	void randomConvex();// deletable
	void randomCircle();
};
