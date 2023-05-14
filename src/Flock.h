#ifndef FLOCK_H  // Check if BOID_H has not been defined yet
#define FLOCK_H

#include "Boid.h"

class Flock {

public:
    std::vector<Boid> boids;

    Flock(int size);

    void update();

    void draw(sf::RenderWindow& window);

private:
    int flock_members;

};

#endif