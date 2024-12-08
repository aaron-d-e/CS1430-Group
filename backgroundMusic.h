//
//  backgroundMusic.h
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

#ifndef BACKGROUNDMUSIC_H
#define BACKGROUNDMUSIC_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

using namespace std;

/**
 * @class backgroundMusic
 * @brief A class to manage and control background music using the SDL2 library.
 */
class backgroundMusic {
private:
    string songName; ///< Name of the current song.
    char* songPath;  ///< Path to the music file.
    int currVolume;  ///< Current volume level (0 to MIX_MAX_VOLUME).

public:
    //************************************************************
    // description: Default constructor for the backgroundMusic class. 
    //              Initializes the object with no music loaded and 
    //              default volume level.                         
    // return: None                                               
    // pre: None                                                  
    // post: An empty backgroundMusic object is created.          
    //************************************************************
    backgroundMusic();

    //************************************************************
    // description: Constructor that loads a song from a given path 
    //              and sets the initial volume.                  
    // return: None                                               
    // pre: The file at the provided path must exist and be a valid 
    //      music file.                                            
    // post: A backgroundMusic object with the song loaded is created. 
    //************************************************************
    backgroundMusic(char* path, double volume);

    //************************************************************
    // description: Sets a new background song from a given path. 
    // return: None                                              
    // pre: The file at the provided path must exist and be a     
    //      valid music file.                                     
    // post: The current song is replaced with the new song.      
    //************************************************************
    void setSong(char* path);

    //************************************************************
    // description: Sets the volume level for the background music. 
    // return: None                                               
    // pre: Volume must be between 0 and MIX_MAX_VOLUME.          
    // post: The background music is played at the specified volume. 
    //************************************************************
    void setVolume(int volume);

    //************************************************************
    // description: Gets the file path of the current song.       
    // return: A string containing the file path of the current song. 
    // pre: None                                                  
    // post: The file path of the loaded song is returned.        
    //************************************************************
    string getPath();

    //************************************************************
    // description: Halves the current volume of the background music. 
    // return: None                                                  
    // pre: Volume must be greater than 0 to reduce it.                
    // post: The volume is halved, ensuring it does not drop below 0.  
    //************************************************************
    void halfVolume();

    //************************************************************
    // description: Mutes the background music.                  
    // return: None                                              
    // pre: None                                                 
    // post: The volume is set to 0.                             
    //************************************************************
    void muteVolume();

    //************************************************************
    // description: Unmutes the background music, restoring the   
    //              volume to its previous level.                 
    // return: None                                               
    // pre: The music must have been muted previously.            
    // post: The volume is restored to the previous level.        
    //************************************************************
    void unmuteVolume();

    //************************************************************
    // description: Plays the current background music at the     
    //              specified volume level.                       
    // return: None                                               
    // pre: A valid song must be loaded in songPath.              
    // post: The background music is played.                      
    //************************************************************
    void playMusic(double volume);
};

#endif /* BACKGROUNDMUSIC_H */
