//
//  backgroundMusic.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#include "backgroundMusic.h"


backgroundMusic::backgroundMusic(){}
backgroundMusic::backgroundMusic(char* path, double volume){
    songPath = path;
    currVolume = volume;
    SDL_AudioInit(songPath);

}
void backgroundMusic::setSong(char* path){
    songPath = path;
}
void backgroundMusic::setVolume(int volume){
    currVolume = volume;
    Mix_VolumeMusic(currVolume);
}
string backgroundMusic::getPath(){
    return songPath;
}
void backgroundMusic::halfVolume(){
    Mix_VolumeMusic(currVolume/2);
}
void backgroundMusic::muteVolume(){
    Mix_PauseAudio(1);
}
void backgroundMusic::unmuteVolume(){
    Mix_PauseAudio(0);
}
void backgroundMusic::playMusic(double volume){
    currVolume = volume;
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_VolumeMusic(currVolume);
    Mix_Music* music = Mix_LoadMUS(songPath);
    Mix_PlayMusic(music, -1);
}


