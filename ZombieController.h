#ifndef ZOMBIECONTROLLER_H
#define ZOMBIECONTROLLER_H

#include"Zombie.h"
#include<vector>


// per wave
class ZombieController{						

	private:
	std::vector <Zombie> ZombieBox;
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
