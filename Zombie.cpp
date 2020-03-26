#include "Zombie.hpp"

Zombie::Zombie(int startDamage, int hitPoints):damage(startDamage), hitPoints(hitPoints){}


void Zombie::updateLocation(int x, int y){
	location.x = x;
	location.y = y;
}

void Zombie::lowerHitPoints(int amount){hitPoints -= amount;}

int Zombie::getDamage(){return damage;}

int Zombie::getHitPoints(){return hitPoints;}

int Zombie::getX(){return location.x;}

int Zombie::getY(){return location.y;}

