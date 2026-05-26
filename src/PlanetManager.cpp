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
void PlanetManager::update(float dt) {
    for (auto& planet : planets) {
        planet.update(dt);
    }
}