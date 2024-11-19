#include <iostream>

#include "SDL_Plotter.h"
#include "SDL Functions.h"
#include "Enemies.h"

using namespace std;

int main(int argc, char ** argv)
{
    double CURRENT;
    double PAST;
    double deltaTime;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("Pinball Game 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN); // window
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // renderer

    Ball b1(100, 100, -0.3, -0.1, 25, {255, 0, 0, 255}); // ball object
    Triangle t1(0, SCREEN_HEIGHT / 3, 100, 200, {255,255,255,0});
    Enemies e1(30, 400, 400, {0,0,255,255});


    //game loop
    bool isRunning = true;
    bool triangleRendered = false;


    while(isRunning) {
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                isRunning = false;
            }
        }


        PAST = CURRENT;
        CURRENT = SDL_GetPerformanceCounter();
        deltaTime = ((CURRENT - PAST) * 1000.0) / SDL_GetPerformanceFrequency();


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //background color
        SDL_RenderClear(renderer);

        b1.Physics(deltaTime); // ball physics
        b1.TriangleCollision1(deltaTime); // left triangle
        b1.TriangleCollision2(deltaTime); // right triangle

        b1.renderBall(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // color for triangles
        t1.renderTriangle(renderer);

        //RENDER ENEMIES
        e1.RenderEnemy(renderer);


        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
