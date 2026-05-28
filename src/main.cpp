#include <SFML/Graphics.hpp>
#include "PlanetManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Sim");
    window.setFramerateLimit(60);

    PlanetManager manager;
    manager.addPlanet(Planet({400, 300}, {0.f, 0.f}, 10000.f, 30.f));
    // manager.addPlanet(Planet({550, 300}, {0.f, 258.f}, 1.f, 10.f));
    manager.addPlanet(Planet({550, 300}, {0.f, 183.f}, 1.f, 10.f));


    sf::Clock clock;
    sf::Clock spawnClock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        sf::Event event;
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (spawnClock.getElapsedTime().asSeconds() > 0.3f) {
                    sf::Vector2f pos(event.mouseButton.x, event.mouseButton.y);
                    // manager.addPlanet(Planet(pos, {0.f, 50.f}, 1.f, 8.f));
                    manager.addPlanet(Planet(pos, {0.f, 0.f}, 10.f, 10.f));
                    spawnClock.restart();
                }
            }
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }
        if (dt > 0.02f) dt = 0.02f;
        manager.update(dt);

        window.clear(sf::Color::Black);
        manager.draw(window);
        window.display();
    }

    return 0;
}