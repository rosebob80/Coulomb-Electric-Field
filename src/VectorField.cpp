#include "VectorField.hpp"

VectorField::VectorField() {
    for (int32_t y = 0; y < WINDOW_HEIGHT; y += 20) {
        for (int32_t x = 0; x < WINDOW_WIDTH; x += 20) {
            positions.emplace_back(x, y);
            magnitude.emplace_back(0, 0);
        }
    }

    for (auto &position : positions) {
        sf::RectangleShape rect;
        rect.setPosition(position);

        rect.setSize(sf::Vector2<fpt>{1, 10});
        rect.setFillColor(sf::Color{150, 150, 150});
        lines.push_back(rect);
    }
}

void VectorField::draw(sf::RenderWindow *window, const std::vector<ChargedParticle> &particles) {

#pragma omp parallel for
    for (uint64_t i = 0; i < magnitude.size(); i++) {
        magnitude[i].x = 0;
        magnitude[i].y = 0;
        for (const auto &particle : particles) {
            magnitude[i] += particle.electricalField(positions[i]);
        }
        auto rot = RAD2DEG(std::atan2(magnitude[i].y, magnitude[i].x)) + 90;
        lines[i].setRotation(rot);
    }

    for (uint64_t i = 0; i < positions.size(); i++) {
        window->draw(lines[i]);
    }
}