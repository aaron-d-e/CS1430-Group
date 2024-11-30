//
// Created by Andrew Hutcheson on 11/19/2024.
//
#include "Flipper.h"

#include "SDL_Functions.h"

double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

Flipper::Flipper(SDL_Renderer *renderer, int x, int y, float angle): xPos(x), yPos(y), angle(angle) {
    box = {xPos,yPos,150,20};
    this->angle = angle;
}

void Flipper::renderFlipper(SDL_Renderer *renderer, SDL_Texture* texture, bool invert) {
    //find point of rotation
    SDL_Point center;
    if (invert){
        center.x = 15;
        center.y = box.h / 2;
    }else{
        center.x = box.w - 15;
        center.y = box.h / 2;
    }
    this->isFlipped = invert;
    //decide to flip or not
    SDL_RenderCopyEx(renderer, texture, nullptr, &box, angle, &center, isFlipped ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Flipper::incrementAngle(){
    if (isFlipped){
        if (angle > -60){
            angle -= .2;
        }
    }else{
        if (angle < 60){
            angle += .2;
        }
    }
}

void Flipper::decrementAngle(){
    if (isFlipped){
        if (angle < 0){
            angle += .2;
        }
    }else{
        if (angle > 0){
            angle -= .2;
        }
    }
}

void Flipper::collision(SDL_Renderer* renderer, Ball& ball, double dt) {
    //draw collision line
    SDL_Point basePoint;
    SDL_Point endPoint;
    if (isFlipped) {
        basePoint.x = xPos+5;
        basePoint.y = yPos;
        float y = yPos+8 - basePoint.y;
        float x = xPos+box.w - basePoint.x;
        endPoint.x = static_cast<int>((x)*cos(toRadians(angle)) - (y)*sin(toRadians(angle)) + basePoint.x);
        endPoint.y = static_cast<int>((x)*sin(toRadians(angle)) + (y)*cos(toRadians(angle)) + basePoint.y+5);
        SDL_RenderDrawPoint(renderer, xPos+box.w,yPos+5);

        //SDL_RenderDrawPoint(renderer, xPos+5,yPos);
    }else {
        basePoint.x = xPos+box.w-5;
        basePoint.y = yPos+2;
        float y = yPos+5 - basePoint.y;
        float x = xPos - basePoint.x;
        endPoint.x = static_cast<int>((x)*cos(toRadians(angle)) - (y)*sin(toRadians(angle)) + basePoint.x);
        endPoint.y = static_cast<int>((x)*sin(toRadians(angle)) + (y)*cos(toRadians(angle)) + basePoint.y+10);
        SDL_RenderDrawPoint(renderer, xPos,yPos+5);

        //SDL_RenderDrawPoint(renderer, xPos+box.w-10,yPos);
    }
    bool collision = false;
    double accuracy = 8;
    double distance2;
    double distance1;
    double lineLength;

    distance2 = sqrt(pow(basePoint.x - ball.getX(), 2) + pow(basePoint.y - ball.getY(), 2)); // right triangle
    distance1 = sqrt(pow(endPoint.x - ball.getX(), 2) + pow(endPoint.y - ball.getY(), 2));
    lineLength = sqrt(pow(basePoint.x - endPoint.x, 2) + pow(basePoint.y - endPoint.y, 2));

    if((distance2 + distance1) <= lineLength + accuracy) {
        collision = true;
    }

    if(collision){
        /*ball.setXVelo(ball.getXVel() * BOUNCINESS * 1.5); //FIX ME ACCURATE X AND Y PHYSICS
        ball.setYVelo(-ball.getYVel() * BOUNCINESS * 1.5);
        ball.setX(ball.getX() + ball.getXVel() * dt);
        ball.setY(ball.getY() + ball.getYVel() * dt);*/

        double speed = sqrt(pow(ball.getXVel(), 2) + pow(ball.getYVel(), 2));

        // Calculate the new velocity components based on angle
        double newXVel;
        double newYVel;
        if (isFlipped) {
            newXVel = (abs(angle) > 5) ? speed * cos(angle) * 1.05 : ball.getXVel() * BOUNCINESS;
            newYVel = (abs(angle) > 5) ? speed * sin(angle) * 1.05 : ball.getYVel() * BOUNCINESS;
        }else {
            newXVel = (abs(angle) > 5) ? -speed * cos(abs(angle)) * 1.05 : ball.getXVel() * BOUNCINESS;
            newYVel = (abs(angle) > 5) ? -speed * sin(abs(angle)) * 1.05 : ball.getYVel() * BOUNCINESS;
        }


        // Update ball's velocity
        ball.setXVelo(newXVel);
        ball.setYVelo(-newYVel); // Reverse Y velocity to simulate bounce

        // Update ball's position
        ball.setX(ball.getX() + ball.getXVel() * dt);
        ball.setY(ball.getY() + ball.getYVel() * dt);
    }
    //SDL_RenderDrawLine(renderer, basePoint.x, basePoint.y, endPoint.x, endPoint.y);
    //SDL_RenderDrawLine()
}
