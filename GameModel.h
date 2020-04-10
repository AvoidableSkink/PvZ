#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ZombieController.h"
#include "Board.hpp"

class GameModel{


	private:
	Board board;
	ZombieController zc;


	public:
	GameModel(): zc(5,5){}
	void Update();
	void Render();
	void set(){	
	 // second two should take rows and cols

	}
	

};

#endif
