#ifndef FLOCK_H  // Check if BOID_H has not been defined yet
#define FLOCK_H

#include "Boid.h"
#include "ThreadPool.h"

class Flock {

public:
    std::vector<Boid> boids;
    ThreadPool& threadPool;

    Flock(int size, ThreadPool& threadPool);

    void update();

    void draw(sf::RenderWindow& window);


private:
    int flock_members;

};

#endif