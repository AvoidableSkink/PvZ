#ifndef ZOMBIE_H
#define ZOMBIE_H


class Zombie{
	private:
	struct{
		int x;
		int y;
	} location;
	int hitPoints;
	int damage;
	int speed;

	public:
	Zombie(int startDamage, int hitPoints);
	void updateLocation(int x, int y);
	void lowerHitPoints(int amount);	
	int getDamage();
	int getHitPoints();
	int getX();
	int getY();
};

#endif
