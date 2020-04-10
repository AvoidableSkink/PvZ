#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ZombieController.h"
#include "Board.hpp"

class GameModel{


	private:
	ZombieController Zombie_Controller;
	Board board;

	public:
	GameModel();
	void Update();
	void Render();

};

#endif
