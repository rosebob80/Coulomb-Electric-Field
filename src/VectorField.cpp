#include "VectorField.hpp"

VectorField::VectorField() {
    for (int32_t y = 0; y < WINDOW_HEIGHT; y += 10) {
        for (int32_t x = 0; x < WINDOW_WIDTH; x += 10) {
            positions.emplace_back(sf::Vector2<fpt>{(fpt) x, (fpt) y}, sf::Vector2<fpt>{0.0, 0.0}, 1, 1, false);
            magnitude.emplace_back(0, 1);
        }
    }

    for (auto & position : positions) {
        sf::RectangleShape rect;
        rect.setPosition(position.getP());

        rect.setSize(sf::Vector2<fpt>{1, 15});
        rect.setFillColor(sf::Color{200, 200, 200});
        lines.push_back(rect);
    }
}

void VectorField::draw(sf::RenderWindow *window, const std::vector<ChargedParticle> &particles) {

    for (uint64_t i = 0; i < positions.size(); i++) {
        auto pos = positions[i];
        magnitude[i] = positions[i].coulombForce(particles);
        auto mag = magnitude[i];

        auto rot = RAD2DEG(std::atan2(mag.y, mag.x)) + 90;
        lines[i].setRotation(rot);
    }

    for (uint64_t i = 0; i < positions.size(); i++) {
        if(lines[i].getRotation() != 90) {
            window->draw(lines[i]);
        }
    }
}