#include"PlantBullet.hpp"
#include <chrono>
using namespace std::chrono;

PlantBullet::PlantBullet(int x, int y, int d):locX(x), locY(y), damage(d){
    alive=true;
    lastShot = std::chrono::high_resolution_clock::now();;
}
	
void PlantBullet::update(){
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime-lastShot);
    if(duration.count() >= interval){
	move();
    lastShot = currentTime;
	}


}

void PlantBullet::move(){}

int PlantBullet::giveDamage() {
    alive = false;
    return damage;
}

bool PlantBullet::isAlive() {return alive;}
int PlantBullet::getX() {return locX;}
int PlantBullet::getY() {return locY;}


