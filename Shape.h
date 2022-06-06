#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include <array>

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

enum class GameState { MainMenu, Settings, GameMode, Play };


class Shape {
private:
public:
    Shape();

    Settings gameCurrentSettings;

    sf::RectangleShape rectangle;
    sf::ConvexShape convex;//deletable
    sf::CircleShape circle;

    //is needed to cordinate customization and drawing
    short int whichShapeToDraw{};
    bool isShapeNeeded = true;
    

    void chooseShapeAndCustomiseIt();
 
    void randomRectangle();
    void randomConvex();// deletable
    void randomCircle();

    void update();
    void onClick();
};