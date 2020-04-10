#ifndef ZOMBIECONTROLLER_H
#define ZOMBIECONTROLLER_H

#include"Zombie.h"
#include<vector>
#include "Board.hpp"


// per wave
class ZombieController{						

	private:
	std::vector <Zombie> ZombieBox;
 	Board board;
	int zombiesRemaining;
	int currentWaveSize;
	int kills = 0;
	int rows;
	int cols;

	
	public:
	ZombieController(int rows, int cols);
	void CreateZombie(int damage, int hitpoints, int row, int col);
	void ZombieManager();
	void RemoveZombie(int loc);
	

};

#endif
