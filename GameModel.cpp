#include "GameModel.h"
#include "PeaShooter.hpp"
#include "rlutil.h"

void GameModel::Update(){
   // zc.ZombieManager(); // creates zombies if needed
    myRow.moveObjects();
    myRow.updateHealth();
    myRow.eraseDead();
    
    if(myRow.checkZombieWin()){
        status = -1;
    }
}
	
//so I think we can use the y/rank to show where to print out the stuff for the rendering so its in the correct order
//I think trying rlutil.h will be helpful for this.
void GameModel::Render(){  // !!! Feel free to work on this code too... I think this is the major piece left !!!

    //bullets first, then zombies, then plants... because they may share a square, i think the ones most important to be seen are plants, then zombies, then bullets.
    if(processRank == 0)
	rlutil::cls();

//    rlutil::hidecursor();

    myRow.renderBullets();
    myRow.renderZombies();
    myRow.renderPlants();

    rlutil::showcursor();
}

//adds some pea shooters to the row
void GameModel::fill() {
    srand(time(0)+processRank);
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
//    std::cout << " we got " << numPlants << " plants" << std::endl;
    for(int i=0;i<10;++i) {
	if(myRow.checkForPlant(i)){
//	    std::cout << "plant at " << i << std::endl;
	}
    }
}

bool GameModel::getStatus(){
    if(zc.getZombiesRemaining() <= 0){
        status = 0;
    }
    return status;
}
