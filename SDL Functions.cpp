//
// Created by aaron on 10/30/2024.
//
#include <iostream>
#include "SDL_Functions.h"

Ball::Ball(float xInitialPos, float yInitialPos, float startXVelo, float startYVelo, float r, SDL_Color c): x(xInitialPos), y(yInitialPos), xVelocity(startXVelo), yVelocity(startYVelo), radius(r), color(c) {}

void Ball::Physics(float dT) {
    //yVelocity += GRAVITY;

    yVelocity += (GRAVITY * dT);

    y += yVelocity * dT;
    x += xVelocity * dT;

    if (x <= radius || x >= 1000 - radius) {
        xVelocity *= -BOUNCINESS;
        x = (x <= radius) ? radius : 1000 - radius;
    }
    if (y <= radius || y >= 1000 - radius) {
        yVelocity *= -BOUNCINESS;
        y = (y <= radius) ? radius : 1000 - radius;
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

}}
}








