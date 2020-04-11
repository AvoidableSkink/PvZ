#pragma once

#include <iostream>
#include <chrono>
#include "PlantBullet.hpp"

class Plant {
protected:
    int locX;
    int locY;

    int interval;
    int damage;
    int maxHealth;
    int currentHealth;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastShot;    
public: 
    void takeDamage(int d);
    int getHealth();
    int getX();
    int getY();//trying to decide if y is still necessary since things just are in a row...
    bool alive();
    bool readyToShoot();
    
   virtual PlantBullet shoot(int cols, int row); //for the sunflower this is generating sun | no sunflowers currently
   // and this is throwing errors
};
