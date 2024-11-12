//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include "SDL Functions.h"

Ball::Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c): x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(float dT) {
    x += xVelocity * dT;
    y += yVelocity * dT;

    if(x + radius < radius || x + radius > 1000-radius) {
        xVelocity = -xVelocity;
    }
    if(y+radius < radius || y + radius > 1000-radius) {
        yVelocity = -yVelocity;
    }
}

void Ball::render (SDL_Renderer* renderer) {
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








