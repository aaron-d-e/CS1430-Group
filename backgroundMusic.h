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
    char* songPath;
    int currVolume;
public:
    backgroundMusic();
    backgroundMusic(char* path, double volume);

    //************************************************************
    // description: Sets a new background song from the given path. 
    // return: None                                               
    // pre: The file at the provided path must exist and be a valid 
    //      music file.                                            
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
    // post: The file path of the currently loaded song is returned. 
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

#endif /* backgroundMusic_h */
