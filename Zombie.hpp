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
	virtual void updateLocation(int x, int y);
	virtual void lowerHitPoints(int amount);	
	virtual int getDamage();
	virtual int getHitPoints();
	virtual int getX();
	virtual int getY();
};

#endif
