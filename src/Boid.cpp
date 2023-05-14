#include "Flock.h"
#include "Boid.h"

Boid::Boid(float x, float y) {
    //shape = sf::CircleShape(5.f);
    sf::CircleShape triangle(10, 3);
    shape = triangle;
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);  // Set color to white
    //velocity = sf::Vector2f((std::rand() % 3) - 1, (std::rand() % 3) - 1);
    velocity = sf::Vector2f((std::rand() % 20 - 10) / 100.f, (std::rand() % 20 - 10) / 100.f);
}

void Boid::update() {
    shape.move(velocity);
    // Prevent boids from going off the screen
    if (shape.getPosition().x < 0) velocity.x = abs(velocity.x);
    else if (shape.getPosition().x > 800) velocity.x = -abs(velocity.x);
    if (shape.getPosition().y < 0) velocity.y = abs(velocity.y);
    else if (shape.getPosition().y > 600) velocity.y = -abs(velocity.y);
}

void Boid::applyRules(Flock& flock) {
    align(flock);
    cohesion(flock);
    separation(flock);
}

void Boid::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

void Boid::align(Flock& flock) {
    sf::Vector2f perceivedVelocity;
    for (Boid& other : flock.boids) {
        perceivedVelocity += other.velocity;
    }
    perceivedVelocity /= static_cast<float>(flock.boids.size());

    velocity += (perceivedVelocity - velocity) / 80.f;  // adjust this value as needed
}

void Boid::cohesion(Flock& flock) {
    sf::Vector2f centerOfMass;
    for (Boid& other : flock.boids) {
        centerOfMass += other.shape.getPosition();
    }
    centerOfMass /= static_cast<float>(flock.boids.size());

    velocity += (centerOfMass - shape.getPosition()) / 100.f;  // adjust this value as needed
}

void Boid::separation(Flock& flock) {
    sf::Vector2f c;
    for (Boid& other : flock.boids) {
        if (&other == this) continue;
        if (abs(shape.getPosition().x - other.shape.getPosition().x) < 20.f &&
            abs(shape.getPosition().y - other.shape.getPosition().y) < 20.f) {
            c -= other.shape.getPosition() - shape.getPosition();
        }
    }

    velocity += c / 8.f;  // adjust this value as needed
}