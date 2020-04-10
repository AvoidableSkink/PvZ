#include "GameModel.h"


GameModel::GameModel(){
	ZombieController zc(GameModel::board, 5, 5); // second two should take rows and cols
	GameModel::Zombie_Controller = zc;
}
void GameModel::Update(){
	board.updateBoard();


	}
	
void GameModel::Render(){



	
}


