#pragma once

#include <iostream>
#include <vector>
#include "PlantBullet.hpp"
#include "Zombie.h"
#include "BoardRow.hpp"

class Board {
private:
    std::vector<PlantBullet> liveBullets;
    BoardRow myRows[5];

        
    void updateBullets(); //move some bullets 
    void updatePlants(); //go through and check on all the plants...

public:
    void updateBoard();
    void addZombie(int row, Zombie zom){myRows[row].addZombie(zom);}


};
