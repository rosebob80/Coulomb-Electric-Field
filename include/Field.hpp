#pragma once

#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <omp.h>
#include "ChargedParticle.hpp"
#include "VectorField.hpp"
#include "Common.hpp"
#include "FPS.hpp"

class Field {
private:
    std::vector<ChargedParticle> particles;
    sf::Font *font;
    sf::RenderWindow *window;
    tgui::GuiSFML *gui;
    fpt timeElapsed{};
    sf::Clock clock{};
    sf::Event event{};
    FPS fps;
    uint64_t lastAdded = 0;
    VectorField vectorField;
    tgui::CheckBox::Ptr showLines;
    tgui::CheckBox::Ptr addMobile;
    tgui::Slider::Ptr charge;
    tgui::Label::Ptr chargeLabel;
    tgui::Slider::Ptr mass;
    tgui::Label::Ptr massLabel;
protected:
    void drawParticles();

    void drawFPS();
public:
    Field(sf::Font *font, sf::RenderWindow *window, tgui::GuiSFML *gui);

    void update();

    [[nodiscard]] sf::Vector2<fpt> currentMouse() const;
};