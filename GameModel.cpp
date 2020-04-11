#include "GameModel.h"
#include "PeaShooter.hpp"
#include "rlutil.h"

void GameModel::Update(){
    zc.ZombieManager(); // creates zombies if needed
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
    
    for(size_t y = 0; y < 1; y++)
    {
        for (size_t x = 0; x < 10; x++) // i just picked the row length for ten since I guess it works
        {
            if (simulation.getCell(x, y) == true) // <---- I don't know where to pull this from in our project
            {
                // move cursor and render char
                rlutil::locate(x, y);
                rlutil::setChar('*');  //<-- 'Z' for zombie, 'P' for plant?
                //rutil::setChar('Z');
                //rutil::setChar('P');
            }
            else
            {
                continue;
            }
        }
    }

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
    std::cout << " we got " << numPlants << " plants" << std::endl;
    for(int i=0;i<10;++i) {
	if(myRow.checkForPlant(i)){
	    std::cout << "plant at " << i << std::endl;
	}
    }
}

bool GameModel::getStatus(){
    if(zc.getZombiesRemaining() <= 0){
        status = 0;
    }
    return status;
}
