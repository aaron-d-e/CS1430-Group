//
//  SoundEffect.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 12/2/24.
//

#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

/**
 * @class SoundEffect
 * @brief A class to manage and play sound effects using the SDL2 library.
 */
class SoundEffect {
private:
    std::string soundPath; ///< Path to the sound file.
    int currVolume;        ///< Current volume level (0 to MIX_MAX_VOLUME).
    Mix_Chunk* curChunk;   ///< Pointer to the loaded sound effect.

public:
    //************************************************************
    // description: Default constructor for the SoundEffect class. 
    //              Initializes the object with no sound and a 
    //              default volume level.                         
    // return: None                                               
    // pre: None                                                  
    // post: An empty SoundEffect object is created.              
    //************************************************************
    SoundEffect();

    //************************************************************
    // description: Constructor that loads a sound from a given path 
    //              and sets the initial volume.                   
    // return: None                                                
    // pre: The file at the provided path must exist and be a valid 
    //      sound file.                                            
    // post: A SoundEffect object with the sound loaded is created. 
    //************************************************************
    SoundEffect(const std::string& path, int volume);

    //************************************************************
    // description: Destructor for the SoundEffect class. 
    //              Releases resources associated with the sound. 
    // return: None                                              
    // pre: None                                                 
    // post: All allocated resources are released.               
    //************************************************************
    ~SoundEffect();

    //************************************************************
    // description: Sets a new sound effect from a given path. 
    // return: None                                            
    // pre: The file at the provided path must exist and be a 
    //      valid sound file.                                  
    // post: The current sound is replaced with the new sound. 
    //************************************************************
    void setSound(const std::string& path);

    //************************************************************
    // description: Sets the volume level for the sound effect. 
    // return: None                                            
    // pre: Volume must be between 0 and MIX_MAX_VOLUME.       
    // post: The sound effect is played at the specified volume. 
    //************************************************************
    void setVolume(int volume);

    //************************************************************
    // description: Gets the file path of the current sound effect. 
    // return: A string containing the file path.                  
    // pre: None                                                   
    // post: The path of the currently loaded sound is returned.   
    //************************************************************
    std::string getPath() const;

    //************************************************************
    // description: Plays the currently loaded sound effect.     
    // return: None                                            
    // pre: A valid sound must be loaded in curChunk.           
    // post: The sound effect is played at the set volume.      
    //************************************************************
    void playSound();
};

#endif /* SOUNDEFFECT_H */
