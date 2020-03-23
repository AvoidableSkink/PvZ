#include <iostream>

class Plant {
protected:
    int interval;
    int damage;
    int maxHealth;
    int currentHealth;
public: 
    void takeDamage(int d);
    int getHealth();
    bool alive();
    virtual void shoot(); //for the sunflower this is generating sun
}
