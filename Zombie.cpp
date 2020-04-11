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

//update should be void? had int in case stuff breaks
//also all this does is update location... so its ok to skip if they cant move
void Zombie::update( ){

    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime-lastShot);
    
    if(duration.count() >= interval){
	move();
	lastShot = currentTime;
    }
	// if this reached the other side of the board, player is dead
	
	}
}

void Zombie::move(){
	location.x -= 1;
}

void Zombie::takeDamage(int damage){ //to take damage from the plant
	hitPoints -= damage;
}

int Zombie::getDamage(){return damage;} // to give the plant damage

int Zombie::getHitPoints(){return hitPoints;}

int Zombie::getX(){return location.x;}

int Zombie::getY(){return location.y;}

