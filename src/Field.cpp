#include "Field.hpp"

Field::Field(sf::Font *font, sf::RenderWindow *window, Config *config, tgui::GuiSFML *gui) : font(font), window(window), config(config), gui(gui) {
    // Left positive static
    this->particles.emplace_back(sf::Vector2<fpt>{400, 400},
                                 sf::Vector2<fpt>{0.0, 0.0},
                                 -0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{400, 450},
                                 sf::Vector2<fpt>{0.0, 0.0},
                                 -0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{400, 500},
                                 sf::Vector2<fpt>{0.0, 0.0},
                                 -0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{400, 550},
                                 sf::Vector2<fpt>{0.0, 0.0},
                                 -0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{400, 600},
                                 sf::Vector2<fpt>{0.0, 0.0},
                                 -0.001,
                                 1000,
                                 false);

    // Middle
    this->particles.emplace_back(sf::Vector2<fpt>{500, 500},
                                 sf::Vector2<fpt>{0, 0},
                                 0.001,
                                 1000,
                                 true);

    // Right negative static
    this->particles.emplace_back(sf::Vector2<fpt>{600, 400},
                                 sf::Vector2<fpt>{0.0001, -0.0001},
                                 0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{600, 450},
                                 sf::Vector2<fpt>{0.0, -0.0},
                                 0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{600, 500},
                                 sf::Vector2<fpt>{0.0, -0.0},
                                 0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{600, 550},
                                 sf::Vector2<fpt>{0.0, -0.0},
                                 0.001,
                                 1000,
                                 false);

    this->particles.emplace_back(sf::Vector2<fpt>{600, 600},
                                 sf::Vector2<fpt>{0.0, -0.0},
                                 0.001,
                                 1000,
                                 false);
}

void Field::update() {
    this->timeElapsed = 100 * this->clock.restart().asSeconds();

    while (window->pollEvent(this->event)) {
        gui->handleEvent(event);
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }

    std::vector<sf::Vector2<fpt>> f(this->particles.size());

    for(int32_t i = 0; i < this->particles.size(); i++) {
        f[i] = particles[i].coulombForce(this->particles);
    }

    for(int32_t i = 0; i < this->particles.size(); i++) {
        particles[i].updatePosition(f[i], this->timeElapsed);
    }

    window->clear(sf::Color::Green);
    this->drawParticles();
    gui->draw();
    window->display();
}

void Field::drawParticles() {
    for (auto &particle : this->particles) {
        particle.draw(this->window);
    }
}

sf::Vector2<fpt> Field::currentMouse() const {
    sf::Vector2i pos = sf::Mouse::getPosition(*this->window);
    return sf::Vector2<fpt>{(fpt) pos.x, (fpt) pos.y};
}
