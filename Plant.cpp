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

void Plant::shoot() {}

