#pragma once
#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

// Window size
constexpr int width = 1400, height = 800;

// Struct containing global settings
struct Settings {
	bool randomColor = false;
	sf::Color targetColor = sf::Color::Red;

	bool randomSize = false;
	sf::Vector2f targetSize = sf::Vector2f(50.f, 50.f);

	bool randomShape = false;
	short int targetShape = 0; // 0 - circle, 1 - square, etc.
};



class Game
{
private:
	// SFML window
	sf::RenderWindow* window;
	sf::Event event;

	// Font
	sf::Font mainFont;

	// Menus
	short int gameState; // Lepszy bylby enum
	std::array<sf::RectangleShape, 5> currentButtons; // For menu polling detection

	void drawMainMenu();
	void pollMainMenu();
	void drawGameModeMenu();
	void drawSettingsMenu();

	// Settings struct
	Settings currentSettings;
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


