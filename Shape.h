#pragma once
#include "Classic.h"
#include "Survival.h"
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

    bool classic = true; // is it classic gamemode (1) or survival (0)
};

enum class GameState { MainMenu, Settings, GameMode, Play, GameOver };

class Shape {
public:
    Settings gameCurrentSettings;

    sf::RectangleShape rectangle;
    sf::ConvexShape convex;
    sf::CircleShape circle;

    // for coordination and customization of shapes
    short int whichShapeToDraw{};
    bool isShapeNeeded = true;
    

    void chooseShapeAndCustomiseIt();
    void randomRectangle();
    void randomConvex();
    void randomCircle();

    void onClick();
};