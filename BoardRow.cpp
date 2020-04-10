#include <iostream>

#include "BoardRow.hpp"

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
	//if(bullets[i].readyToMove()) {
	    //bullets[i].move();
	//}
    }

    for(int i=0;i<zombies.size();++i) {
	//if(zombies[i].readyToMove()){
	//    zombies[i].move();
	//}
    }
}

//checks for collisions i.e. plants being eaten or zombies getting shot
void BoardRow::updateHealth() {

}
