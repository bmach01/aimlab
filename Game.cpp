#include "Game.h"

void Game::drawMainMenu()
{
	// Title text
	sf::Text title;
	title.setFont(mainFont);
	title.setString("AimLab");
	title.setCharacterSize(90);
	title.setFillColor(sf::Color::White);
	title.setOrigin(title.getGlobalBounds().width / 2, title.getGlobalBounds().height / 2);
	title.setPosition(width / 2, height / 4);

	// Menu buttons
	sf::RectangleShape gameModeButton;
	sf::RectangleShape settingsButton;
	sf::RectangleShape exitButton;

	// std::array for later copying to polling
	std::array<sf::RectangleShape,3> allButtons = { gameModeButton, settingsButton, exitButton };

	// Menu buttons texts
	sf::Text gameModeText;
	gameModeText.setString("play");
	sf::Text settingsText;
	settingsText.setString("settings");
	sf::Text exitText;
	exitText.setString("exit");

	sf::Text buttonTexts[3] = { gameModeText, settingsText, exitText };

	// Graphic customization
	for (int i = 0; i < 3; i++) {
		allButtons[i].setOutlineColor(sf::Color::White);
		allButtons[i].setOutlineThickness(5.f);
		allButtons[i].setFillColor(sf::Color::Black);
		allButtons[i].setSize(sf::Vector2f(300.f, 80.f));
		allButtons[i].setPosition(width / 2, (height + 200 * i) / 2);
		allButtons[i].setOrigin(150.f, 40.f);

		buttonTexts[i].setFont(mainFont);
		buttonTexts[i].setFillColor(sf::Color::White);
		buttonTexts[i].setCharacterSize(50);
		buttonTexts[i].setOrigin(buttonTexts[i].getGlobalBounds().width / 2, buttonTexts[i].getGlobalBounds().height / 2);
		buttonTexts[i].setPosition(allButtons[i].getPosition().x, allButtons[i].getPosition().y - 10); // To jest voodoo/Stala Mimora

		window->draw(allButtons[i]);
		window->draw(buttonTexts[i]);
	}
	
	// Copy allButtons to currentButtons for polling
	std::copy(allButtons.begin(), allButtons.end(), currentButtons.begin());

	window->draw(title);
}

void Game::pollMainMenu()
{
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
	
		for (int i = 0; i < 3; i++) {
			sf::Vector2i mousePos(event.mouseButton.x + currentButtons[i].getOrigin().x, event.mouseButton.y + currentButtons[i].getOrigin().y);
			if (currentButtons[i].getPosition().x <= mousePos.x &&
				currentButtons[i].getPosition().y <= mousePos.y &&
				currentButtons[i].getPosition().x + currentButtons[i].getSize().x >= mousePos.x && // TO POWINNO SIE DAC LEPIEJ???
				currentButtons[i].getPosition().y + currentButtons[i].getSize().y >= mousePos.y)
			{
				gameState = i;
				std::cout << i << "\n";
				return;
			}
		}

	}
	
}

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), "AimLab", sf::Style::Close);
	window->setFramerateLimit(60);

	// Main Menu = 0, Settings = 1, GameMode = 2
	gameState = 0; // Lepszy bylby enum

	// Load font
	if (!mainFont.loadFromFile("HighlandGothicFLF.ttf"))
	{
		// Error
		std::cout << "Cannot load fonts!\n";
		window->close();
	}

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
		case 0:
			pollMainMenu();
			//std::cout << event.mouseButton.x << " " << event.mouseButton.y << "\n";

			break;
		case 1:
			// Ogarnia klikanie w opcjach
			break;
		case 2:
			// Ogarnia klikanie wyboru trybu
			break;
		case 3:
			// Ogarnia klikanie we wlasciwej grze
			break;
		}
	}
}

void Game::draw()
{
	window->clear(sf::Color::Black);

	switch (gameState) {
	case 0:
		drawMainMenu();
		break;
	case 1:
		//drawSettingsMenu();
		break;
	case 2:
		//drawGameModeMenu();
		break;
	case 3:
		// tu juz normalnie rysowanie juz podczas gry
		break;
	}


	window->display();
}
