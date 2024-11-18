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
// BALL CLASS
class Ball {
public:
    Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c); // BALL CONSTRUCTOR
    void Physics(double dT); //FUNCTION THAT CALCULATES PHYSICS FOR BALL
    void renderBall (SDL_Renderer* renderer); //FUNCTION THAT RENDERS BALL TO SCREEN
    float GetX() const { return x; } //GETS X VALUE, *currently unused*
    float GetY() const { return y; } // GETS Y VALUE, *currently unused*
    void TriangleCollision1(double dT); //COLLISION FOR TRIANGLE ON LEFT SIDE OF SCREEN
    void TriangleCollision2(double dT); // COLLISION FOR TRIANGLE ON RIGHT SIDE OF SCREEN
    //ADD THIS TO OTHER TRIANGLE, ONLY CHANGE POINT VALUES

private:
    float x, y;
    float xVelocity, yVelocity;
    float radius;
    SDL_Color color;
    SDL_Point a = {0, 550}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750};
};

//TRIANGLE CLASS
class Triangle {
public:
    Triangle(float xPos, float yPos, float b, float h, SDL_Color c); // TRIANGLE CONSTRUCTOR
    void renderTriangle(SDL_Renderer* renderer); //RENDERS STATIC TRIANGLES TO SCREEN
private:
    float base;
    float height;
    float x,y;
    SDL_Color color;
    SDL_Point a = {0, 550}, b = {0, 700}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750}, f = {799, 700};

};

#endif //SDL_FUNCTIONS_H
