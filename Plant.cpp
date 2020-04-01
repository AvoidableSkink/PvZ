#include "Plant.hpp"

void Plant::takeDamage(int d) {
    currentLife -= d;
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
    auto currentTime = std::chrono::high_resulution_clock::now();
    auto duration = std::hrono::duration_cast<chrono::seconds>(currentTime-lastShot)
    if(duration.count() >= interval)
	return true;
    else
	return false;
}

