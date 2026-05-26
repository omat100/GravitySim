//
// Created by user on 5/26/2026.
//

#include "Planet.h"

#include "Planet.h"

Planet::Planet(sf::Vector2f position, sf::Vector2f velocity, float mass, float radius)
    : velocity(velocity), mass(mass) {
    shape.setRadius(radius);
    shape.setOrigin(radius, radius);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::White);
}

void Planet::update(float dt) {
    shape.move(velocity * dt);
}

void Planet::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

sf::Vector2f Planet::getPosition() {
    return shape.getPosition();
}