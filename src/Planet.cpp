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
    velocity += acceleration * dt;
    shape.move(velocity * dt);

    trail.push_back(shape.getPosition());
    if (trail.size() > maxTrailLength)
        trail.pop_front();
}

void Planet::draw(sf::RenderWindow& window) {
    for (int i = 0; i < trail.size(); i++) {
        sf::CircleShape dot(2.f);
        dot.setPosition(trail[i]);
        const float alpha = static_cast<float>(i) / trail.size() * 255.f;
        dot.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha)));
        window.draw(dot);
    }
    window.draw(shape);
}

sf::Vector2f Planet::getPosition() {
    return shape.getPosition();
}