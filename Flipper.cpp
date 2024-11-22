//
// Created by Andrew Hutcheson on 11/19/2024.
//
#include "Flipper.h"
double toRadians(double degrees) {
    return degrees * M_PI / 180.0;
}

Flipper::Flipper(SDL_Renderer *renderer, int x, int y, float angle): xPos(x), yPos(y), angle(angle) {
    box = {xPos,yPos,120,20};
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

void Flipper::collision(SDL_Renderer* renderer) {
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


    //SDL_RenderDrawLine(renderer, basePoint.x, basePoint.y, endPoint.x, endPoint.y);
    //SDL_RenderDrawLine()
}
