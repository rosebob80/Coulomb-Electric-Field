#include "Common.hpp"

std::ostream &operator<<(std::ostream &os, const sf::Vector2<fpt> &vector) {
    os << "[x = " << vector.x << ", y = " << vector.y << "]";
    return os;
}

sf::Vector2<fpt> operator+(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x += scalar;
    ret.y += scalar;
    return ret;
}

sf::Vector2<fpt> operator-(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x -= scalar;
    ret.y -= scalar;
    return ret;
}

sf::Vector2<fpt> operator/(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x /= scalar;
    ret.y /= scalar;
    return ret;
}

sf::Vector2<fpt> operator*(const sf::Vector2<fpt> &lhs, fpt scalar) {
    sf::Vector2<fpt> ret(lhs);
    ret.x *= scalar;
    ret.y *= scalar;
    return ret;
}

sf::Vector2<fpt> unit(const sf::Vector2<fpt> &lhs) {
    return lhs / norm(lhs);
}

fpt norm(const sf::Vector2<fpt> &lhs) {
    return std::sqrt(std::pow(lhs.x, 2) + std::pow(lhs.y, 2));
}
