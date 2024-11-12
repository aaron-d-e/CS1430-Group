#include <iostream>

#include "SDL_Plotter.h"
#include "SDL Functions.h"

using namespace std;

int main(int argc, char ** argv)
{
    Uint32 CURRENT = SDL_GetPerformanceCounter();
    Uint32 PAST = 0;
    float deltaTime;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("Pinball Game 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 1000, SDL_WINDOW_SHOWN); // window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // renderer

    Ball b1(500, 500, 0.5, 0.5, 25, {255, 0, 0, 255}); // ball object

    //game loop
    bool isRunning = true;

    while(isRunning) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }
        }

        PAST = CURRENT;
        CURRENT = SDL_GetPerformanceCounter();
        deltaTime = ((CURRENT - PAST) * 1000.0) / SDL_GetPerformanceFrequency();

        b1.Physics(deltaTime);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        b1.render(renderer);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}