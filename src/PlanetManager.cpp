//
// Created by user on 5/26/2026.
//

#include "PlanetManager.h"

PlanetManager::PlanetManager() {}

void PlanetManager::draw(sf::RenderWindow& window) {
    for (auto& planet : planets) {
        planet.draw(window);
    }
}
void PlanetManager::applyGravity(float dt) {
    const float G = 500.f;

    // reset accelerations
    for (auto& planet : planets)
        planet.acceleration = {0.f, 0.f};

    for (int i = 0; i < planets.size(); i++) {
        for (int j = i + 1; j < planets.size(); j++) {
            sf::Vector2f dir = planets[j].getPosition() - planets[i].getPosition();
            float dist = std::sqrt(dir.x * dir.x + dir.y * dir.y);

            if (dist < 10.f) continue;

            float force = G * planets[i].mass * planets[j].mass / (dist * dist);
            sf::Vector2f normalized = dir / dist;

            planets[i].acceleration += normalized * (force / planets[i].mass);
            planets[j].acceleration -= normalized * (force / planets[j].mass);
        }
    }
}
void PlanetManager::update(float dt) {
    applyGravity(dt);
    for (auto& planet : planets) {
        planet.update(dt);
    }
}