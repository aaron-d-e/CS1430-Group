//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include <math.h>
#include "SDL Functions.h"


// BALL CLASS
Ball::Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c):
    x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(double dT) {
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
void Ball::TriangleCollision1(double dT) {  // left triangle
    float distancePointLine1;
    float distancePointLine2;
    float lineLength; // left
    float accuracy = 8;
    bool collision1 = false;
    distancePointLine1 = sqrt(pow(a.x - x, 2) + pow(a.y - y, 2)); // left triangle
    distancePointLine2 = sqrt(pow(c.x - x, 2) + pow(c.y - y, 2));
    lineLength = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));

    if((distancePointLine1 + distancePointLine2) <= lineLength + accuracy) {
        collision1 = true;
    }


    if(collision1) {
        xVelocity = -BOUNCINESS * dT; //FIX ME ACCURATE X AND Y PHYSICS
        yVelocity = -BOUNCINESS * dT;
    }
}

void Ball::TriangleCollision2(double dT) { // right triangle
    float distancePointLine3;
    float distancePointLine4;
    float lineLength2;
    float accuracy = 8;
    bool collision2 = false;

    distancePointLine3 = sqrt(pow(d.x - x, 2) + pow(d.y - y, 2)); // right triangle
    distancePointLine4 = sqrt(pow(e.x - x, 2) + pow(e.y - y, 2));
    lineLength2 = sqrt(pow(d.x - e.x, 2) + pow(d.y - e.y, 2));

    if((distancePointLine3 + distancePointLine4) <= lineLength2 + accuracy) {
        collision2 = true;
    }

    if(collision2) {
        xVelocity = -BOUNCINESS * dT; //FIX ME ACCURATE X AND Y PHYSICS
        yVelocity = -BOUNCINESS * dT;
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






