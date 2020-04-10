#include "PeaShooter.hpp"
#include "PlantBullet.hpp"

//y is going to be the rank....
PeaShooter::PeaShooter(int x, int y) { //just kinda picked, sure well change em later
    locX = x;
    locY = y;
    
    srand(time(0));
    //TODO: probably want more consistent damage, interval, health stats 
    interval = rand()%3+1; //in seconds
    damage = rand()%3+1;
    maxHealth = rand()%15+1;
    currentHealth = maxHealth;
    lastShot = std::chrono::high_resolution_clock::now();
}

PlantBullet PeaShooter::shoot() {
    PlantBullet newBullet(locX,locY,damage); 
    lastShot = std::chrono::high_resolution_clock::now();
    return newBullet;
}
