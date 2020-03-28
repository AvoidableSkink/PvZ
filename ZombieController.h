#ifndef ZOMBIECONTROLLER_H
#define ZOMBIECONTROLLER_H

#include<vector>


// per wave
class ZombieController{						

	private:
	std::vector <Zombie> ZombieBox;
	int zombiesRemaining;

	
	public:
	ZombieController();
	void CreateZombie(int a, int b, int row, int col);
	void UpdateZombies();
	void RemoveZombie(int loc);
	

};
