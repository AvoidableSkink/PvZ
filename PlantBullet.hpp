#pragma once
#ifndef PLANTBULLET_HPP
#define PLANYBULLET_HPP

#include <chrono>
#include<iostream>

class PlantBullet{

	public:
	PlantBullet(int x, int y, int d);
	virtual void update();
	virtual void move();
	std::chrono::time_point<std::chrono::high_resolution_clock> lastShot;   

	private:

	int locX;
	int locY;
	int damage;
	int interval;

};


#endif
