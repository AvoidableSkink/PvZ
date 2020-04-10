#include"PlantBullet.hpp"
#include <chrono>
using namespace std::chrono;



PlantBullet::PlantBullet(int x, int y, int d):locX(x), locY(y), damage(d){
    lastShot = std::chrono::high_resolution_clock::now();
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




