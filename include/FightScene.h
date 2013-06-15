#ifndef FIGHTSCENE_H
#define FIGHTSCENE_H
#include "Fighter.h"

//F0 = Fighter[0], F1 = fighter[1]
class FightScene
{
    public:
    FightScene();
    FightScene(string,float,float,float,float,string,float,float,float,float,string,bool);
    //In order... background stage(leave blank for now) location/name
    //F0 xPos, yPos, width(of sprite and main hitbox), height(of sprite and main hitbox),texture location/name
    //F1 xPos, yPos, width(of sprite and main hitbox), height(of sprite and main hitbox),texture location/name
    void drawFighters();

    void drawAll();
    //draws it all in the order it should, oh and drawui/health/background will probably go to private eventually!
    void drawUI();
    //draws most of the UI; blank for now.
    void drawHealth();
    //draws the health of the fighter; blank for now.
    void drawBackground();
    //blank for now; to be changed

    //possibly change the name; checks to see if a fighter is dead

    void setVelocityFighter0(float, float);
    void setVelocityFighter1(float, float);
    void walkFighter0(float); //true if collision
    void walkFighter1(float); //false if not
    void jumpFighter0();
    void jumpFighter1();
    void setJumpFighter0();
    void setJumpFighter1();
    void setMovementFighter0(int);
    void setMovementFighter1(int);
    int checkCollision(Hitbox,Hitbox);
    void fixCollision(int);

    bool checkXCollide(Hitbox); //true if collide, false if not.
    bool checkYCollide(Hitbox); //true if collide, false if not.
    Fighter getFighter0();
    Fighter getFighter1();
    void setstate();

    void updateFightScene();

        virtual ~FightScene();
    protected:
    private:

        Fighter *fighter[2];
        float length, currentCenter;
        //currentCenter is the middle pixel of the screen, as not the entire background will show at once
        //to be implemented; for now just leave null or whatever.
        bool roundOver, matchOver;
        int currentRound, F1Victories,F2Victories;
        //F1 = Fighter[0], F2 = fighter[1]

        int movementF0, movementF1;
        //1, walk right, 2 walk left, 0 neutral

        float walkspeed;

        bool F0Jump, F1Jump;
};

#endif // FIGHTSCENE_H
