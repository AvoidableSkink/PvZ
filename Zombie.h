#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <chrono>
#include <iostream>
using namespace std::chrono;

class Zombie{
	private:
	struct{
		int x;
		int y;
	} location;
	int hitPoints;
	int damage;
	int speed;
	int interval;
	std::chrono::time_point<std::chrono::high_resolution_clock> lastShot;    


	public:
	Zombie(int startDamage, int hitPoints);
	virtual int update();
	virtual void updateLocation(int x, int y);
	virtual void lowerHitPoints(int amount);	
	virtual int getDamage();
	virtual void takeDamage(int damage);
	virtual void move();
	virtual int getHitPoints();
	virtual int getX();
	virtual int getY();
};

#endif
