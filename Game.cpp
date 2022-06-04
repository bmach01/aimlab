#include "Game.h"

void Game::drawMenus()
{
	// Containers for current state of game buttons and texts
	std::vector<sf::RectangleShape> currentButtons;
	std::vector<sf::Text> currentTexts;

	switch (gameState) {
	case GameState::MainMenu:
		currentButtons.insert(currentButtons.begin(), std::begin(mainMenuButtons), std::end(mainMenuButtons));
		currentTexts.insert(currentTexts.begin(), std::begin(mainMenuTexts), std::end(mainMenuTexts));
		break;
	case GameState::Settings:
		currentButtons.insert(currentButtons.begin(), std::begin(settingsMenuButtons), std::end(settingsMenuButtons));
		currentTexts.insert(currentTexts.begin(), std::begin(settingsMenuTexts), std::end(settingsMenuTexts));
		currentButtons.push_back(backButton);
		currentTexts.push_back(backText);
		break;
	case GameState::GameMode:
		currentButtons.insert(currentButtons.begin(), std::begin(gameModeMenuButtons), std::end(gameModeMenuButtons));
		currentTexts.insert(currentTexts.begin(), std::begin(gameModeMenuTexts), std::end(gameModeMenuTexts));
		currentButtons.push_back(backButton);
		currentTexts.push_back(backText);
		break;
	}

	// Drawing correct buttsons and text
	for (auto button : currentButtons) {
		window->draw(button);
	}
	for (auto text : currentTexts) {
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

	// Buttons looks
	for (int i = 0; i < 13; i++) {
		settingsMenuButtons[i].setSize(sf::Vector2f(80.f, 80.f));
		settingsMenuButtons[i].setFillColor(sf::Color::Black);
		settingsMenuButtons[i].setOutlineThickness(2.f);
	}

	// Color buttons
	settingsMenuButtons[0].setFillColor(sf::Color::White);
	settingsMenuButtons[1].setFillColor(sf::Color::Blue);
	settingsMenuButtons[2].setFillColor(sf::Color::Red);
	settingsMenuButtons[3].setFillColor(sf::Color::Green);


	// Position in correct rows
	// COLOR / SIZE / SHAPE rows
	for (int i = 0; i < 4; i++) {
		settingsMenuButtons[i].setPosition(width / 2 + i * 100.f,
			settingsMenuTexts[0].getPosition().y - 20.f);
	}
	// Size buttons
	for (int i = 4; i < 7; i++) {
		settingsMenuButtons[i].setPosition(width / 2 + (i - 4) * 100.f,
			settingsMenuTexts[2].getPosition().y - 20.f);
	}
	// Shape buttons
	for (int i = 7; i < 10; i++) {
		settingsMenuButtons[i].setPosition(width / 2 + (i - 7) * 100.f,
			settingsMenuTexts[4].getPosition().y - 20.f);
	}

	// Random buttons
	settingsMenuButtons[10].setPosition(width / 2, settingsMenuTexts[1].getPosition().y - 20.f);
	settingsMenuButtons[11].setPosition(width / 2, settingsMenuTexts[3].getPosition().y - 20.f);
	settingsMenuButtons[12].setPosition(width / 2, settingsMenuTexts[5].getPosition().y - 20.f);

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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
	
		for (int i = 0; i < 3; i++) {
			sf::Vector2i mousePos(event.mouseButton.x + mainMenuButtons[i].getOrigin().x, event.mouseButton.y + mainMenuButtons[i].getOrigin().y);
			if (mainMenuButtons[i].getPosition().x <= mousePos.x &&
				mainMenuButtons[i].getPosition().y <= mousePos.y &&
				mainMenuButtons[i].getPosition().x + mainMenuButtons[i].getSize().x >= mousePos.x && // TO POWINNO SIE DAC LEPIEJ???
				mainMenuButtons[i].getPosition().y + mainMenuButtons[i].getSize().y >= mousePos.y)
			{
				switch (i) {
				case 0:
					gameState = GameState::GameMode;
					break;
				case 1:
					gameState = GameState::Settings;
					break;
				case 2:
					window->close();
				}
				return;
			}
		}

	}
	
}

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "AimLab", sf::Style::Close);
	window->setFramerateLimit(60);
	gameState = GameState::MainMenu;
	
	// Load font
	if (!mainFont.loadFromFile("HighlandGothicFLF.ttf"))
	{
		// Error
		std::cout << "Cannot load fonts!\n";
		window->close();
	}

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

void Game::update()
{
	polling();

}

void Game::polling()
{
	while (window->pollEvent(event)) {

		if (event.type == sf::Event::Closed)
			window->close();

		if (gameState != GameState::Play)
			pollMenus();

	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	if (gameState != GameState::Play)
		drawMenus();
	else {
		//draw targets and shiet
	}

	window->display();
}
