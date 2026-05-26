//
// Created by user on 5/26/2026.
//
# pragma once
#include "Planet.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>

class PlanetManager {
private:
    std::vector<Planet> planets;
public:
    PlanetManager();
    void addPlanet(Planet planet) { planets.push_back(planet); }
    void draw(sf::RenderWindow& window);
    void applyGravity(float dt);
    void update(float dt);
};
