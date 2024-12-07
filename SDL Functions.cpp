//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include <math.h>
#include "SDL_Functions.h"


// BALL CLASS
Ball::Ball(double xInitialPos, double yInitialPos, double startXVelo, double startYVelo, double r, SDL_Color c):
        x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(double dT) {
    //yVelocity += GRAVITY;

    yVelocity += GRAVITY / (dT * dT);

    y += yVelocity * dT;
    x += xVelocity * dT;


    if (x <= radius || x >= SCREEN_WIDTH - radius) {
        xVelocity *= -BOUNCINESS;
        x = (x <= radius) ? radius : SCREEN_WIDTH - radius;
    }
    /*if (y <= radius || y >= SCREEN_HEIGHT - radius) {
        yVelocity *= -BOUNCINESS;
        y = (y <= radius) ? radius : SCREEN_HEIGHT - radius;
    }*/
    if (y <= radius) {
        yVelocity *= -BOUNCINESS;
        y = (y <= radius) ? radius : SCREEN_HEIGHT - radius;
    }

}

void Ball::renderBall (SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for(int i = 0; i < radius * 2; i++) {
        for(int j = 0; j < radius * 2; j++) {
            int dx = radius - i;
            int dy = radius - j;
            if((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Ball::reset() {
    x = BALL_INITIAL_X;
    y = BALL_INITIAL_Y;
    yVelocity = 0;
    xVelocity = 0;

}
void Ball::TriangleCollision1(double dT) {  // left triangle
    double distancePointLine1;
    double distancePointLine2;
    double lineLength; // left
    double accuracy = 8;
    bool collision1 = false;
    distancePointLine1 = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2)); // left triangle
    distancePointLine2 = sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
    lineLength = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    if((distancePointLine1 + distancePointLine2) <= lineLength + accuracy) {
        collision1 = true;
    }


    if(collision1){
        /*xVelocity *= BOUNCINESS; //FIX ME ACCURATE X AND Y PHYSICS
        yVelocity *= -BOUNCINESS;
        x += xVelocity * dT;
        y += yVelocity * dT;*/

        double speed = sqrt(pow(xVelocity, 2) + pow(yVelocity, 2));

        // Calculate the new velocity components based on angle
        //0.7853 is the angle of the triangle in radians
        double newXVel = speed * cos(0.7853) * BOUNCINESS;
        double newYVel = speed * sin(0.7853) * BOUNCINESS;

        // Update ball's velocity
        xVelocity = newXVel;
        yVelocity = -newYVel; // Reverse Y velocity to simulate bounce

        // Update ball's position
        x +=  xVelocity * dT;
        y +=  yVelocity * dT;
    }
}

void Ball::TriangleCollision2(double dT) { // right triangle
    double distancePointLine3;
    double distancePointLine4;
    double lineLength2;
    double accuracy = 8;
    bool collision2 = false;

    distancePointLine3 = sqrt(pow(d.x - x, 2) + pow(d.y - y, 2)); // right triangle
    distancePointLine4 = sqrt(pow(e.x - x, 2) + pow(e.y - y, 2));
    lineLength2 = sqrt(pow(d.x - e.x, 2) + pow(d.y - e.y, 2));

    if((distancePointLine3 + distancePointLine4) <= lineLength2 + accuracy) {
        collision2 = true;
    }

    if(collision2) {
        double speed = sqrt(pow(xVelocity, 2) + pow(yVelocity, 2));

        // Calculate the new velocity components based on angle
        //2.35619 is the angle of the triangle in radians
        double newXVel = speed * cos(2.35619) * BOUNCINESS;
        double newYVel = speed * sin(2.35619) * BOUNCINESS;

        // Update ball's velocity
        xVelocity = newXVel;
        yVelocity = -newYVel; // Reverse Y velocity to simulate bounce

        // Update ball's position
        x +=  xVelocity * dT;
        y +=  yVelocity * dT;
    }
}

//TRIANGLE CLASS

Triangle::Triangle(double xPos, double yPos, double b, double h, SDL_Color c):
        x(xPos), y(yPos), base(b), height(h){}

void Triangle::renderTriangle(SDL_Renderer* renderer) {
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, a.x, a.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, b.x, b.y);

    SDL_RenderDrawLine(renderer, d.x, d.y, e.x, e.y);
    SDL_RenderDrawLine(renderer, d.x, d.y, f.x, f.y);
    SDL_RenderDrawLine(renderer, f.x, f.y, e.x, e.y);
}

void Score::addScore(int score){
    totalScore += score;
}

void handleUserClick(bool &userClick, Ball &b1, Score &score) {
    score.lives -= 1;
    userClick = !userClick;
    /*
     * if (score.lives == 0){
     *  gameOverScreen();
     * }
     */
    b1.reset();
}

void gamePause(bool &userClick, Ball &b1){
    if (b1.getY() >= SCREEN_HEIGHT + 100) {
        if (userClick == true) {
            userClick = false;
        }
    }
}




/*
void drawCircle (SDL_Renderer* renderer, int x, int y, int radius, SDL_Color c) {
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    for(int i = 0; i < radius * 2; i++) {
        for(int j = 0; j < radius * 2; j++) {
            int dx = radius - i;
            int dy = radius - j;
            if((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void drawRectangle(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color c) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(renderer, c.r, c.g, c.b, c.a);
    SDL_RenderFillRect(renderer, &rect);
}*/
