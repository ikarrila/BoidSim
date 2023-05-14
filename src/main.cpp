#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Flock.h"
#include "Boid.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Boids Simulation");
    Flock flock(100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        flock.update();

        window.clear();
        flock.draw(window);
        window.display();
    }

    return 0;
}
