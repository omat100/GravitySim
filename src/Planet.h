# pragma once
#include <SFML/Graphics.hpp>
#pragma once
#include <SFML/Graphics.hpp>

class Planet {
private:
    sf::CircleShape shape;
public:
    sf::Vector2f velocity;
    float mass;

    Planet(sf::Vector2f position, sf::Vector2f velocity, float mass, float radius);
    void update(float dt);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
};