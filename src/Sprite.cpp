#include "../include/Sprite.h"

Sprite::Sprite()
{
    xCoord = 100;
    yCoord = 100;
    width = 128;
    height = 128;
    setTexture("default");
}

Sprite::Sprite(float X, float Y, float W, float H, string filename)
{
    xCoord = X;
    yCoord = Y;
    width = W;
    height = H;
    setTexture(filename);
}

Sprite::~Sprite()
{
    glDeleteTextures( 1, &texture[0] );
    //dtor
}
//sets x and y
void Sprite::setXY(float X,float Y)
{
    xCoord = X;
    yCoord = Y;
}

void Sprite::setX(float X)
{
    xCoord = X;
}

void Sprite::setY(float Y)
{
    yCoord = Y;
}

float Sprite::getY(void)
{
    return yCoord;
}

float Sprite::getX(void)
{
    return xCoord;
}

void Sprite::setWidth(float newW)
{
    width = newW;
}

void Sprite::setHeight(float newH)
{
    height = newH;
}

float Sprite::getWidth()
{
    return width;
}

float Sprite::getHeight()
{
    return height;
}


void Sprite::setXVelocity(float newXVel)
{
    xVelocity = newXVel;
}

void Sprite::setYVelocity(float newYVel)
{
    yVelocity = newYVel;
}

void Sprite::setXYVelcoity(float newXVel,float newYVel)
{
    xVelocity = newXVel;
    yVelocity = newYVel;
}

float Sprite::getXVelocity()
{
    return xVelocity;
}

float Sprite::getYVelocity()
{
    return yVelocity;
}

bool Sprite::setTexture(string filename)
{
    /* load an image file directly as a new OpenGL texture */
    glGenTextures(1, &texture[0]);                  // Create The Texture
    // Typical Texture Generation Using Data From The Bitmap

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    texture[0] = SOIL_load_OGL_texture
                 (
                     filename.c_str(),
                     //"img/backup.bmp",
                     SOIL_LOAD_AUTO,
                     SOIL_CREATE_NEW_ID,
                     SOIL_FLAG_INVERT_Y
                 );

    if(texture[0] == 0)
    {
        cout << "failed\n";
        return false;
    }
    cout << "success\n";
    return true;
}

void Sprite::bindTexture()
{
    glBindTexture( GL_TEXTURE_2D, texture[0] );
}

void Sprite::draw()
{
    // Clear the screen before drawing
    //glClear( GL_COLOR_BUFFER_BIT );

    // Bind the texture to which subsequent calls refer to
    bindTexture();
    glBegin( GL_QUADS );
    // Top-left vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex2f( xCoord, yCoord);
    // Bottom-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex2f( xCoord + width, yCoord);
    // Bottom-right vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex2f( xCoord+width, yCoord+height);
    // Top-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex2f( xCoord, yCoord+height);
    glEnd();
    //glLoadIdentity();
    //SDL_GL_SwapBuffers();
}

void Sprite::translate(float x, float y)
{
    xCoord = getX() + x;
    yCoord = getY() + y;
    glTranslatef(x, y, 0 );
}

void Sprite::updateSelf()
{
    setX(getX() + xVelocity);
    setY(getY() + yVelocity);
}
