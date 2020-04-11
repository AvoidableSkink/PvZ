#include "ZombieController.h"
#include <time.h>
#include <stdio.h> 
#include <stdlib.h> 

ZombieController::ZombieController(int row, int col): rows(row), cols(col){
	currentWaveSize = rand()%13;
	zombiesRemaining = rand()%15;
}

void ZombieController::CreateZombie(int damage, int hitpoints, int row, int col){
	Zombie zom(damage, hitpoints);
	zom.updateLocation(row, col);
	board.addZombie(row, zom);
	zombiesRemaining--;
}

void ZombieController::ZombieManager(){
	srand(time(0));
	if(currentWaveSize < 4){
		CreateZombie(rand()%5 + 1, rand()%20 + 1, rand()%rows, cols-1);
		currentWaveSize++;
		zombiesRemaining--;
	}
}

void ZombieController::RemoveZombie(int loc){
	ZombieBox.erase(ZombieBox.begin() + loc);
	zombiesRemaining--;
}


int ZombieController::getZombiesRemaining(){return zombiesRemaining;}
