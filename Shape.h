#pragma once
#include "Game.h"

class Shape {
private:
    Settings gameCurrentSettings;
    Game* gamePointer = nullptr;

public:
    Shape(Game *g);
    Shape();

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