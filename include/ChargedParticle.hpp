#pragma once

#include <SFML/Graphics.hpp>
#include <ostream>
#include "Common.hpp"

#define COULOMB_CONSTANT 0.000000000008854187812813

class ChargedParticle {
private:
    sf::Vector2<fpt> p;
    sf::Vector2<fpt> v;
    fpt q{};
    fpt m{};
    bool mobile{};

public:
    ChargedParticle(const sf::Vector2<fpt> &p, const sf::Vector2<fpt> &v, fpt q, fpt m, bool mobile);

    sf::Vector2<fpt> coulombForce(const std::vector<ChargedParticle> &particles);

    void updatePosition(const sf::Vector2<fpt>& coulomb, fpt deltaT);

    bool operator==(const ChargedParticle &rhs) const;

    bool operator!=(const ChargedParticle &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const ChargedParticle &particle);
};