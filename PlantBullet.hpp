#ifndef PLANTBULLET_HPP
#define PLANYBULLET_HPP



PlantBullet{

	public:
	PlantBullet(int x, int y, int d);
	virtual void update();
	private:

	int locX;
	int locY;
	int damage;

};


#endif
