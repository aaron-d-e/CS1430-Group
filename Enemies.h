//
// Created by aaron on 11/19/2024.
//

#ifndef ENEMIES_H
#define ENEMIES_H
#include <SDL.h>

class Enemies {

public:
    Enemies(double r, double xPos, double yPos, SDL_Color c); // ENEMIES CONSTRUCTOR
    void RenderEnemy(SDL_Renderer* renderer); // RENDERS NUMBER OF ENEMIES
    void EnemyCollision(double dT); // FIX ME

private:
    double radius;
    double xPosition;
    double yPosition;
    SDL_Color color;
};


#endif //ENEMIES_H
