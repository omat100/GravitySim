#include <SFML/Graphics.hpp>
#include "PlanetManager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Gravity Sim");
    window.setFramerateLimit(60);

    PlanetManager manager;
    // manager.addPlanet(Planet({400, 300}, {0.f, 0.f}, 10000.f, 30.f, sf::Color::Yellow));
    // manager.addPlanet(Planet({550, 300}, {0.f, 183.f}, 1.f, 15.f, sf::Color::Black));

    sf::Font font;
    font.loadFromFile("../SpicyRice-Regular.ttf");

    bool showPanel = false;
    sf::Vector2f spawnPos;
    float mass = 500.f;
    float radius = 10.f;
    float velocityY = 80.f;

    int colorChoice = 0;
    std::vector<std::string> colorNames = {"White", "Red", "Blue", "Yellow", "Green"};
    std::vector<sf::Color> colors = {sf::Color::White, sf::Color::Red, sf::Color::Blue, sf::Color::Yellow, sf::Color::Green};

    sf::RectangleShape panel(sf::Vector2f(200.f, 185.f));
    panel.setFillColor(sf::Color(30, 30, 30, 200));
    panel.setOutlineColor(sf::Color::White);
    panel.setOutlineThickness(1.f);

    sf::Text massText, radiusText, velText, colorText, instructions;
    massText.setFont(font);      massText.setCharacterSize(14);    massText.setFillColor(sf::Color::White);
    radiusText.setFont(font);    radiusText.setCharacterSize(14);  radiusText.setFillColor(sf::Color::White);
    velText.setFont(font);       velText.setCharacterSize(14);     velText.setFillColor(sf::Color::White);
    colorText.setFont(font);     colorText.setCharacterSize(14);
    instructions.setFont(font);  instructions.setCharacterSize(12); instructions.setFillColor(sf::Color::Yellow);
    instructions.setString("Left click to spawn\nEsc to cancel");

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();
        if (dt > 0.02f) dt = 0.02f;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    if (showPanel) showPanel = false;
                    else window.close();
                }
                if (showPanel) {
                    if (event.key.code == sf::Keyboard::Up)    mass += 100.f;
                    if (event.key.code == sf::Keyboard::Down)  mass = std::max(1.f, mass - 100.f);
                    if (event.key.code == sf::Keyboard::W)     radius = std::min(50.f, radius + 2.f);
                    if (event.key.code == sf::Keyboard::S)     radius = std::max(2.f, radius - 2.f);
                    if (event.key.code == sf::Keyboard::D)     velocityY += 10.f;
                    if (event.key.code == sf::Keyboard::A)     velocityY -= 10.f;
                    if (event.key.code == sf::Keyboard::C)     colorChoice = (colorChoice + 1) % colors.size();
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Right) {
                    spawnPos = {(float)event.mouseButton.x, (float)event.mouseButton.y};
                    panel.setPosition(spawnPos);
                    showPanel = true;
                }
                if (event.mouseButton.button == sf::Mouse::Left && showPanel) {
                    manager.addPlanet(Planet(spawnPos, {0.f, velocityY}, mass, radius, colors[colorChoice]));
                    showPanel = false;
                }
            }
        }

        manager.update(dt);

        window.clear(sf::Color::Black);
        manager.draw(window);

        if (showPanel) {
            massText.setString("Mass: " + std::to_string((int)mass) + " (Up/Down)");
            radiusText.setString("Radius: " + std::to_string((int)radius) + " (W/S)");
            velText.setString("VelY: " + std::to_string((int)velocityY) + " (A/D)");
            colorText.setString("Color: " + colorNames[colorChoice] + " (C)");
            colorText.setFillColor(colors[colorChoice]);

            massText.setPosition(spawnPos + sf::Vector2f(10.f, 10.f));
            radiusText.setPosition(spawnPos + sf::Vector2f(10.f, 40.f));
            velText.setPosition(spawnPos + sf::Vector2f(10.f, 70.f));
            colorText.setPosition(spawnPos + sf::Vector2f(10.f, 100.f));
            instructions.setPosition(spawnPos + sf::Vector2f(10.f, 145.f));

            window.draw(panel);
            window.draw(massText);
            window.draw(radiusText);
            window.draw(velText);
            window.draw(colorText);
            window.draw(instructions);
        }

        window.display();
    }

    return 0;
}