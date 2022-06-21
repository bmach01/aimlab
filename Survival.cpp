#include "Survival.h"
#include <fstream>

Survival::Survival() {
	
	timer = new sf::Clock;
	init();
}
Survival::~Survival() {
	delete timer;
}
void Survival::init() {
	timer->restart();
	clicks = 0;
}

const int Survival::  points() {
	return clicks;
}
const double Survival::getTime() {
	return timer->getElapsedTime().asSeconds();
}