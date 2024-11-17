//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include <math.h>
#include "SDL Functions.h"


// BALL CLASS
Ball::Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c):
    x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(float dT) {
    //yVelocity += GRAVITY;

    yVelocity += (GRAVITY * dT);

    y += yVelocity * dT;
    x += xVelocity * dT;

    if (x <= radius || x >= SCREEN_WIDTH - radius) {
        xVelocity *= -BOUNCINESS;
        x = (x <= radius) ? radius : SCREEN_WIDTH - radius;
    }
    if (y <= radius || y >= SCREEN_HEIGHT - radius) {
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
void Ball::CircleTriangle1() { // FIX ME ADD ANGULAR VELOCITY
    float distancePointLine1;
    float distancePointLine2;
    float lineLength;
    float accuracy = 45;
    bool collision = false;
    distancePointLine1 = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2));
    distancePointLine2 = sqrt(pow(b.x - x, 2) + pow(b.y - y, 2));
    lineLength = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

    if((distancePointLine1 + distancePointLine2) <= lineLength + accuracy) {
        collision = true;
    }

    if(collision) {
        xVelocity = -xVelocity;
        yVelocity = -yVelocity;
    }
}

//TRIANGLE CLASS

Triangle::Triangle(float xPos, float yPos, float b, float h, SDL_Color c):
    x(xPos), y(yPos), base(b), height(h){}

void Triangle::renderTriangle(SDL_Renderer* renderer) {
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
    SDL_RenderDrawLine(renderer, a.x, a.y, c.x, c.y);
    SDL_RenderDrawLine(renderer, c.x, c.y, b.x, b.y);

    SDL_RenderDrawLine(renderer, d.x, d.y, e.x, e.y);
    SDL_RenderDrawLine(renderer, d.x, d.y, f.x, f.y);
    SDL_RenderDrawLine(renderer, f.x, f.y, e.x, e.y);
}






