#include"PlantBullet.hpp"
#include <chrono>
using namespace std::chrono;

PlantBullet::PlantBullet(int x, int y, int d):locX(x), locY(y), damage(d){
    alive=true;
    lastMove = std::chrono::high_resolution_clock::now();;
    interval = 1;
}
	
void PlantBullet::update(){
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime-lastMove);
    if(duration.count() >= interval){
	move();
	lastMove = currentTime;
    }
}

void PlantBullet::move(){
    ++locX;
    //falls off screen
    if(locX>9)
	alive=false;
}

int PlantBullet::giveDamage() {
    alive = false;
    return damage;
}

bool PlantBullet::isAlive() {return alive;}
int PlantBullet::getX() {return locX;}
int PlantBullet::getY() {return locY;}


