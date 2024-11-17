//
// Created by aaron on 10/30/2024.
//

#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H
#include <SDL.h>
#include "SDL_Plotter.h"
#include <iostream>
const float GRAVITY = .01;
const float BOUNCINESS = .8;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
class Ball {
public:
    Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c);
    void Physics(float dT);
    void renderBall (SDL_Renderer* renderer);

private:
    float x, y;
    float xVelocity, yVelocity;
    float radius;
    SDL_Color color;
};

class Triangle {
public:
    Triangle(float xPos, float yPos, float b, float h, SDL_Color c);
    void renderTriangle(SDL_Renderer* renderer);
private:
    float base;
    float height;
    float x,y;
    SDL_Color color;
    SDL_Point a = {0, 550}, b = {0, 700}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {799, 700}, f = {599, 750};

};

#endif //SDL_FUNCTIONS_H

