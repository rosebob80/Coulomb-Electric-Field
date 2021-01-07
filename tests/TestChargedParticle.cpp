#include <iostream>
#include <Common.hpp>
#include <ChargedParticle.hpp>
#include <cassert>

void unchargedParticle() {
    ChargedParticle a{
            sf::Vector2<fpt>{0, 0},
            sf::Vector2<fpt>{0, 0},
            0,
            500,
            true
    };
    ChargedParticle b{
            sf::Vector2<fpt>{1, 0},
            sf::Vector2<fpt>{0, 0},
            2,
            500,
            true
    };
    ChargedParticle c{
            sf::Vector2<fpt>{-1, 0},
            sf::Vector2<fpt>{0, 0},
            3,
            500,
            true
    };
    std::vector<ChargedParticle> particles{
            a, b, c
    };
    sf::Vector2<fpt> coulomb = a.coulombForce(particles);
    assert(coulomb.x == 0);
    assert(coulomb.y == 0);
}

void chargedParticlePositive() {
    ChargedParticle a{
            sf::Vector2<fpt>{0, 0},
            sf::Vector2<fpt>{0, 0},
            1,
            500,
            true
    };
    ChargedParticle b{
            sf::Vector2<fpt>{1, 0},
            sf::Vector2<fpt>{0, 0},
            2,
            500,
            true
    };
    ChargedParticle c{
            sf::Vector2<fpt>{-1, 0},
            sf::Vector2<fpt>{0, 0},
            3,
            500,
            true
    };
    std::vector<ChargedParticle> particles{
            a, b, c
    };
    sf::Vector2<fpt> coulomb = a.coulombForce(particles);
    std::cout << coulomb << std::endl;
}

void chargedParticleNegative() {
    ChargedParticle a{
            sf::Vector2<fpt>{0, 0},
            sf::Vector2<fpt>{0, 0},
            -1,
            500,
            true
    };
    ChargedParticle b{
            sf::Vector2<fpt>{1, 0},
            sf::Vector2<fpt>{0, 0},
            2,
            500,
            true
    };
    ChargedParticle c{
            sf::Vector2<fpt>{-1, 0},
            sf::Vector2<fpt>{0, 0},
            3,
            500,
            true
    };
    std::vector<ChargedParticle> particles{
            a, b, c
    };
    sf::Vector2<fpt> coulomb = a.coulombForce(particles);
    std::cout << coulomb << std::endl;
}

void updatePositionPositive() {
    ChargedParticle a{
            sf::Vector2<fpt>{0, 0},
            sf::Vector2<fpt>{0, 0},
            1,
            500,
            true
    };
    ChargedParticle b{
            sf::Vector2<fpt>{1, 0},
            sf::Vector2<fpt>{0, 0},
            2,
            500,
            true
    };
    ChargedParticle c{
            sf::Vector2<fpt>{-1, 0},
            sf::Vector2<fpt>{0, 0},
            3,
            500,
            true
    };
    std::vector<ChargedParticle> particles{
            a, b, c
    };
    sf::Vector2<fpt> coulomb = a.coulombForce(particles);
    std::cout << a << std::endl;
    a.updatePosition(coulomb, 1.0f);
    std::cout << a << std::endl;
}

void updatePositionNegative() {
    ChargedParticle a{
            sf::Vector2<fpt>{0, 0},
            sf::Vector2<fpt>{0, 0},
            -1,
            500,
            true
    };
    ChargedParticle b{
            sf::Vector2<fpt>{1, 0},
            sf::Vector2<fpt>{0, 0},
            2,
            500,
            true
    };
    ChargedParticle c{
            sf::Vector2<fpt>{-1, 0},
            sf::Vector2<fpt>{0, 0},
            3,
            500,
            true
    };
    std::vector<ChargedParticle> particles{
            a, b, c
    };
    sf::Vector2<fpt> coulomb = a.coulombForce(particles);
    std::cout << a << std::endl;
    a.updatePosition(coulomb, 1.0f);
    std::cout << a << std::endl;
}

int main() {
    unchargedParticle();
    chargedParticlePositive();
    chargedParticleNegative();
    updatePositionPositive();
    updatePositionNegative();
}