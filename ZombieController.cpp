#include "ZombieController.h"

ZombieController::ZombieController(){
	//randomly pick number of zombies
	//for section of gameboard controlled by this controller
	zombiesRemaining = 15;
}


void ZombieController::CreateZombie(int a, int b, int row, int col){
	Zombie zom(a,b);
	zom.updateLocation(row, col);
	ZombieBox.push_back(zom);
	zombiesRemaining++;
}


void ZombieController::UpdateZombies(){
	for(Zombie &z : ZombieBox){
	//call functions / classes

	}
}


void ZombieController::RemoveZombie(int loc){
	ZombieBox.erase(ZombieBox.begin() + loc);
	zombiesRemaining--;
}
