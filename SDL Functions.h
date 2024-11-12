//
// Created by aaron on 10/30/2024.
//

#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H
#include <SDL.h>
#include "SDL_Plotter.h"
#include <iostream>

class Ball {
public:
    Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c);
    void Physics(float dT);
    void render (SDL_Renderer* renderer);
private:
    float x, y;
    float xVelocity, yVelocity;
    float radius;
    SDL_Color color;
};

#endif //SDL_FUNCTIONS_H


