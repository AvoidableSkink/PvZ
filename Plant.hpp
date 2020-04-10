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
    bool alive();
    bool readyToShoot();
    virtual PlantBullet shoot(){}; //for the sunflower this is generating sun
};
