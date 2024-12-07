//
//  SoundEffect.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#ifndef SoundEffect_h
#define SoundEffect_h
#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
using namespace std;

class soundEffect {
private:
    const char* soundPath;
    int currVolume;
    Mix_Chunk* curChunk;
public:
    soundEffect();
    soundEffect(const char* path, double volume);
    void setSound(const char* path);
    void setVolume(int volume);
    string getPath();
    void playSound(double volume);


};


#endif /* SoundEffect_h */
