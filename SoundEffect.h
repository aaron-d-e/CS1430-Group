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

    //************************************************************
    // description: Sets a new sound effect from the given path.  
    // return: None                                              
    // pre: The file at the provided path must exist and be a     
    //      valid sound file.                                    
    // post: The current sound is replaced with the new sound.   
    //************************************************************
    void setSound(char* path);

    //************************************************************
    // description: Sets the volume level for the sound effect.  
    // return: None                                             
    // pre: Volume must be between 0 and MIX_MAX_VOLUME.        
    // post: The sound effect is played at the specified volume. 
    //************************************************************
    void setVolume(int volume);

    //************************************************************
    // description: Gets the file path of the current sound effect. 
    // return: A string containing the file path of the current 
    //         sound effect.                                      
    // pre: None                                                 
    // post: The file path of the currently loaded sound is returned. 
    //************************************************************
    string getPath();

    //************************************************************
    // description: Plays the currently loaded sound effect.     
    // return: None                                             
    // pre: A valid sound must be loaded in curChunk.           
    // post: The sound effect is played at the set volume.      
    //************************************************************
    void playSound(double volume);
};

#endif /* SoundEffect_h */
