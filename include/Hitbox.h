#ifndef HITBOX_H
#define HITBOX_H
#include <GL/gl.h>
#include <GL/glu.h>


class Hitbox
{
public:
    Hitbox();
    Hitbox(float,float,float,float);

    int getXCoord();
    int getYCoord();
    int getWidth();
    int getHeight();


    void setXCoord(float);
    void setYCoord(float);
    void setXYCoord(float, float);
    void setWidth(float);
    void setHeight(float);

    void drawHitbox();
    virtual ~Hitbox();
protected:
private:
    float xCoord, yCoord;
    float height, width;
    bool isBody;
};

#endif // HITBOX_H
