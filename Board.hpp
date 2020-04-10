#include <iostream>
#include "PlantBullet.hpp"
#include <vector>

class Board {
private:
    std::vector<PlantBullet> liveBullets;
        
    void updateBullets(); //move some bullets 
    void updatePlants(); //go through and check on all the plants...

public:
    void updateBoard();

};
