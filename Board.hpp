#include <iostream>
#include "PlantBullet.hpp"
#include "Zombie.h"
#include <vector>

class Board {
private:
    std::vector<PlantBullet> liveBullets;
    std::vector<Zombie> zombies;
        
    void updateBullets(); //move some bullets 
    void updatePlants(); //go through and check on all the plants...

public:
    void updateBoard();

};
