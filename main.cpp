#include <iostream>
#include <cmath>
#include "SDL_Functions.h"
#include "Flipper.h"
using namespace std;

int main(int argc, char** argv) {
    Uint32 CURRENT = SDL_GetPerformanceCounter();
    Uint32 PAST = 0;
    double deltaTime;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("Pinball Game 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Ball b1(400, 400, -0.5, -0.1, 20, {255, 0, 0, 255});
    Triangle t1(0, SCREEN_HEIGHT / 3, 100, 200, {255,255,255,0});
    //load texture for Flipper
    SDL_Surface* surface = SDL_LoadBMP("../images/flipper.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    Flipper leftFlipper(renderer, 190,735,0);
    Flipper rightFlipper(renderer, 500, 735,0);

    bool isRunning = true;

    while (isRunning) {
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_KEYDOWN:
                    switch (e.key.keysym.sym) {
                        case SDLK_a:
                            leftFlipper.keydown = true;
                            break;
                        case SDLK_d:
                            rightFlipper.keydown = true;
                            break;
                        default:
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (e.key.keysym.sym) {
                        case SDLK_a:
                            leftFlipper.keydown = false;
                            break;
                        case SDLK_d:
                            rightFlipper.keydown = false;
                            break;
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
        }

        PAST = CURRENT;
        CURRENT = SDL_GetPerformanceCounter();
        deltaTime = ((CURRENT - PAST) * 1000.0) / SDL_GetPerformanceFrequency();


        b1.Physics(deltaTime);
        b1.TriangleCollision1(deltaTime); // left triangle
        b1.TriangleCollision2(deltaTime);


        //rightFlipper.collision(renderer);


        //update flippers
        if (leftFlipper.keydown) {
            leftFlipper.incrementAngle();
        } else {
            leftFlipper.decrementAngle();
        }
        if (rightFlipper.keydown) {
            rightFlipper.incrementAngle();
        } else {
            rightFlipper.decrementAngle();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,255,255,0);
        //SDL_RenderDrawRect(renderer, &rect);

        leftFlipper.renderFlipper(renderer, texture,true);
        rightFlipper.renderFlipper(renderer,texture,false);

        leftFlipper.collision(renderer);
        rightFlipper.collision(renderer);

        b1.renderBall(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // color for triangles
        t1.renderTriangle(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
