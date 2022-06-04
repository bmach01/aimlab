#pragma once
#include"Shape.h"
//window size
constexpr int width = 800, height = 600;


class Game
{
private:
	// SFML window
	Shape shape;
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

