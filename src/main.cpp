#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Flock.h"
#include "Boid.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Boids Simulation");
    Flock flock(200);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            /*
            if (event.key.code == sf::Keyboard::Escape)
                window.close();*/
        }

        flock.update();

        window.clear();
        flock.draw(window);
        window.display();
    }

    return 0;
}
