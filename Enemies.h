//
// Created by aaron on 11/19/2024.
//

#ifndef ENEMIES_H
#define ENEMIES_H
#include <SDL.h>
#include "SDL Functions.h"

class Enemies {

public:
    Enemies(double r, double xPos, double yPos, SDL_Color c); // ENEMIES CONSTRUCTOR
    void RenderEnemy(SDL_Renderer* renderer); // RENDERS NUMBER OF ENEMIES
    void EnemyCollision(double dT, Ball& b, Score& s, Enemies& e); // FIX ME
    void setXPosition(double xPos);
    void setYPosition(double yPos);
    double getXPosition()const;
    double getYPosition()const;
    bool getCollided()const {return collided;}
    void setCollided(bool c) {collided = c;}



private:
    double radius;
    bool collided = false;
    double xPosition;
    double yPosition;
    SDL_Color color;

};


#endif //ENEMIES_H
