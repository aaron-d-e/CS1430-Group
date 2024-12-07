//
// Created by aaron on 11/19/2024.
//

#include "Enemies.h"
#include <math.h>
#include "SDL Functions.h"
#include "SDL_Plotter.h"
#include "SoundEffect.h"
#include <SDL.h>
#include <SDL_mixer.h>



Enemies::Enemies(double r, double xPos, double yPos, SDL_Color c):
    radius(r), xPosition(xPos), yPosition(yPos), color(c){}

void Enemies::RenderEnemy(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for(int i = 0; i < radius * 2; i++) {
        for(int j = 0; j < radius * 2; j++) {
            int dx = radius - i;
            int dy = radius - j;
            if((dx*dx + dy*dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, xPosition + dx, yPosition + dy);
            }
        }
    }
}

void Enemies::EnemyCollision(double dT, Ball& b, Score& s, Enemies& e) {

    double accuracy = 20;
    soundEffect sound("../Assets/Sounds/sfx_sounds_interaction1.wav", 1);

        if(sqrt(pow(b.getX() - xPosition, 2) + pow(b.getY() - yPosition, 2)) <= radius + accuracy) {
            s.addScore(1);

            sound.playSound(125);


            b.setXVelo(-b.getXVel());
            b.setYVelo(-b.getYVel());
            e.setXPosition(rand()%SCREEN_WIDTH - (radius * 2));
            e.setYPosition(rand()%SCREEN_HEIGHT);

            e.setCollided(true);
        }
     if(e.getXPosition() < (radius * 2)) {
         e.setXPosition(e.getXPosition() + 100);
     }
    if(e.getYPosition() < (radius * 2)) {
        e.setYPosition(e.getYPosition() + 100);
    }
    if(e.getYPosition() < (radius * 2)) {
        e.setYPosition(e.getYPosition() + 50);
    }
    if(e.getYPosition() > 600) {
        e.setYPosition(e.getYPosition() - 50);
    }


}

void Enemies::setXPosition(double xPos) {
    xPosition = xPos;
}
void Enemies::setYPosition(double yPos) {
    yPosition = yPos;
}
double Enemies::getXPosition()const {
    return xPosition;
}
double Enemies::getYPosition()const {
    return yPosition;
}



