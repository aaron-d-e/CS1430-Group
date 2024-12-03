//
//  backgroundMusic.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#ifndef backgroundMusic_h
#define backgroundMusic_h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>
using namespace std;

class backgroundMusic {
private:
    string songName;
    char test;
public:
    backgroundMusic();
    backgroundMusic(string name, double volume);
    void setSong(string name);
    string getSong();
    void halfVolume(); 
    void muteVolume();
    void unmuteVolume();
    void playMusic(double volume);
    
    
};


#endif /* backgroundMusic_h */
