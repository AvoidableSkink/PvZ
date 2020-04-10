#include "GameModel.h"


void GameModel::Update(){
//    this->board.updateBoard();
    myRow.moveObjects();
    myRow.updateHealth();
    myRow.eraseDead();

}
	
void GameModel::Render(){



	
}


