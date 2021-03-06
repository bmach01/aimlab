#pragma once
#include "Shape.h"

class Game
{
private:
	// SFML window
	sf::RenderWindow *window;
	sf::Event event;
	Settings currentSettings;
	bool clicked = false;

	// Font and textures
	sf::Texture circle;
	sf::Texture pentagon;
	sf::Texture truemark;
	sf::Texture falsemark;
	sf::Font mainFont;
	void loadTexturesFonts();

	// Supporting all menus
	GameState gameState;
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
	
	// Game over screens
	sf::Text gameOverTexts[4];
	void initiateGameOverMenu();

	// Game 
	sf::Vector2f mousePos;
	void pollGame();
	Shape* shape;
	Classic* classic;
	Survival* survival;
	void saveRecords();

	// Settings menu
	sf::RectangleShape settingsMenuButtons[13];
	sf::Text settingsMenuTexts[6];
	void initiateSettingsMenu();
	void supportSettingsMenu(int button_id);

public:
	// (De)Constructor
	Game(Shape *sh, Classic *clas, Survival *surv);
	virtual ~Game();

	// Access
	const bool isRunning();
	void shareSettings();

	// Public functions
	void update();
	void polling();
	void draw();
};