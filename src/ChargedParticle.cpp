#include "ChargedParticle.hpp"

ChargedParticle::ChargedParticle(const sf::Vector2 <fpt> &p, const sf::Vector2 <fpt> &v, fpt q, fpt m, bool mobile) : p(
        p), v(v), q(q), m(m), mobile(mobile) {}


ChargedParticle::ChargedParticle(const sf::Vector2 <fpt> &p, const sf::Vector2 <fpt> &v, fpt q, fpt m, bool mobile,
                                 sf::Font *font) : p(
        p), v(v), q(q), m(m), mobile(mobile), font(font) {

}

sf::Vector2 <fpt> ChargedParticle::coulombForce(const std::vector <ChargedParticle> &particles) const {
    sf::Vector2 <fpt> ret{0, 0};
    for (const auto &that : particles) {
        if (that != *this) {
            auto diff = this->p - that.p;

            if(diff.x < 0 && diff.x > -3) {
                diff.x = -3;
            } else if(diff.x > 0 && diff.x < 3) {
                diff.x = 3;
            }

            if(diff.y < 0 && diff.y > -3) {
                diff.y = -3;
            } else if(diff.y > 0 && diff.y < 3) {
                diff.y = 3;
            }
            ret += (unit(diff) / std::pow(norm(diff), 2.0))
                   * ((that.q * this->q) / (4.0 * PI * COULOMB_CONSTANT));
        }
    }
    return ret;
}

void ChargedParticle::updatePosition(const sf::Vector2 <fpt> &coulomb, fpt deltaT) {
    if (this->mobile) {
        auto radius = MAX(MIN(std::abs(this->m), 10), 3);

        // Acceleration
        sf::Vector2 <fpt> a = coulomb / this->m;

        // Speed
        sf::Vector2 <fpt> deltaV = a * deltaT;
        this->v += deltaV;


        // Position
        sf::Vector2 <fpt> deltaS = this->v * deltaT;
        this->p += deltaS;

        // Collision left or right
        if (this->p.x - radius < 0 || this->p.x + radius > WINDOW_WIDTH) {
            mirrorHorizontal(this->v);
        }

        // Collision top or bottom
        if (this->p.y - radius < 0 || this->p.y + radius > WINDOW_HEIGHT) {
            mirrorVertical(this->v);
        }
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

void ChargedParticle::draw(sf::RenderWindow *window) {
    auto radius = MAX(MIN(std::abs(this->m), 10), 3);
    sf::CircleShape circle(radius);
    circle.setPosition(this->p - radius / 2);

    if (this->q < 0) {
        circle.setFillColor(sf::Color::Blue);
    } else if (this->q == 0) {
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(1);
    } else {
        circle.setFillColor(sf::Color::Red);
    }

    window->draw(circle);

    std::stringstream ss;
    if (this->q < 0) {
        ss << "-";
    } else if(this->q > 0) {
        ss << "+";
    }
    sf::Text fpsText{ss.str(), *font, 20};
    if (this->q < 0) {
        fpsText.setPosition(this->p.x + 1, this->p.y - 10);
    } else if(this->q > 0) {
        fpsText.setPosition(this->p.x - 1, this->p.y - 7);
    }
    fpsText.setFillColor(sf::Color::White);
    window->draw(fpsText);
}

const sf::Vector2<fpt> &ChargedParticle::getP() const {
    return p;
}
