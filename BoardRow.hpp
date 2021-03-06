#pragma once

#include <iostream>
#include <vector>
#include "Zombie.h"
#include "Plant.hpp"
#include "PlantBullet.hpp"
#include "rlutil.h"

class BoardRow {
private:
    std::vector<Plant> plants;
    std::vector<Zombie> zombies;
    std::vector<PlantBullet> bullets;
    
public:
    void moveObjects(); 
    void updateHealth();
    void eraseDead();
    void addZombie(Zombie zom){zombies.push_back(zom);}
    void addPlant(Plant plant){plants.push_back(plant);}
    bool checkForPlant(int space);
    bool checkZombieWin();

    void renderBullets();
    void renderZombies();
    void renderPlants();
};
