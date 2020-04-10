#pragma once
#ifndef PLANTBULLET_HPP
#define PLANYBULLET_HPP



class PlantBullet{

public:
    PlantBullet(int x, int y, int d);
    virtual void update();
    int giveDamage();
    bool isAlive();
    int getX();
    int getY();

private:
    int locX;
    int locY;
    int damage;
    bool alive;
//callin it lastMove
};


#endif
