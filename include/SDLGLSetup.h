#ifndef SDLGLSETUP_H
#define SDLGLSETUP_H
#include <time.h>
#include "../include/Timer.h"
//#include "Hitbox.h"
#include "FightScene.h"
//#include "Fighter.h"
class SDLGLSetup
{
    FightScene *fightscene;
    //Fighter *fighter1;
    //Fighter *fighter2;

    Uint8* keyboard;
    //Hitbox *box;
//GLuint texture=NULL; //this is a handle to our texture object

    SDL_Event event;
public:
    SDLGLSetup();
    bool update();
    void drawImage();
    void drawSetup();
    void drawEnd();
    int init();
    void init_GL();
    void clean_up();
    //bool handleinput();
    bool waitForNextFrame();

    //virtual ~SDLGLSetup();
private:
    bool quit;
    Timer t;
    bool wait;
};


#endif // SDLGLSETUP_H

