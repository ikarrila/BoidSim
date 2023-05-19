#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Flock.h"
#include "Boid.h"
#include <thread>
#include <iostream>

#include "ThreadPool.h"

const int WIDTH = 1200;
const int HEIGHT = 800;

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Boids Simulation");

    const auto processor_count = std::thread::hardware_concurrency();
    ThreadPool pool(processor_count);
    Flock flock(1000, pool);


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
