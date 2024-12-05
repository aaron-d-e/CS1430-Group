//
//  main.cpp
//  Sdl_test_please
//
//  Created by Jeffrey Rajkumar on 11/21/24.
//

/*#include <iostream>
#include "backgroundMusic.h"
#include "SoundEffect.h"

int main(){
    int x = 0;
    soundEffect sound("/Users/jeffreyrajkumar/Library/Mobile Documents/com~apple~CloudDocs/Downloads/The Essential Retro Video Game Sound Effects Collection [512 sounds] By Juhani Junkala/General Sounds/Interactions/sfx_sounds_interaction1.wav", 100);
    backgroundMusic background("/Users/jeffreyrajkumar/Library/Mobile Documents/com~apple~CloudDocs/Downloads/5 Action Chiptunes By Juhani Junkala 2/Juhani Junkala [Retro Game Music Pack] Level 3.wav", 100);

    background.playMusic(100);
        
    cout << "HELLOOOOO";
    
    
    
}*/
#include <iostream>
#include <cmath>
#include "SDL_Plotter.h"
#include "backgroundMusic.h"
#include "SoundEffect.h"

using namespace std;

void drawCircle(point loc, int size, color c, SDL_Plotter& g);
int main(int argc, char ** argv)
{

    backgroundMusic background("/Users/jeffreyrajkumar/Library/Mobile Documents/com~apple~CloudDocs/Downloads/5 Action Chiptunes By Juhani Junkala 2/Juhani Junkala [Retro Game Music Pack] Level 3.wav", 1);
    soundEffect sound("/Users/jeffreyrajkumar/Library/Mobile Documents/com~apple~CloudDocs/Downloads/The Essential Retro Video Game Sound Effects Collection [512 sounds] By Juhani Junkala/General Sounds/Interactions/sfx_sounds_interaction1.wav", 50);
    SDL_Plotter g(1000,1000);
    point p;
    color c;
    int size;
    Uint32 RGB;
    while (!g.getQuit())
    {
        
        background.playMusic(1);
        if(g.kbhit()){
            switch(toupper(g.getKey())){
                case 'C': g.clear();
                          break;
            }
        }

        if(g.mouseClick()){
            p = g.getMouseClick();
            size = rand()%50;
            c.R  = rand()%256;
            c.G  = rand()%256;
            c.B  = rand()%256;
            drawCircle(p, size, c, g);
            sound.playSound(50);
        }
        g.update();

    }
}


void drawCircle(point loc, int size, color c, SDL_Plotter& g){
    for(double i = -size; i <= size;i+=0.1){
        for(double j = -size; j <= size; j+=0.1){
            if(i*i + j*j <= size*size){
                g.plotPixel(round(loc.x+i),round(loc.y+j),c);
                
            }
        }
    }

}
