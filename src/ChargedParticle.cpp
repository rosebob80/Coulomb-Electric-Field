#include "ChargedParticle.hpp"

ChargedParticle::ChargedParticle(const sf::Vector2<fpt> &p, const sf::Vector2<fpt> &v, fpt q, fpt m, bool mobile) : p(
        p), v(v), q(q), m(m), mobile(mobile) {}

sf::Vector2<fpt> ChargedParticle::coulombForce(const std::vector<ChargedParticle> &particles) {
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
        sf::Vector2<fpt> a = coulomb / this->m;
        sf::Vector2<fpt> deltaV = a * deltaT;
        this->v += deltaV;
    }
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
