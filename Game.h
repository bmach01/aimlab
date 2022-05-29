#pragma once
#include <SFML/Graphics.hpp>

class Game
{
private:
	// SFML window
	sf::RenderWindow* window;
	sf::Event event;


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
};

/*
TEST 
podaje has�o 
lubie w dupe 
*/