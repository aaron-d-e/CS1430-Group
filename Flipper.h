//
// Created by Andrew Hutcheson on 11/19/2024.
//

#ifndef SDL2_TEST_FLIPPER_H
#define SDL2_TEST_FLIPPER_H
#include <SDL.h>
#include "SDL_Functions.h"
#include <cmath>

class Flipper{
private:
    float angle;
    int xPos;
    int yPos;
    SDL_Rect box;
    bool isFlipped = false;

public:
    bool keydown = false;
    Flipper(SDL_Renderer *renderer, int x, int y, float angle);
    void renderFlipper(SDL_Renderer* renderer, SDL_Texture* texture, bool invert);
    void incrementAngle();
    void decrementAngle();
    void collision(SDL_Renderer *renderer, Ball& ball, double dt);
};
#endif //SDL2_TEST_FLIPPER_H
