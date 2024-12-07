#include "Flipper.h"
#include "Enemies.h"
#include "LTimer.h"
#include <ctime>
#include <SDL_ttf.h>
#include "BackgroundMusic.h"
#include "SoundEffect.h"
#include <iostream>
#include <charconv>

#include "BackgroundMusic.h"

using namespace std;

const int SCREEN_FPS = 160;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

void displayText(const char* text, Score& s, SDL_Renderer* renderer);

int main(int argc, char** argv) {

    Uint32 CURRENT = SDL_GetPerformanceCounter();
    Uint32 PAST = 0;
    double deltaTime;
    bool enemiesspawn = false;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("Pinball Game 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);



    srand((unsigned)time(0));
    Uint8 r = (rand() % 255) + 1;
    Uint8 g = (rand() % 255) + 1;
    Uint8 b = (rand() % 255) + 1;
    Uint8 a = (rand() % 255) + 1;


    //initialize environment
    //BALL INITIAL X and Y are initialized in SDL_Functions.h with other constants
    Ball b1(BALL_INITIAL_X, BALL_INITIAL_Y, 0.1, -0.2, 20, {255, 0, 0, 255});
    Triangle t1(0, SCREEN_HEIGHT / 3, 100, 200, {255,255,255,0});
    Enemies e1(50, 400, 400, {r,g,b,a});
    backgroundMusic music("../Assets/Sounds/retro-city-14099.wav", 1);



    //initialize score
    Score score(0,10, 1.0);

    //load texture for Flipper
    SDL_Surface* surface = SDL_LoadBMP("../Assets/Sprites/flipper.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    Flipper leftFlipper(renderer, 200,745,0);
    Flipper rightFlipper(renderer, 450, 745,0);

    bool isRunning = true;
    LTimer fpsTimer;
    LTimer capTimer;
    int countedFrames = 0;
    fpsTimer.start();

    music.playMusic(100);

    while (isRunning && score.lives > 0) {
        capTimer.start();
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }
        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
        deltaTime = SCREEN_TICKS_PER_FRAME - frameTicks;
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
        leftFlipper.renderFlipper(renderer, texture,true);
        rightFlipper.renderFlipper(renderer,texture,false);

        leftFlipper.collision(renderer, b1, deltaTime);
        rightFlipper.collision(renderer, b1, deltaTime);

        score.updateLife(b1);

    displayText("Score", score, renderer);


        if(score.lives <= 10) {
            e1.RenderEnemy(renderer);
            e1.EnemyCollision(deltaTime, b1, score, e1);
            //enemiesspawn = true;
        }

        //e1.EnemyCollision(deltaTime, b1, score, e1);
        //e2.EnemyCollision(deltaTime, b1, score, e2);
        //e3.EnemyCollision(deltaTime, b1, score, e3);




        b1.renderBall(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // color for triangles
        t1.renderTriangle(renderer);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);


    }

    //SDL_DestroyTexture(textTexture);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void displayText(const char* text, Score& s, SDL_Renderer* rend) {
    //  font shenanigans
    if(TTF_Init() < 0) {
        SDL_Delay(100);
        exit(1);
    }
    TTF_Font* font = TTF_OpenFont("../Assets/Background/ARCADECLASSIC.TTF" ,24);
    if(!font) {
        SDL_Delay(100);
        exit(1);
    }
    SDL_Color White = {255,255,255};
    const char* scoreText = "Score" + s.totalScore;
    SDL_Surface* textSurface =  TTF_RenderText_Solid(font, scoreText, White);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(rend, textSurface);
    SDL_FreeSurface(textSurface);
    SDL_Rect textRect = { 10 ,10 ,400, 100};
    SDL_RenderCopy(rend, textTexture, NULL, &textRect);

}
