#ifndef BOID_H  // Check if BOID_H has not been defined yet
#define BOID_H

#include <SFML/Graphics.hpp>
#include <vector>

class Flock;

class Boid {

public:
    Boid(float x, float y);

    void update();

    void applyRules(Flock& flock);

    void draw(sf::RenderWindow& window);

    void align(Flock& flock);

    void cohesion(Flock& flock);

    void separation(Flock& flock);

    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif