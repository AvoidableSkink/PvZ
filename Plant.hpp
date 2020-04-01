#include <iostream>
#include <chrono>

class Plant {
protected:
    int locX;
    int locY;

    int interval;
    int damage;
    int maxHealth;
    int currentHealth;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastShot;    
public: 
    void takeDamage(int d);
    int getHealth();
    bool alive();
    bool readyToShoot();
    virtual void shoot(); //for the sunflower this is generating sun
}
