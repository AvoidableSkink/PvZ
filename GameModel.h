#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ZombieController.h"
#include "Board.hpp"

class GameModel{


	private:
	Board board;
	ZombieController Zombie_Controller;


	public:
	GameModel();
	void Update();
	void Render();
	void set(){	
	ZombieController zc(board, 5, 5); // second two should take rows and cols
	Zombie_Controller = zc;
	}

};

#endif
