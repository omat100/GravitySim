#include <SFML/Graphics.hpp>
#include "PlanetManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Sim");
    window.setFramerateLimit(60);

    PlanetManager manager;
    manager.addPlanet(Planet({400, 300}, {50.f, 0.f}, 1000.f, 20.f));
    manager.addPlanet(Planet({200, 300}, {0.f, 50.f}, 500.f, 10.f));

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }

        manager.update(dt);

        window.clear(sf::Color::Black);
        manager.draw(window);
        window.display();
    }

    return 0;
}