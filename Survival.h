#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include <array>
#include <random>
#include <fstream>
#include <chrono>

class Survival {
public:
	//constructor and deconstructor
	Survival();
	~Survival();
	sf::Clock* timer;
	void init(); //initialize variables
	int clicks; //number of right clicks
	
	const int points(); //returns points
	
	const double getTime(); //returns time in seconds
};