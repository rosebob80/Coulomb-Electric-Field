#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <Common.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Probe  Ladung", sf::Style::Default);
    window.setFramerateLimit(30);

    tgui::GuiSFML gui{window};

    sf::Font arial;
    arial.loadFromFile("arial.ttf");

    Config config{
        .centerX = 150.0f,
        .centerY = 150.0f,
        .xTick = 100.0f,
        .yTick = 100.0f,
        .gridSize = 10.0f,
        .sample = 100,
        .radius = 5
    };

    //Graph graph(&arial, &window, &gui, &config);
    while (window.isOpen()) {
        //graph.update();
    }
}