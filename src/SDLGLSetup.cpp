#include "../include/SDLGLSetup.h"

using namespace std;
SDLGLSetup::SDLGLSetup()
{
    SDL_Event event;
    Uint8* keyboard;
    quit = false;
    //box = new Hitbox(100,100,200,200);
    wait = false;
    t.start();
}


bool SDLGLSetup::update()
{
    SDL_PumpEvents();
    keyboard = SDL_GetKeyState(NULL);


     if (keyboard[SDLK_RIGHT])
    {
        //if(fightscene->checkCollision(f1hb,f2hb))
        fightscene->setMovementFighter0(1);
    }
    else if (keyboard[SDLK_LEFT])
    {
         //&& fightscene->getFighter0().getState() != 3
        fightscene->setMovementFighter0(2);
    }
    else
    {
        fightscene->setMovementFighter0(3);
    }
    /*if (keyboard[SDLK_DOWN])
    {
    }
    */if (keyboard[SDLK_UP])
    {
        // && fightscene->getFighter0().getState() != 3
        fightscene->setJumpFighter0();
    }
    if (keyboard[SDLK_d])
    {
        fightscene->setMovementFighter1(1);
    }
    else if (keyboard[SDLK_a])
    {
        fightscene->setMovementFighter1(2);
    }
    else
    {
        fightscene->setMovementFighter1(3);
    }
    /*
    if (keyboard[SDLK_s])
    {
    fightscene->getFighter0().jump();
    }
    */if (keyboard[SDLK_w])
    {
        fightscene->setJumpFighter1();
    }

    if (keyboard[SDLK_ESCAPE])
    {
        quit = true;
        return quit;
    }
    if (keyboard[SDLK_SPACE])
    {
        fightscene->setstate();
    }


     fightscene->updateFightScene();
     drawImage();
     drawEnd();
     drawSetup();

}
//SDL_Joystick *stick = NULL;


void SDLGLSetup::drawImage()
{
    fightscene->drawFighters();
}

void SDLGLSetup::drawSetup()
{
    glClear( GL_COLOR_BUFFER_BIT );
}

void SDLGLSetup::drawEnd()
{
    glLoadIdentity();
    SDL_GL_SwapBuffers();
}

int SDLGLSetup::init()
{
    SDL_Surface *screen;
    // Slightly different SDL initialization
    if ( SDL_Init(SDL_INIT_VIDEO) != 0 )
    {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    screen = SDL_SetVideoMode( 1440, 900, 16, SDL_OPENGL|SDL_FULLSCREEN);
    if ( !screen )
    {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }
    return 0;
}

void SDLGLSetup::init_GL()
{
    // Set the OpenGL state after creating the context with SDL_SetVideoMode
    glClearColor( 0, 0, 0, 0 );
    glEnable( GL_TEXTURE_2D ); // Need this to display a texture
    glViewport( 0, 0, 1440, 900);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( 0, 1440, 900, 0, -1, 1 );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    fightscene = new FightScene("bla.png",800.0,400.0,128.0,128.0,"img/vh.png",400.0,400.0,128.0,128.0,"img/vh2.png",false);
}

void SDLGLSetup::clean_up()
{

    SDL_Quit();
}


//bool SDLGLSetup::handleinput();

bool SDLGLSetup::waitForNextFrame()
{

    if(wait == false)
    {

     update();
     wait == true;
    }

    if(t.get_ticks()>1000/60)
    {
       wait = false;
       t.start();
    }
    else
        wait = true;
    return quit;

}

/*SDLGLSetup::~SDLGLSETUP()
{
        //dtor
]*/
