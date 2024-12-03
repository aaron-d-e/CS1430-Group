//
//  backgroundMusic.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#include "backgroundMusic.h"


backgroundMusic::backgroundMusic(){}
backgroundMusic::backgroundMusic(string name, double volume){}
void backgroundMusic::setSong(string name){}
string backgroundMusic::getSong(){
    return "blaahhhh";
}
void backgroundMusic::halfVolume(){}
void backgroundMusic::muteVolume(){}
void backgroundMusic::unmuteVolume(){}
void backgroundMusic::playMusic(double volume){
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
    Mix_Music* music = Mix_LoadMUS("/Users/jeffreyrajkumar/Desktop/Intro to CS/Sdl_test_please/Sdl_test_please/GameSongwav");
    Mix_PlayMusic(music, -1);
}

