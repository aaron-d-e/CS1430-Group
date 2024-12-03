//
// Created by aaron on 11/19/2024.
//

#include "Enemies.h"
#include <math.h>
#include "SDL Functions.h"

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

void Enemies::EnemyCollision(double dT, Ball& b, Score& s) {
    double accuracy = 20;
    if(sqrt(pow(b.getX() - xPosition, 2) + pow(b.getY() - yPosition, 2)) <= radius + accuracy) {
    //add one to score
    }

}

void Enemies::setXPosition(double xPos) {
    xPosition = xPos;
}
void Enemies::setYPostion(double yPos) {
    yPosition = yPos;
}

double Enemies::getXPosition()const {
    return xPosition;
}
double Enemies::getYPostion()const {
    return yPosition;
}



