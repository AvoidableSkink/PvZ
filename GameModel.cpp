#include "GameModel.h"
#include "PeaShooter.hpp"

void GameModel::Update(){
//    this->board.updateBoard();
    myRow.moveObjects();
    myRow.updateHealth();
    myRow.eraseDead();

}
	
void GameModel::Render(){



	
}

//adds some pea shooters to the row
void GameModel::fill() {
    srand(time(0));
    int numPlants = rand() % 6 + 1;
    
    int x;
    for(int i=0;i<numPlants;++i) {
	do{
	    x = rand()%10;
	} while(myRow.checkForPlant(x));
	PeaShooter tmp(x,0);//this 0 will change.... should be the rank of the processor ?
	myRow.addPlant(tmp);
    }

    //test stuff
    std::cout << " we got " << numPlants << " plants" << std::endl;
    for(int i=0;i<10;++i) {
	std::cout << "plant at " << i << "?" << std::endl;
	if(myRow.checkForPlant(i)){
	    std::cout << "plant at " << i << std::endl;
	}
    }
}
