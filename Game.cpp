#include "Game.h"

void Game::drawMenus()
{
	// Drawing correct buttsons and text
	for (auto button : getCurrentButtons()) {
		window->draw(button);
	}
	for (auto text : getCurrentTexts()) {
		window->draw(text);
	}

}

void Game::initiateMainMenu()
{
	// Title 
	mainMenuTexts[3].setFont(mainFont);
	mainMenuTexts[3].setString("AimLab");
	mainMenuTexts[3].setCharacterSize(90);
	mainMenuTexts[3].setFillColor(sf::Color::White);
	mainMenuTexts[3].setOrigin(mainMenuTexts[3].getGlobalBounds().width / 2, mainMenuTexts[3].getGlobalBounds().height / 2);
	mainMenuTexts[3].setPosition(width / 2, height / 4);

	// Menu buttons texts
	mainMenuTexts[0].setString("play");
	mainMenuTexts[1].setString("settings");
	mainMenuTexts[2].setString("exit");

	// Buttons and texts looks and positions
	for (int i = 0; i < 3; i++) {
		mainMenuButtons[i].setOutlineColor(sf::Color::White);
		mainMenuButtons[i].setOutlineThickness(5.f);
		mainMenuButtons[i].setFillColor(sf::Color::Black);
		mainMenuButtons[i].setSize(sf::Vector2f(300.f, 80.f));
		mainMenuButtons[i].setPosition(width / 2, (height + 200 * i) / 2);
		mainMenuButtons[i].setOrigin(150.f, 40.f);

		mainMenuTexts[i].setFont(mainFont);
		mainMenuTexts[i].setFillColor(sf::Color::White);
		mainMenuTexts[i].setCharacterSize(50);
		mainMenuTexts[i].setOrigin(mainMenuTexts[i].getGlobalBounds().width / 2, mainMenuTexts[i].getGlobalBounds().height / 2);
		mainMenuTexts[i].setPosition(mainMenuButtons[i].getPosition().x, mainMenuButtons[i].getPosition().y - 10); // To jest voodoo/Stala Mimora
	}
}

void Game::supportMainMenu(int button_id)
{
	switch (button_id) {
	case 0:
		gameState = GameState::GameMode;
		return;
	case 1:
		gameState = GameState::Settings;
		return;
	case 2:
		window->close();
		return;
	}
}

void Game::initiateGameModeMenu()
{
	// Main text
	gameModeMenuTexts[2].setString("Choose a game mode");
	gameModeMenuTexts[2].setFont(mainFont);
	gameModeMenuTexts[2].setFillColor(sf::Color::White);
	gameModeMenuTexts[2].setCharacterSize(70);
	gameModeMenuTexts[2].setOrigin(gameModeMenuTexts[2].getGlobalBounds().width / 2, gameModeMenuTexts[2].getGlobalBounds().height / 2);
	gameModeMenuTexts[2].setPosition(width / 2, height / 4);

	// Texts
	gameModeMenuTexts[0].setString("Classic");
	gameModeMenuTexts[1].setString("Survival");

	// Graphic settings for both buttons and texts
	for (int i = 0; i < 2; i++) {
		gameModeMenuButtons[i].setOutlineColor(sf::Color::White);
		gameModeMenuButtons[i].setOutlineThickness(5.f);
		gameModeMenuButtons[i].setFillColor(sf::Color::Black);
		gameModeMenuButtons[i].setSize(sf::Vector2f(300.f, 80.f));
		gameModeMenuButtons[i].setPosition((width / 3) * (i + 1), height / 2);
		gameModeMenuButtons[i].setOrigin(150.f, 40.f);

		gameModeMenuTexts[i].setFont(mainFont);
		gameModeMenuTexts[i].setFillColor(sf::Color::White);
		gameModeMenuTexts[i].setCharacterSize(50);
		gameModeMenuTexts[i].setOrigin(gameModeMenuTexts[i].getGlobalBounds().width / 2, gameModeMenuTexts[i].getGlobalBounds().height / 2);
		gameModeMenuTexts[i].setPosition(gameModeMenuButtons[i].getPosition().x, gameModeMenuButtons[i].getPosition().y - 10);
	}
}

void Game::supportGameModeMenu(int button_id)
{
	switch (button_id) {
	case 0:
		gameState = GameState::Play;
		return;
	case 1:
		//survival
		return;
	case 2:
		gameState = GameState::MainMenu;
		return;
	}
}

void Game::initiateSettingsMenu()
{
	// Options texts
	settingsMenuTexts[0].setString("Target color: ");
	settingsMenuTexts[1].setString("Random target color: ");
	settingsMenuTexts[2].setString("Target size: ");
	settingsMenuTexts[3].setString("Random target size: ");
	settingsMenuTexts[4].setString("Target shape: ");
	settingsMenuTexts[5].setString("Random target shape: ");

	// Texts looks
	for (int i = 0; i < 6; i++) {
		settingsMenuTexts[i].setFont(mainFont);
		settingsMenuTexts[i].setFillColor(sf::Color::White);
		settingsMenuTexts[i].setCharacterSize(40);
		settingsMenuTexts[i].setPosition(width / 10, (height / 7) * (i + 1));
	}

	// Color buttons
	settingsMenuButtons[0].setFillColor(sf::Color::White);
	settingsMenuButtons[1].setFillColor(sf::Color::Blue);
	settingsMenuButtons[2].setFillColor(sf::Color::Red);
	settingsMenuButtons[3].setFillColor(sf::Color::Green);


	// Position in correct rows
	// COLOR / SIZE / SHAPE rows
	for (int i = 0; i <= 3; i++) {
		settingsMenuButtons[i].setPosition(width / 2 + i * 100.f,
			settingsMenuTexts[0].getPosition().y - 20.f);
		settingsMenuButtons[i].setSize(sf::Vector2f(80.f, 80.f));
		settingsMenuButtons[i].setOutlineThickness(2.f);
	}

	// Random color
	settingsMenuButtons[4].setSize(sf::Vector2f(80.f, 80.f));
	settingsMenuButtons[4].setOutlineThickness(2.f);
	settingsMenuButtons[4].setPosition(width / 2, settingsMenuTexts[1].getPosition().y - 20.f); // Random color
	settingsMenuButtons[4].setTexture(&falsemark, false);


	// Size buttons
	float spaceBetween{};
	for (int i = 5; i <= 7; i++) {
		settingsMenuButtons[i].setSize(sf::Vector2f(25.f * (i - 3), 25.f * (i - 3)));
		settingsMenuButtons[i].setPosition(width / 2 + spaceBetween,
			settingsMenuTexts[2].getPosition().y + 60.f - i * 12.5f);
		spaceBetween += settingsMenuButtons[i].getSize().x + 50.f;

		settingsMenuButtons[i].setFillColor(sf::Color::Black);
		settingsMenuButtons[i].setOutlineThickness(2.f);
	}
	// Random size
	settingsMenuButtons[8].setSize(sf::Vector2f(80.f, 80.f));
	settingsMenuButtons[8].setOutlineThickness(2.f);
	settingsMenuButtons[8].setPosition(width / 2, settingsMenuTexts[3].getPosition().y - 20.f); // Random size
	settingsMenuButtons[8].setTexture(&falsemark, false);

	// Shape buttons
	for (int i = 9; i <= 11; i++) {
		settingsMenuButtons[i].setPosition(width / 2 + (i - 9) * 100.f,
			settingsMenuTexts[4].getPosition().y - 20.f);
		settingsMenuButtons[i].setSize(sf::Vector2f(80.f, 80.f));
		settingsMenuButtons[i].setOutlineThickness(2.f);
	}
	settingsMenuButtons[9].setTexture(&circle, false);
	settingsMenuButtons[11].setTexture(&pentagon, false);

	// Random shape
	settingsMenuButtons[12].setSize(sf::Vector2f(80.f, 80.f));
	settingsMenuButtons[12].setOutlineThickness(2.f);
	settingsMenuButtons[12].setPosition(width / 2, settingsMenuTexts[5].getPosition().y - 20.f); // Random shape
	settingsMenuButtons[12].setTexture(&falsemark, false);

}

void Game::supportSettingsMenu(int button_id)
{
	switch (button_id) {
	case 0:
		currentSettings.targetColor = sf::Color::White;
		return;
	case 1:
		currentSettings.targetColor = sf::Color::Blue;
		return;
	case 2:
		currentSettings.targetColor = sf::Color::Red;
		return;
	case 3:
		currentSettings.targetColor = sf::Color::Green;
		return;
	case 4:
		currentSettings.randomColor = !currentSettings.randomColor;
		if (!currentSettings.randomColor)
			settingsMenuButtons[4].setTexture(&falsemark, false);
		else {
			settingsMenuButtons[4].setTexture(&truemark, false);
		}
		return;
	case 5:
		currentSettings.targetSize = sf::Vector2f(50.f, 50.f);
		return;
	case 6:
		currentSettings.targetSize = sf::Vector2f(75.f, 75.f);
		return;
	case 7:
		currentSettings.targetSize = sf::Vector2f(100.f, 100.f);
		return;
	case 8:
		currentSettings.randomSize = !currentSettings.randomSize;
		if (!currentSettings.randomSize)
			settingsMenuButtons[8].setTexture(&falsemark, false);
		else {
			settingsMenuButtons[8].setTexture(&truemark, false);
		}
		return;
	case 9:
		currentSettings.targetShape = 0; // Circle
		return;
	case 10:
		currentSettings.targetShape = 1; // Square
		return;
	case 11:
		currentSettings.targetShape = 2; // Else
		return;
	case 12:
		currentSettings.randomShape = !currentSettings.randomShape;
		if (!currentSettings.randomShape)
			settingsMenuButtons[12].setTexture(&falsemark, false);
		else {
			settingsMenuButtons[12].setTexture(&truemark, false);
		}
		return;
	case 13:
		gameState = GameState::MainMenu;
		std::cout << "SHARE SETTINGS GAME SETTINGS MENU AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAa\n";
		shareSettings();
		return;
	}
}

void Game::loadTexturesFonts()
{
	// Load font
	if (!mainFont.loadFromFile("texturesandfonts/HighlandGothicFLF.ttf") ||
		!pentagon.loadFromFile("texturesandfonts/pentagon.png") ||
		!circle.loadFromFile("texturesandfonts/circle.png") ||
		!falsemark.loadFromFile("texturesandfonts/false.png") ||
		!truemark.loadFromFile("texturesandfonts/true.png"))
	{
		window->close();
	}
	
	truemark.setSmooth(true);
	falsemark.setSmooth(true);
	pentagon.setSmooth(true);
	circle.setSmooth(true);
}

std::vector<sf::RectangleShape> Game::getCurrentButtons()
{
	std::vector<sf::RectangleShape> currentButtons;
	switch (gameState) {
	case GameState::MainMenu:
		currentButtons.insert(currentButtons.begin(), std::begin(mainMenuButtons), std::end(mainMenuButtons));
		return currentButtons;
	case GameState::Settings:
		currentButtons.insert(currentButtons.begin(), std::begin(settingsMenuButtons), std::end(settingsMenuButtons));
		currentButtons.push_back(backButton);
		return currentButtons;
	case GameState::GameMode:
		currentButtons.insert(currentButtons.begin(), std::begin(gameModeMenuButtons), std::end(gameModeMenuButtons));
		currentButtons.push_back(backButton);
		return currentButtons;
	}
}

std::vector<sf::Text> Game::getCurrentTexts()
{
	std::vector<sf::Text> currentTexts;
	switch (gameState) {
	case GameState::MainMenu:
		currentTexts.insert(currentTexts.begin(), std::begin(mainMenuTexts), std::end(mainMenuTexts));
		return currentTexts;
	case GameState::Settings:
		currentTexts.insert(currentTexts.begin(), std::begin(settingsMenuTexts), std::end(settingsMenuTexts));
		currentTexts.push_back(backText);
		return currentTexts;
	case GameState::GameMode:
		currentTexts.insert(currentTexts.begin(), std::begin(gameModeMenuTexts), std::end(gameModeMenuTexts));
		currentTexts.push_back(backText);
		return currentTexts;
	}
}

void Game::initiateBackButton()
{
	backButton.setOutlineColor(sf::Color::White);
	backButton.setOutlineThickness(5.f);
	backButton.setFillColor(sf::Color::Black);
	backButton.setSize(sf::Vector2f(300.f, 80.f));
	backButton.setPosition(width - 200.f, height - 80.f);
	backButton.setOrigin(150.f, 40.f);

	backText.setString("back");
	backText.setFont(mainFont);
	backText.setFillColor(sf::Color::White);
	backText.setCharacterSize(70);
	backText.setOrigin(backText.getGlobalBounds().width / 2, backText.getGlobalBounds().height / 2);
	backText.setPosition(backButton.getPosition().x, backButton.getPosition().y - 10);
}

void Game::pollMenus()
{
	// On left mouse press
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)); // mouse position relative to window
		std::vector<sf::RectangleShape>currentButtons = getCurrentButtons();

		for (int i = 0; i < currentButtons.size(); i++) { // iterate through all current buttons
			if (currentButtons[i].getGlobalBounds().contains(mousePos)) {

				// Correct button support
				switch (gameState) {
				case GameState::MainMenu:
					supportMainMenu(i);
					return;
				case GameState::GameMode:
					supportGameModeMenu(i);
					return;
				case GameState::Settings:
					supportSettingsMenu(i);
					return;
				}
			}
		}
	}
}

Game::Game(Shape *sh)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "AimLab", sf::Style::Close);
	window->setFramerateLimit(60);
	gameState = GameState::MainMenu;
	shape = sh;
	shareSettings();

	loadTexturesFonts();
	initiateBackButton();
	initiateMainMenu();
	initiateGameModeMenu();
	initiateSettingsMenu();
}

Game::~Game()
{
	delete window;
}

const bool Game::isRunning()
{
	return window->isOpen();
}

void Game::shareSettings()
{
	shape->gameCurrentSettings = currentSettings;
	std::cout << "SHAPE " << shape->gameCurrentSettings.randomShape << " : " << currentSettings.randomShape << " GAME\n";
}

void Game::chrset()
{
	std::cout << currentSettings.randomColor << "GAME\n";
	currentSettings.randomColor = true;
	std::cout << currentSettings.randomColor << "GAME\n";
}

void Game::update()
{
	polling();
	//useShape();
	shape->chooseShapeAndCustomiseIt();

}

void Game::polling()
{
	while (window->pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			window->close();

		if (gameState != GameState::Play)
			pollMenus();
		else {
			//pollGame();
		}

	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	if (gameState != GameState::Play) {
		drawMenus();
	}
	else {
		std::cout << "PLAY\n";
		if (currentSettings.randomShape) {
			std::cout << "RANDOMSHAPE\n";
			switch (shape->whichShapeToDraw)
			{
			case 0:
				window->draw(shape->rectangle);
				break;
			case 1:
				window->draw(shape->circle);
				break;
			case 2:
				window->draw(shape->convex);
				break;
			}
		}
		else {
			std::cout << "NONRANDOMSHAPE\n";
			switch (currentSettings.targetShape)
			{
			case 0:
				std::cout << shape->circle.getRadius() << "\n";
				window->draw(shape->circle);
				break;
			case 1:
				window->draw(shape->rectangle);
				break;
			case 2:
				window->draw(shape->convex);
				break;
			}
		}
	}

	window->display();
}
