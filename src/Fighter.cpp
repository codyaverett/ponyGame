#include "../include/Fighter.h"

Fighter::Fighter()
{
    setX(100);
    setY(100);
    setWidth(128);
    setHeight(128);
    hitboxes[0] = new Hitbox(getX(),getY(),getWidth(),getHeight());
    drawHitbox = true;
    state = 1;
    fallspeed = .2;
    startingY = getY();
}

Fighter::Fighter(float X,float Y,float W,float H,string filename, bool drawhbox)
{
    setX(X);
    setY(Y);
    setWidth(W);
    setHeight(H);
    hitboxes[0] = new Hitbox(getX(),getY(),getWidth(),getHeight());
    setTexture(filename);
    drawHitbox = drawhbox;
    state = 1;
    fallspeed = .2;
    startingY = getY();
}

float Fighter::getHealth()
{
    return health;
}

void Fighter::setHealth(float newHealth)
{
    health = newHealth;
}

void Fighter::modifyHealth(float modification)
{
    health += modification;
}

bool Fighter::isDead()
{
    if(health > 0)
        return true;
    else
        return false;
}

void Fighter::draw()
{
    // Clear the screen before drawing
    //glClear( GL_COLOR_BUFFER_BIT );

    // Bind the texture to which subsequent calls refer to
    bindTexture();
    glBegin( GL_QUADS );
    // Top-left vertex (corner)
    glTexCoord2i( 1, 1 );
    glVertex2f( getX(), getY());
    // Bottom-left vertex (corner)
    glTexCoord2i( 0, 1 );
    glVertex2f( getX() + getWidth(), getY());
    // Bottom-right vertex (corner)
    glTexCoord2i( 0, 0 );
    glVertex2f( getX()+getWidth(), getY() + getHeight());
    // Top-right vertex (corner)
    glTexCoord2i( 1, 0 );
    glVertex2f( getX(), getY() + getHeight());
    glEnd();
    //glLoadIdentity();
    //SDL_GL_SwapBuffers();
}

void Fighter::drawTheHitBox()
{
    //if(drawHitbox == true)
    //{
    hitboxes[0]->drawHitbox();
    //}
}

void Fighter::moveFighter(float xAmount, float yAmount)
{
    //setX(getX()+xAmount);
    //setY(getY()+yAmount);
    //hitboxes[0]->setXCoord(getX());
    //hitboxes[0]->setYCoord(getY());
    setXVelocity(xAmount);
}

void Fighter::setState(int newState)
{
    state = newState;
}

int Fighter::getState()
{
    return state;
}

void Fighter::jump()
{
    //if (state == 2) //super jump
    if(state != 3 )
    {
        setYVelocity(-10);
        state = 3;
        //updateFighter();
    }
}

bool Fighter::getDrawHitbox()
{
    return drawHitbox;
}

Hitbox Fighter::getBodyHitBox()
{
    return *hitboxes[0];
}

Hitbox getHeadHitBox();

float Fighter::getStartingY()
{
    return startingY;
}

void Fighter::setStartingY(float startY)
{
    startingY = startY;
}
void Fighter::updateFighter()
{
    updateSelf();
    hitboxes[0]->setXYCoord(getX(), getY());
    if (state==3)
    {
        setYVelocity(getYVelocity() + fallspeed);
        if (getYVelocity() > 0)
        {
            if(getY() + getYVelocity() > startingY)
            {
                setY(startingY);
                state = 0;
                setYVelocity(0);
            }

        }
    }

}

Fighter::~Fighter()
{
    //dtor
}

/*void Fighter::walkRight(Fighter)
{

}

void Fighter::walkLeft(Fighter)
{

}*/
