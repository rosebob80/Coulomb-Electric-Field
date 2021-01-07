#include <Common.hpp>

int main () {
    sf::Vector2<fpt> a{-10, 10};
    std::cout << mirrorHorizontal(a) << std::endl;
}