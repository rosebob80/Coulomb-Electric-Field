#include <Common.hpp>

int main () {
    sf::Vector2<fpt> a{-10, 10};
    mirrorHorizontal(a);
    std::cout << a << std::endl;
}
