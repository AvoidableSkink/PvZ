#include <iostream>
#include <vector>

#include "Plant.hpp"
#include "Zombie.h"
#include "PlantBullet.hpp"

class BoardRow {
private:
    std::vector<Plant> plants;
    std::vector<Zombie> zombies;
    std::vector<PlantBullet> bullets;
    
public:
    void moveObjects(); 
    void updateHealth();
    
};
