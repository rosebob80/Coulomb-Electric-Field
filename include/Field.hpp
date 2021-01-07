#pragma once
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ChargedParticle.hpp"
#include "Common.hpp"

class Field {
private:
    std::vector<ChargedParticle> particles;
    sf::Font * font;
    sf::RenderWindow * window;
    Config * config;
public:
    Field(sf::Font *font, sf::RenderWindow *window, Config *config);
};