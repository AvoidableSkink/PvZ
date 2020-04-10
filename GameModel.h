
#pragma once
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ZombieController.h"
//#include "Board.hpp"
#include "BoardRow"

class GameModel{

private:
    //Board board;
    ZombieController zc;
    BoardRow myRow;	

public:
    GameModel(): zc(5,5){}
    void Update();
    void Render();
    void set(){	
     // second two should take rows and cols

    }
	

};

#endif
