#pragma once

#include <SFML/Graphics.hpp>
#include <ostream>
#include <sstream>
#include "Common.hpp"

#define COULOMB_CONSTANT 0.000000000008854187812813

inline uint64_t timeSinceEpochMs() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
}

class ChargedParticle {
private:
    sf::Vector2<fpt> p;
    sf::Vector2<fpt> v;
    fpt q{};
    fpt m{};
    bool mobile{};
    sf::Font * font;

public:
    ChargedParticle(const sf::Vector2<fpt> &p, const sf::Vector2<fpt> &v, fpt q, fpt m, bool mobile);

    ChargedParticle(const sf::Vector2<fpt> &p, const sf::Vector2<fpt> &v, fpt q, fpt m, bool mobile, sf::Font * font);

    [[nodiscard]] sf::Vector2<fpt> coulombForce(const std::vector<ChargedParticle> &particles) const;

    void updatePosition(const sf::Vector2<fpt>& coulomb, fpt deltaT);

    void draw(sf::RenderWindow * window);

    const sf::Vector2<fpt> &getP() const;

    bool operator==(const ChargedParticle &rhs) const;

    bool operator!=(const ChargedParticle &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const ChargedParticle &particle);
};