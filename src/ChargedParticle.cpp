#include "ChargedParticle.hpp"

ChargedParticle::ChargedParticle(const sf::Vector2<fpt> &p, const sf::Vector2<fpt> &v, fpt q, fpt m, bool mobile) : p(
        p), v(v), q(q), m(m), mobile(mobile) {}

sf::Vector2<fpt> ChargedParticle::coulombForce(const std::vector<ChargedParticle> &particles) const {
    sf::Vector2<fpt> ret{0, 0};
    for (const auto &that : particles) {
        if (that != *this) {
            ret += (unit(this->p - that.p) / std::pow(norm(this->p - that.p), 2.0))
                   * ((that.q * this->q) / (4.0 * PI * COULOMB_CONSTANT));
        }
    }
    return ret;
}

void ChargedParticle::updatePosition(const sf::Vector2<fpt> &coulomb, fpt deltaT) {
    if (this->mobile) {
        // Acceleration
        sf::Vector2<fpt> a = coulomb / this->m;

        // Speed
        sf::Vector2<fpt> deltaV = a * deltaT;
        this->v += deltaV;

        // Position
        sf::Vector2<fpt> deltaS = this->v * deltaT;
        std::cout << deltaS << std::endl;
        this->p += deltaS;
    }
}

fpt ChargedParticle::potential(const sf::Vector2<fpt> &r) const {
    return this->q / (4.0 * PI * COULOMB_CONSTANT * norm(r - this->p));
}

bool ChargedParticle::operator==(const ChargedParticle &rhs) const {
    return p == rhs.p &&
           v == rhs.v &&
           q == rhs.q &&
           m == rhs.m &&
           mobile == rhs.mobile;
}

bool ChargedParticle::operator!=(const ChargedParticle &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const ChargedParticle &particle) {
    os << "p: " << particle.p << " v: " << particle.v << " q: " << particle.q << " m: " << particle.m << " mobile: "
       << particle.mobile;
    return os;
}

void ChargedParticle::draw(sf::RenderWindow * window) {
    auto radius = MAX(MIN(std::abs(this->m), 10), 3);
    sf::CircleShape circle(radius);
    circle.setPosition(this->p - radius / 2);

    if(this->q < 0) {
        circle.setFillColor(sf::Color::Blue);
    } else if(this->q == 0) {
        circle.setFillColor(sf::Color::White);
    } else {
        circle.setFillColor(sf::Color::Red);
    }

    window->draw(circle);
}
