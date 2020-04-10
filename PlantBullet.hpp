#pragma once
#ifndef PLANTBULLET_HPP
#define PLANYBULLET_HPP

#include <chrono>
#include<iostream>

class PlantBullet{
public:
    PlantBullet(int x, int y, int d);
    virtual void update();
    std::chrono::time_point<std::chrono::high_resolution_clock> lastMove;
    virtual void move();
    int giveDamage();
    bool isAlive();
    int getX();
    int getY();

private:
    int locX;
    int locY;
    int interval;
    int damage;
    bool alive;
};


#endif
