#include <iostream>

#include "BoardRow.hpp"

//returns true if plant found
bool checkForPlant(int space,std::vector<Plant> p);

//moves stuff that needs to move
//plants shoot instead of moving :)
void BoardRow::moveObjects() {
    for(int i=0;i<plants.size();++i) {
	if(plants[i].readyToShoot()){
	    PlantBullet tmp = plants[i].shoot();
	    bullets.push_back(tmp);
	}	
    }

    for(int i=0;i<bullets.size();++i) {
	bullets[i].update();
    }

    for(int i=0;i<zombies.size();++i) {
	//my idea for how to not let zombies move if they are with a plant
	if(!checkForPlant(zombies[i].getX(),plants)) //no plant on my square
	    zombies[i].update();
    }
}

//checks for collisions i.e. plants being eaten or zombies getting shot
void BoardRow::updateHealth() {
    //check if the zombies are eating a plant
    //just feeling for loops right now
    for(int i =0;i<zombies.size();++i){
	for(int j=0;j<plants.size();++j){
	    //collision
	    if(zombies[i].getX() == plants[j].getX()) { 
		int damage = zombies[i].getDamage();
		plants[j].takeDamage(damage);
		break;
	    }
	}
    }

    //check for collisions of bullets and zombies
    for(int i=0;i<bullets.size();++i){
	for(int j=0; zombies.size();++j){
	    //collision
	    if(bullets[i].getX() == zombies[j].getX()){
		int damage = bullets[i].giveDamage();
		zombies[j].takeDamage(damage);
	    }
	}
    }
}

void BoardRow::eraseDead() {
    
    //time to check and see what died
    for(int i=plants.size()-1;i>=0;--i){
	if(!plants[i].alive())
	    plants.erase(plants.begin() + i);
    }

    for(int i=bullets.size()-1;i>=0;--i){
	if(!bullets[i].isAlive())
	    bullets.erase(bullets.begin()+i);
    }

    //sameish thing for zombies
}

bool checkForPlant(int space, std::vector<Plant> p) {
    for(int i=0;i<p.size();!p[i].alive()) {
	if(p[i].getX() == space)
	    return true;
    }
    return false;
}
