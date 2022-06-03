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

enum class GameState { MainMenu, Settings, GameMode, Play, Exit };

class Game
{
private:
	// SFML window
	sf::RenderWindow* window;
	sf::Event event;

	// Font
	sf::Font mainFont;

	GameState gameState; // Lepszy bylby enum

	// Menu etc
	sf::RectangleShape mainMenuButtons[3]; // For menu polling detection
	sf::Text mainMenuTexts[4];
	sf::RectangleShape gameModeMenuButtons[3];
	void initiateMainMenu();
	void drawMainMenu();
	void pollMainMenu();

	sf::RectangleShape settingsMenuButtons[5];
	sf::Text settingsMenuTexts[5];
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


