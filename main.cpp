#include "include/SDLGLSetup.h"
int main(int argc, char *argv[])
{
    //image->setXY(100.0,100.0);
//Make sure the program waits for a quit

    SDLGLSetup *test = new SDLGLSetup();

    test->init();
    test->init_GL();


    test->drawSetup();
    test->drawImage();
    test->drawEnd();
    while(!test->waitForNextFrame())
    {
    }
    test->clean_up();
    return 0;
}
