#include "Plant.hpp"

void Plant::takeDamage(int d) {
    currentHealth -= d;
}

int Plant::getHealth() {
    return currentHealth;
}

bool Plant::alive() {
    if(currentHealth > 0) 
	return true;
    else
	return false;
}

bool Plant::readyToShoot() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime-lastShot);
    if(duration.count() >= interval)
	return true;
    else
	return false;
}

PlantBullet Plant::shoot(int cols, int row){
    PlantBullet p(cols, row, rand()%5);
    return p;
}



int Plant::getX() {return locX;}
int Plant::getY() {return locY;}
