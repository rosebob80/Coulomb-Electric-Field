#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Common.hpp>
#include <Field.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Probeladung", sf::Style::Default);
    window.setFramerateLimit(60);

    tgui::GuiSFML gui{window};

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    Field field(&arial, &window, &gui);
    while (window.isOpen()) {
        field.update();
    }
}