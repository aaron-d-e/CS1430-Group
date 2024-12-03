//
//  SoundEffect.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#ifndef SoundEffect_h
#define SoundEffect_h
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_mixer/SDL_mixer.h>
#include <SDL2_image/SDL_image.h>
using namespace std;

class soundEffect {
private:
    char* soundPath;
    int currVolume;
    Mix_Chunk* curChunk;
public:
    soundEffect();
    soundEffect(char* path, double volume);
    void setSound(char* path);
    void setVolume(int volume);
    string getPath();
    void playSound(double volume);
    
    
};


#endif /* SoundEffect_h */
