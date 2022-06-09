#pragma once
#include <SFML/Graphics.hpp>
#include<ctime>
#include<iostream>
#include <array>
#include <random>

class Shape {
private:
  
public:
   // Constructor
   Shape();
   
   // Copy of settings
   Settings gameCurrentSettings;
 
   // Figures
   sf::RectangleShape rectangle;
   sf::ConvexShape convex;
   sf::CircleShape circle;
   
   // Randomize figures
   void randomRectangle();
   void randomConvex();
   void randomCircle();
   void chooseShapeAndCustomiseIt();
  
   //Is needed to cordinate customization and drawing
   short int whichShapeToDraw{};
   bool isShapeNeeded = true;
    
   // Functions (?PUBLIC?)
   void update();
   void onClick();
};