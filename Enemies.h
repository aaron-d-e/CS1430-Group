//
// Created by aaron on 11/19/2024.
//

#ifndef ENEMIES_H
#define ENEMIES_H
#include <SDL.h>
#include "SDL_Functions.h"

class Enemies {

public:
    Enemies(double r, double xPos, double yPos, SDL_Color c, int lives); // ENEMIES CONSTRUCTOR
    void RenderEnemy(SDL_Renderer* renderer, double dT, Ball& b, Score& s); // RENDERS NUMBER OF ENEMIES
    void EnemyCollision(double dT, Ball& b, Score& s); // FIX ME
    void respawn(Score &s, int min, int max);
    void setXPosition(double xPos);
    void setYPosition(double yPos);
    double getXPosition()const;
    double getYPostion()const;
    int getLives()const;
    bool isSpawned = true;

private:
    double radius;
    int lives;
    double xPosition;
    double yPosition;
    SDL_Color color;

};


#endif //ENEMIES_H
