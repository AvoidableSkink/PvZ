#pragma once

#include <iostream>
#include <string>
#include "Plant.hpp"
#include "PlantBullet.hpp"

class PeaShooter : public Plant {
public:
    PeaShooter(int x, int y);
    PlantBullet shoot();
};
