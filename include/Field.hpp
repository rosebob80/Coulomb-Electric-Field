#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <omp.h>
#include "ChargedParticle.hpp"
#include "Common.hpp"

class Field {
private:
    std::vector<ChargedParticle> particles;
    sf::Font *font;
    sf::RenderWindow *window;
    Config *config;
    tgui::GuiSFML *gui;
    fpt timeElapsed{};
    sf::Clock clock{};
    sf::Event event{};
protected:
    void drawParticles();

public:
    Field(sf::Font *font, sf::RenderWindow *window, Config *config, tgui::GuiSFML *gui);

    void update();

    [[nodiscard]] sf::Vector2<fpt> currentMouse() const;
};