#include"PlantBullet.hpp"




PlantBullet::PlantBullet(int x, int y, int d):locX(x), locY(y), damage(d){alive=true;}
	
void PlantBullet::update(){}

int PlantBullet::giveDamage() {
    alive = false;
    return damage;
}

bool PlantBullet::isAlive() {return alive;}
int PlantBullet::getX() {return locX;}
int PlantBullet::getY() {return locY;}


