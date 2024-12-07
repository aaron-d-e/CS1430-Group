#include "Flipper.h"
#include "LTimer.h"
#include "Enemies.h"
//#include <SDL2_TTF.h>
using namespace std;

//constants for capping frame rate
const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

int main(int argc, char** argv) {
    double deltaTime;
    SDL_Event e;
    SDL_Window* window = SDL_CreateWindow("Pinball Game 1.0", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //initialize environment
    //BALL INITIAL X and Y are initialized in SDL_Functions.h with other constants
    Ball b1(BALL_INITIAL_X, BALL_INITIAL_Y, 0.0, -0.1, 20, {255, 0, 0, 255});
    Triangle t1(0, SCREEN_HEIGHT / 3, 100, 200, {255,255,255,0});

    //initialize score
    Score score(0,10, 1.0);

    //initialize enemies
    Enemies e1(50, 400, 400, {255,255,255,255}, score.level);
    Enemies e2(50, 200, 200, {255,255,255,255}, score.level);
    Enemies e3(50, 600, 200, {255,255,255,255}, score.level);
    Enemies e4(50, 400, 550, {255,255,255,255}, score.level);
    //default enemy 4 to not spawned
    e4.setIsSpawned(false);



    //load texture for Flipper
    SDL_Surface* surface = SDL_LoadBMP("../images/flipper.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    //create flippers
    Flipper leftFlipper(renderer, 200,745,0);
    Flipper rightFlipper(renderer, 450, 745,0);

    bool isRunning = true;
    bool userClick = false;

    //stuff for fps calculation
    LTimer fpsTimer;
    LTimer capTimer;
    int countedFrames = 0;
    fpsTimer.start();

    while (isRunning && score.level > 0) {
        //framerate cap timer
        capTimer.start();

        //wait for user to click screen and drop ball
        while(!userClick) {
            while (SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT:
                        //if user is trying to quit while in waiting screen
                        isRunning = false;
                        return 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        handleUserClick(userClick, b1, score);
                        break;
                    case SDL_KEYDOWN:
                        if (e.key.keysym.sym == SDLK_SPACE) {
                            handleUserClick(userClick, b1, score);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (!userClick){
                        userClick = true;
                    }
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

        //Calculate and correct fps
        float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
        if( avgFPS > 2000000 )
        {
            avgFPS = 0;
        }

        //If frame finished early
        int frameTicks = capTimer.getTicks();
        if( frameTicks < SCREEN_TICKS_PER_FRAME )
        {
            //Wait remaining time
            SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
        }
        deltaTime = SCREEN_TICKS_PER_FRAME;


        b1.Physics(deltaTime);
        b1.TriangleCollision1(deltaTime); // left triangle
        b1.TriangleCollision2(deltaTime);


        //update flippers
        leftFlipper.update();
        rightFlipper.update();

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer,255,255,255,0);

        //render flippers
        leftFlipper.renderFlipper(renderer, texture,true);
        rightFlipper.renderFlipper(renderer,texture,false);
        leftFlipper.collision(renderer, b1, deltaTime);
        rightFlipper.collision(renderer, b1, deltaTime);

        //pause game when ball is out of bounds
        gamePause(userClick, b1);

        //spawn enemies if they still have lives
        if (e1.getIsSpawned()) {e1.RenderEnemy(renderer, deltaTime, b1, score);}
        if (e2.getIsSpawned()) {e2.RenderEnemy(renderer, deltaTime, b1, score);}
        if (e3.getIsSpawned()) {e3.RenderEnemy(renderer, deltaTime, b1, score);}
        if (e4.getIsSpawned()) {e4.RenderEnemy(renderer, deltaTime, b1, score);}
        //go to next level
        if (!e1.getIsSpawned() && !e2.getIsSpawned() && !e3.getIsSpawned() && !e4.getIsSpawned()){
            score.level += 1;
            e1.respawn(score, 100, 400);
            e2.respawn(score, 100, 400);
            e3.respawn(score, 100, 400);
            //spawn 4th enemy if higher level
            if (score.level >= 3){
                e4.respawn(score, 450, 550);
            }
        }


        b1.renderBall(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // color for triangles
        t1.renderTriangle(renderer);

        SDL_RenderPresent(renderer);
        ++countedFrames;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
