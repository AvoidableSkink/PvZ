#include <iostream>
#include <vector>

class BoardRow {
private:
    vector<Plant> plants;
    vector<Zombie> zombies;
    vector<PlantBullet> bullets;
    
public:
    void moveObjects(); 
    void updateHealth();
    
};
