#pragma once
#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "ZombieController.h"
//#include "Board.hpp"
#include "BoardRow.hpp"

class GameModel{

private:
    //Board board;
    ZombieController zc;
    BoardRow myRow;	

public:
    GameModel(): zc(1,10) {fill();}
    void fill(); //this is used to add a starting # of random plants until user input is a thing
    void Update();
    void Render();
    bool status = true; // false if player is dead or zombies are gone
    bool getStatus(); 
    void set(){	
     // second two should take rows and cols

    }
	

};

#endif
