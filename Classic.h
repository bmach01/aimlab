#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include <array>
#include <random>
#include <fstream>
#include <chrono>

class Classic
{
private:
	sf::Clock *timer;
	double clicksRange; // Holds distances between shape's center and mousePos
	int gameLength; // Game limit

public:
	// (De)Constructor
	Classic();
	~Classic();
	
	// Public functions
	void pushClick(sf::Vector2f mousePos, sf::CircleShape currentShape); // For accuracy calculation
	void init(); // Initialize variables

	int currentLength; // Current clicks

	// Access functions
	const bool stillPlaying(); // Checks if game should stop based on amount of clicked shapes
	const double getAccuracy(); // Returns calculated accuracy
	const double getTime(); // Returns games time
};

