#include "../include/Hitbox.h"

Hitbox::Hitbox()
{
    //ctor
}

Hitbox::Hitbox(float x,float y,float w,float h)
{
    xCoord = x;
    yCoord = y;
    width = w;
    height = h;
    isBody = false;
}

int Hitbox::getXCoord()
{
    return xCoord;
}

int Hitbox::getYCoord()
{
    return yCoord;
}

int Hitbox::getWidth()
{
    return width;
}

int Hitbox::getHeight()
{
    return height;
}

void Hitbox::setXCoord(float x)
{
    xCoord = x;
}

void Hitbox::setYCoord(float y)
{
    yCoord = y;
}

void Hitbox::setXYCoord(float x, float y)
{
    xCoord = x;
    yCoord = y;
}

void Hitbox::setWidth(float w)
{
    width = w;
}

void Hitbox::setHeight(float h)
{
    height = h;
}

void Hitbox::drawHitbox()
{
    glBegin( GL_QUADS );
    //red,green,blue,alpha
    glColor4f(0.0f, 1.0f, 0.0f, .25f);
    // Top-left vertex (corner)
    glVertex2f(xCoord, yCoord);
    // Bottom-left vertex (corner)
    glVertex2f(xCoord + width, yCoord);
    // Bottom-right vertex (corner)
    glVertex2f(xCoord + width, yCoord + width);
    // Top-right vertex (corner)
    glVertex2f(xCoord, yCoord + height);
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnd();
}

Hitbox::~Hitbox()
{
    //dtor
}
