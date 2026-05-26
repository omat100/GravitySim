//
// Created by user on 5/26/2026.
//
# pragma once
#include "Planet.h"
#include <SFML/Graphics.hpp>
#include <vector>

class PlanetManager {
private:
    std::vector<Planet> planets;
public:
    PlanetManager();
    void addPlanet(Planet planet) { planets.push_back(planet); }
    void draw(sf::RenderWindow& window);
    void update(float dt);
};
