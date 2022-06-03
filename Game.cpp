#include "Game.h"


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

	// Graphic customization
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

void Game::drawMainMenu()
{
	for (int i = 0; i < 3; i++) {
		window->draw(mainMenuButtons[i]);
		window->draw(mainMenuTexts[i]);
	}
	window->draw(mainMenuTexts[3]);
}

void Game::pollMainMenu()
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
					gameState = GameState::Play;
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

	initiateMainMenu();
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

		switch (gameState) {
		case GameState::MainMenu:
			pollMainMenu();
			break;
		case GameState::Settings:
			// Ogarnia klikanie w opcjach
			break;
		case GameState::GameMode:
			// Ogarnia klikanie wyboru trybu
			break;
		case GameState::Play:
			// Ogarnia klikanie we wlasciwej grze
			break;
		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	switch (gameState) {
	case GameState::MainMenu:
		drawMainMenu();
		break;
	case GameState::Settings:
		//drawSettingsMenu();
		break;
	case GameState::GameMode:
		//drawGameModeMenu();
		break;
	case GameState::Play:
		// tu juz normalnie rysowanie juz podczas gry
		break;
	}


	window->display();
}
