#include "PeaShooter.hpp"
#include "PlantBullet.hpp"

PeaShooter::PeaShooter(int x, int y) { //just kinda picked, sure well change em later
    locX = x;
    locY = y;
    
    //TODO: probably want more consistent damage, interval, health stats 
    interval = 3; //just some dummy data
    damage = 1;
    maxHealth = 8;
    currentHealth = maxHealth;
    lastShot = std::chrono::high_resolution_clock::now();
}

PlantBullet PeaShooter::shoot() {
    PlantBullet newBullet(0,0,damage); 
    lastShot = std::chrono::high_resolution_clock::now();
    return newBullet;
}
