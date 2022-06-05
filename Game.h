#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>
#include"Shape.h"
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

	Shape shape;
	sf::Event event;

	sf::RenderWindow* window;
	sf::Event event;

	// Font and textures
	sf::Texture circle;
	sf::Texture pentagon;
	sf::Texture truemark;
	sf::Texture falsemark;
	sf::Font mainFont;
	void loadTexturesFonts();

	// Supporting all menus
	GameState gameState;
	Settings currentSettings;
	sf::RectangleShape backButton;
	sf::Text backText;
	std::vector<sf::RectangleShape> getCurrentButtons(); // Return correct set of buttons for current game state
	std::vector<sf::Text> getCurrentTexts();
	void initiateBackButton();
	void pollMenus();
	void drawMenus();
	
	// Main menu
	sf::RectangleShape mainMenuButtons[3]; // For menu polling detection
	sf::Text mainMenuTexts[4];
	void initiateMainMenu();
	void supportMainMenu(int button_id); // Specific buttons make specific things happen! *woosh*

	// Game mode menu
	sf::RectangleShape gameModeMenuButtons[2];
	sf::Text gameModeMenuTexts[3];
	void initiateGameModeMenu();
	void supportGameModeMenu(int button_id);

	// Settings menu
	sf::RectangleShape settingsMenuButtons[13];
	sf::Text settingsMenuTexts[6];
	void initiateSettingsMenu();
	void supportSettingsMenu(int button_id);
  
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
	
	void returnWindow();
	
};

