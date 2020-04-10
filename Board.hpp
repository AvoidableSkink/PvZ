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
    std::vector<Zombie> zombies;

        
    void updateBullets(); //move some bullets 
    void updatePlants(); //go through and check on all the plants...

public:
    void updateBoard();

};
