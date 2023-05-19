#include "Flock.h"

Flock::Flock(int size, ThreadPool& threadPool)
    : threadPool(threadPool) {
    std::srand(std::time(0));
    for (int i = 0; i < size; i++) {
        boids.push_back(Boid(std::rand() % 800, std::rand() % 600));
    }
}
/*
void Flock::update() {
    for (Boid& b : boids) {
        b.update();
    }
}*/

void Flock::update() {
    // Calculation phase
    for (Boid& b : boids) {
        threadPool.enqueue([&] { b.calculateNewVelocity(*this); });
    }
    threadPool.wait_all();

    // Application phase
    for (Boid& b : boids) {
        threadPool.enqueue([&] { b.applyNewVelocity(); b.update(); });
    }
    threadPool.wait_all();
}

void Flock::draw(sf::RenderWindow& window) {
    for (Boid& b : boids) {
        b.applyRules(*this);
        b.draw(window);
    }
}
