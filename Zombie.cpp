#include "Zombie.h"

#include <random>


Zombie::Zombie(int startDamage, int hitPoints):damage(startDamage), hitPoints(hitPoints){
	interval = rand()%5;
}


void Zombie::updateLocation(int x, int y){
	location.x = x;
	location.y = y;
}

void Zombie::lowerHitPoints(int amount){hitPoints -= amount;}

int Zombie::update( ){

	auto currentTime = std::chrono::high_resulution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime-lastShot);
    if(duration.count() >= interval){
	move();
	lastShot = currentTime;
	}



	return damage;
}

void Zombie::move(){
	location.x -= 1;
}

void Zombie::takeDamage(int damage){ //to take damage from the plant
	hitpoints -= damage;
}

int Zombie::getDamage(){return damage;} // to give the plant damage

int Zombie::getHitPoints(){return hitPoints;}

int Zombie::getX(){return location.x;}

int Zombie::getY(){return location.y;}

