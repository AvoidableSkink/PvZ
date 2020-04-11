#include "GameModel.h"
#include "PeaShooter.hpp"

void GameModel::Update(){
//    this->board.updateBoard();
    myRow.moveObjects();
    myRow.updateHealth();
    myRow.eraseDead();
    if(myRow.checkZombieWin()){
        status = -1;
    }

}
	
//so I think we can use the y/rank to show where to print out the stuff for the rendering so its in the correct order
//I think trying rlutil.h will be helpful for this.
void GameModel::Render(){
    /*
    size_t y = 0; y < simulation.getSizeY(); y++)
    {
        for (size_t x = 0; x < simulation.getSizeX(); x++)
        {
            if (simulation.getCell(x, y) == true)
            {
                // move cursor and render char
                rlutil::locate(x, y);
                rlutil::setChar('*');
            }
            else
            {
                continue;
            }
        }
    }

    rlutil::showcursor();
*/
std::cout << "rendering" <<std::endl;	
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
