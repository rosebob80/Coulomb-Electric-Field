#pragma once
#include <SFML/System.hpp>
#include <omp.h>
#include "ChargedParticle.hpp"
#include "Common.hpp"
class VectorField {
private:
    std::vector<sf::Vector2<fpt>> magnitude;
    std::vector<sf::Vector2<fpt>> positions;
    std::vector<sf::RectangleShape> lines;
public:
    VectorField();

    void draw(sf::RenderWindow * window, const std::vector<ChargedParticle>& particles);
};