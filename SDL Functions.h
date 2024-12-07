//
// Created by aaron on 10/30/2024.
//

#ifndef SDL_FUNCTIONS_H
#define SDL_FUNCTIONS_H
#include <SDL.h>
#include <iostream>
const double GRAVITY = 10;
const double BOUNCINESS = .8;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;
const int BALL_INITIAL_X = 100;
const int BALL_INITIAL_Y = 550;
// BALL CLASS
class Ball {
public:
    Ball(double xInitialPos, double yInitialPos, double startXVelo, double startYVelo, double r, SDL_Color c); // BALL CONSTRUCTOR
    void Physics(double dT); //FUNCTION THAT CALCULATES PHYSICS FOR BALL
    void renderBall (SDL_Renderer* renderer); //FUNCTION THAT RENDERS BALL TO SCREEN
    void reset();
    double getX() const { return x; } //GETS X VALUE, *currently unused*
    double getY() const { return y; } // GETS Y VALUE, *currently unused*
    double getYVel() const {return yVelocity;}
    double getXVel() const {return xVelocity;}
    double getRadius(){return radius;};
    void setX(float tempX){x = tempX;}
    void setY(float tempY){y = tempY;}
    void setXVelo(float tempXVelo){xVelocity = tempXVelo;}
    void setYVelo(float tempYVelo){yVelocity = tempYVelo;}
    double getRadius() const;


    void TriangleCollision1(double dT); //COLLISION FOR TRIANGLE ON LEFT SIDE OF SCREEN
    void TriangleCollision2(double dT); // COLLISION FOR TRIANGLE ON RIGHT SIDE OF SCREEN
    //ADD THIS TO OTHER TRIANGLE, ONLY CHANGE POINT VALUES

private:
    double x, y;
    double xVelocity, yVelocity;
    double radius;
    SDL_Color color;
    SDL_Point a = {0, 550}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750};
};

//TRIANGLE CLASS
class Triangle {
public:
    Triangle(double xPos, double yPos, double b, double h, SDL_Color c); // TRIANGLE CONSTRUCTOR
    void renderTriangle(SDL_Renderer* renderer); //RENDERS STATIC TRIANGLES TO SCREEN
private:
    double base;
    double height;
    double x,y;
    SDL_Color color;
    SDL_Point a = {0, 550}, b = {0, 700}, c = {200, 750};
    SDL_Point d = {799, 550}, e = {599, 750}, f = {799, 700};

};

struct Score {
    int totalScore = 0;
    int lives;
    float multiplier;
    Score(int totalScore, int lives, float multiplier): totalScore(totalScore), lives(lives), multiplier(multiplier){}
    void addScore(int score){totalScore += score;}
    void updateLife(Ball &b1);
    int getScore()const {
        return totalScore;
    }
};

void drawCircle (SDL_Renderer* renderer, int x, int y, int radius, SDL_Color c);
void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color c);
#endif //SDL_FUNCTIONS_H
