# pragma once
#include <SFML/Graphics.hpp>
#include <deque>

class Planet {
private:
    sf::CircleShape shape;
    std::deque<sf::Vector2f> trail;
    int maxTrailLength = 200;
public:
    sf::Vector2f velocity;
    float mass;
    sf::Vector2f acceleration;

    Planet(sf::Vector2f position, sf::Vector2f velocity, float mass, float radius);
    void update(float dt);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
};