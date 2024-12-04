//
// Created by aaron on 11/19/2024.
//

#include "Enemies.h"
#include <cmath>


Enemies::Enemies(double r, double xPos, double yPos, SDL_Color c, int lives):
        radius(r), xPosition(xPos), yPosition(yPos), color(c), lives(lives){}

void Enemies::RenderEnemy(SDL_Renderer* renderer, double dT, Ball& b, Score& s) {
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
    double accuracy = 20;
    if(sqrt(pow(b.getX() - xPosition, 2) + pow(b.getY() - yPosition, 2)) <= radius + accuracy) {
        //add 10 to score
        s.addScore(10);
        lives -= 1;
        if (lives == 0){
            isSpawned = false;
        }
        b.setXVelo(-b.getXVel());
        b.setYVelo(-b.getYVel());
    }
}
/*
void Enemies::EnemyCollision(double dT, Ball& b, Score& s) {
    double accuracy = 20;
    if(sqrt(pow(b.getX() - xPosition, 2) + pow(b.getY() - yPosition, 2)) <= radius + accuracy) {
        //add 10 to score
        s.addScore(10);
        lives -= 1;
        if (lives == 0){
            isSpawned = false;
        }
        b.setXVelo(-b.getXVel());
        b.setYVelo(-b.getYVel());
    }

}*/

void Enemies::respawn(Score &s, int min, int max){
    lives = s.level;
    isSpawned = true;
    //randomize y position
    int ypos = min + (rand() % (max - min + 1));
    setYPosition(ypos);
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
double Enemies::getYPostion()const {
    return yPosition;
}

int Enemies::getLives()const{
    return lives;
}
