//
//  backgroundMusic.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#ifndef backgroundMusic_h
#define backgroundMusic_h
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#include <SDL_audio.h>
using namespace std;

class backgroundMusic {
private:
    string songName;
    const char* songPath;
    int currVolume;
public:
    backgroundMusic();
    backgroundMusic(const char* path, double volume);
    void setSong(const char* path);
    void setVolume(int volume);
    string getPath();
    void halfVolume();
    void muteVolume();
    void unmuteVolume();
    void playMusic(double volume);


};


#endif /* backgroundMusic_h */
