#ifndef FIGHTER_H
#define FIGHTER_H
#include "sprite.h"
#include "hitbox.h"
class Fighter : public Sprite
{
public:
    Fighter();
    Fighter(float,float,float,float,string, bool);
    float getHealth();
    void setHealth(float);
    void modifyHealth(float);
    bool isDead();
    void draw();
    void drawTheHitBox();
    void moveFighter(float,float);
    void setState(int);
    int getState();
    Hitbox getBodyHitBox();
    Hitbox getHeadHitBox();//blank for now!
    bool getDrawHitbox();
    void jump();
    float getStartingY();
    void setStartingY(float);
    void updateFighter();
    virtual ~Fighter();
protected:
private:
    Hitbox *hitboxes[2];//0 is body, 1 is head
    float health;
    bool drawHitbox;
    int state;
    // 1 = stand
    // 2 = crouch
    // 3 = air
    float fallspeed;
    float startingY;
};
/*void walkRight(Fighter);
  void walkLeft (Fighter);*/
#endif // FIGHTER_H
