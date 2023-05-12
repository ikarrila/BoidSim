#include <iostream>
#include <SFML/Graphics.hpp>

struct Position {
    float x;
    float y;
};

struct Velocity {
    float dx;
    float dy;
};

struct Boid {
    Position position;
    Velocity velocity;
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML window");

    while (window.isOpen())
    {
        sf::Event event;
        window.clear(sf::Color::Black);
        sf::RectangleShape rs(sf::Vector2f(100, 100));
        window.draw(rs);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}