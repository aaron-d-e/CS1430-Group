//
//  SoundEffect.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#include "SoundEffect.h"

soundEffect::soundEffect(){
    
}
soundEffect::soundEffect(char* path, double volume){
    soundPath = path;
    currVolume = volume;
}
void soundEffect::setSound(char* path){
    soundPath = path;
}
void soundEffect::setVolume(int volume){
    currVolume = volume;
    Mix_VolumeChunk(curChunk, currVolume);
}
string soundEffect::getPath(){
    return soundPath;
}
void soundEffect::playSound(double volume){
    currVolume = volume;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    curChunk = Mix_LoadWAV(soundPath);
    Mix_VolumeChunk(curChunk, currVolume);
    
}
