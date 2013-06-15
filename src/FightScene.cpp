#include "../include/FightScene.h"

FightScene::FightScene()
{
    fighter[0] = new Fighter(100.0,100.0,128.0,128.0,"img/vh.png", true);
    fighter[1] = new Fighter(200.0,100.0,128.0,128.0,"img/vh2.png",true);
    walkspeed = 7;
}

//THIS WILL REQUIRE MODIFICATION LATER WHEN ACTUAL CHARCTERS AND NOT PLACEHOLDERS ARE MADE
//In order... background stage(leave blank for now) location/name
//F1 xPos, yPos, width(of sprite and main hitbox), height(of sprite and main hitbox),texture location/name
//F2 xPos, yPos, width(of sprite and main hitbox), height(of sprite and main hitbox),texture location/name
FightScene::FightScene(string backTexture,float F0x,float F0y,float F0width,float F0height,string F0Texture,
                       float F1x,float F1y,float F1width,float F1height,string F1Texture,
                       bool showHitbox)
{
    //backTexture doesn't matter for now
    F0Texture = "img/vh.png";
    F1Texture = "img/vh2.png";
    //meh, just hard coded for now.
    fighter[0] = new Fighter(F0x,F0y,F0width,F0height,F0Texture,showHitbox);
    fighter[1] = new Fighter(F1x,F1y,F1width,F1height,F0Texture,showHitbox);
    walkspeed = 3;
}


void FightScene::drawFighters()
{
    fighter[0]->draw();
    fighter[1]->draw();
    glBindTexture(GL_TEXTURE_2D, NULL);
    if(fighter[0]->getDrawHitbox() == true)
    {
        fighter[0]->drawTheHitBox();
        fighter[1]->drawTheHitBox();
    }
}

int FightScene::checkCollision(Hitbox box1,Hitbox box2)
{
    int returner = 0;
    //left right collision
    float x1 = box1.getXCoord();
    float y1 = box1.getYCoord();
    float h1 = box1.getHeight();
    float w1 = box1.getWidth();

    float x2 = box2.getXCoord();
    float y2 = box2.getYCoord();
    float h2 = box2.getHeight();
    float w2 = box2.getWidth();

    if(x1 > x2 && x1-w1 < x2 || x1 < x2 && x1+w1 > x2)//modify to take into account y pos as well, not just x.
        returner += 1; //left
    //else if(x1 < x2 && x1+w1 > x2)
    //return 2; //right
    if(y1 < y2 && y1+h1 > y2 ||  y1 > y2 && y1-h1 < y2)
        //down
        returner += 2;

    return returner;
    //0 if no collide
    //1 if x
    //2 if y
    //3 if x and y collide
}
//blank for now, no point!
void FightScene::drawAll()
{

}

void FightScene::drawUI()
{

}

//draws most of the UI; blank for now.
void FightScene::drawHealth()
{

}
//draws the health of the fighter; blank for now.
void FightScene::drawBackground()
{

}
//blank for now; to be changed

//possibly change the name; checks to see if a fighter is dead

void FightScene::setVelocityFighter0(float xAmount, float yAmount)
{
    //fighter[0]->moveFighter(xAmount,yAmount);
    fighter[0]->setXVelocity(xAmount);
    //fighter[0]->updateFighter();
}

void FightScene::setVelocityFighter1(float xAmount, float yAmount)
{
    //fighter[1]->moveFighter(xAmount,yAmount);
    fighter[1]->setXVelocity(xAmount);
    //fighter[1]->updateFighter();
}

void FightScene::walkFighter0(float xAmount)
{
    Hitbox hbf0 = fighter[0]->getBodyHitBox();
    Hitbox hbf1 = fighter[1]->getBodyHitBox();
    hbf0.setXCoord(hbf0.getXCoord()+xAmount);

    int collideDetails = checkCollision(hbf0,hbf1);
    if (collideDetails == !1)
        setVelocityFighter0(xAmount,fighter[0]->getYVelocity());
    else if(collideDetails == 1)
    {

        setVelocityFighter0(xAmount/2,fighter[0]->getYVelocity());
        setVelocityFighter1(xAmount/2 + fighter[1]->getXVelocity(),fighter[1]->getYVelocity());
    }

    //else
    //hbf0.setXCoord(hbf0.getXCoord()-xAmount);
}



void FightScene::walkFighter1(float xAmount)
{
    Hitbox hbf0 = fighter[0]->getBodyHitBox();
    Hitbox hbf1 = fighter[1]->getBodyHitBox();
    hbf1.setXCoord(hbf1.getXCoord()+xAmount);
    int collideDetails = checkCollision(hbf1,hbf0);
    if (collideDetails != 1)//no problems with the x
        setVelocityFighter1(xAmount,fighter[1]->getYVelocity());
    if(collideDetails  == 1)//x axis problems oh no!
    {
        setVelocityFighter1(xAmount/2,fighter[1]->getYVelocity());
        setVelocityFighter0(xAmount/2 + fighter[0]->getXVelocity(),fighter[0]->getYVelocity());
    }
    //else
    //hbf0.setXCoord(hbf1.getXCoord()-xAmount);
}

void FightScene::jumpFighter0()
{
    fighter[0]->jump();
}

void FightScene::jumpFighter1()
{
    fighter[1]->jump();
}

void FightScene::setJumpFighter0()
{
    F0Jump = true;
}

void FightScene::setJumpFighter1()
{
    F1Jump = true;
}

void FightScene::setMovementFighter0(int dir) // 1 = right, 2 = left, 3 = nuetral.
{
    movementF0 = dir;
}

void FightScene::setMovementFighter1(int dir)
{
    movementF1 = dir;
}

Fighter FightScene::getFighter0()
{
    return *fighter[0];
}

Fighter FightScene::getFighter1()
{
    return *fighter[1];
}

void FightScene::updateFightScene()
{
    if(fighter[1]->getState() != 3)
    {
        if(movementF1 > 2)
            setVelocityFighter1(0,fighter[1]->getYVelocity());
    }
    if(fighter[0]->getState() != 3)
    {
        if (movementF0 == 1)
        {
            walkFighter0(walkspeed);
        }
        else if (movementF0 == 2)
        {
            walkFighter0(-walkspeed);
        }
        else
        {
            setVelocityFighter0(0,fighter[0]->getYVelocity());
        }
    }
    if(fighter[1]->getState() != 3)
    {
        if (movementF1 == 1)
        {
            walkFighter1(walkspeed);
        }
        else if (movementF1 == 2)
        {
            walkFighter1(-walkspeed);
        }
    }
    if(F0Jump)
    {
        jumpFighter0();
    }
    if(F1Jump)
    {
        jumpFighter1();
    }

    fighter[0]->updateFighter();
    fighter[1]->updateFighter();

    int collideDetails = checkCollision(fighter[0]->getBodyHitBox(),fighter[1]->getBodyHitBox());
    if(collideDetails == 1 || collideDetails == 3 )//problems with x hitboxes, they overlap! Oh no!
    {
        //1 is only x-y overlap
        //2 is only y overlap

        float f0x = fighter[0]->getXVelocity();
        float f0y = fighter[0]->getYVelocity();
        float f1x = fighter[1]->getXVelocity();
        float f1y = fighter[1]->getYVelocity();
        if(collideDetails == 3)
        {
        fighter[0]->setYVelocity(0);
        fighter[1]->setYVelocity(0);
        }
        fixCollision(collideDetails);
        fighter[0]->setXYVelcoity(f0x,f0y);
        fighter[1]->setXYVelcoity(f1x,f1y);
    }
        movementF0 = 3;
        movementF1 = 3;
        F0Jump = F1Jump = false;

}

void FightScene::fixCollision(int collideDetails)
{

    float f0xv = fighter[0]->getXVelocity();
    float f1xv = fighter[1]->getXVelocity();
    if(f0xv == 0)
    {
        if(f1xv != 0)
            fighter[1]->setXVelocity(-fighter[1]->getXVelocity());
    }
    else if(f1xv == 0)
    {
        if(f0xv != 0)
            fighter[1]->setXVelocity(-fighter[1]->getXVelocity());
    }
    if(f0xv > f1xv)//if f0 is moving to the right faster than f1(even if f1 is moving left)
    {

        fighter[1]->setXVelocity(-(f0xv- f1xv));

    }
    else
    {
        fighter[1]->setXVelocity(f0xv- f1xv);
        fighter[0]->setXVelocity(-(f0xv- f1xv));

    }

        fighter[0]->updateFighter();
        fighter[1]->updateFighter();
}





FightScene::~FightScene()
{
    //dtor
}

void FightScene::setstate()
{
    fighter[0]->setState(2);
}
