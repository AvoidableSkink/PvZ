#include "ZombieController.h"
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 


ZombieController::ZombieController(int rows, int cols): rows(rows) :cols(cols){
	//randomly pick number of zombies
	//for section of gameboard controlled by this controller
	currentWaveSize = rand()%13;
	zombiesRemaining = 15;
}


void ZombieController::CreateZombie(int damage, int hitpoints, int row, int col){
	Zombie zom(damage, hitpoints);
	zom.updateLocation(row, col);
	ZombieBox.push_back(zom);
	zombiesRemaining++;
}

void ZombieController::ZombieManager(){
	srand(time(0));
	if(ZombieBox.size < 4){
		CreateZombie(intwidth)
	}


}




void ZombieController::RemoveZombie(int loc){
	ZombieBox.erase(ZombieBox.begin() + loc);
	zombiesRemaining--;
}
