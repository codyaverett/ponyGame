#ifndef SPRITE_H
#define SPRITE_H

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <soil.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;
class Sprite
{

public:


    Sprite();
    //Sprite(float, float, string);
    Sprite(float,float,float,float,string);
    void setXY(float,float);
    void setX(float);
    void setY(float);

    float getY(void);
    float getX(void);

    void setWidth(float);
    void setHeight(float);
    float getWidth();
    float getHeight();


    void setXVelocity(float);
    void setYVelocity(float);
    void setXYVelcoity(float,float);
    float getXVelocity();
    float getYVelocity();

    bool setTexture(string);
    void bindTexture();
    void draw();
    void translate(float,float);

    void updateSelf();
    virtual ~Sprite();

protected:
private:
    float xVelocity, yVelocity;
    float xCoord, yCoord;
    float height, width;
    GLuint texture[1];
};

#endif // SPRITE_H
