#include "Field.hpp"

Field::Field(sf::Font *font, sf::RenderWindow *window, tgui::GuiSFML *gui) : font(font), window(window), gui(gui) {
    addMobile = tgui::CheckBox::create();
    addMobile->setText("Moveable");
    addMobile->setPosition(5, WINDOW_HEIGHT - 150);
    addMobile->setChecked(true);

    chargeLabel = tgui::Label::create("Charge (-1 - 1)");
    chargeLabel->setPosition(5, WINDOW_HEIGHT - 110);
    charge = tgui::Slider::create(-1, 1);
    charge->setStep(0.1);
    charge->setPosition(5, WINDOW_HEIGHT - 90);
    charge->setHeight(10);
    charge->setValue(1);

    massLabel = tgui::Label::create("Mass (10000 - 100000)");
    massLabel->setPosition(5, WINDOW_HEIGHT - 50);
    mass = tgui::Slider::create(10000, 100000);
    mass->setStep(10000);
    mass->setPosition(5, WINDOW_HEIGHT - 30);
    mass->setHeight(10);
    mass->setValue(20000);

    gui->add(addMobile);
    gui->add(chargeLabel);
    gui->add(charge);
    gui->add(massLabel);
    gui->add(mass);
}

void Field::update() {
    this->timeElapsed = this->clock.restart().asSeconds();

    while (window->pollEvent(this->event)) {
        gui->handleEvent(event);
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        uint64_t now = timeSinceEpochMs();
        if (now - lastAdded > 250) {
            bool isMobile = this->addMobile->isChecked();
            this->particles.emplace_back(currentMouse(),
                                         sf::Vector2<fpt>{0.0, 0.0},
                                         charge->getValue(),
                                         mass->getValue(),
                                         isMobile, font);
            lastAdded = now;
        }

    }

    std::vector<sf::Vector2<fpt>> f(this->particles.size());

#pragma omp parallel for
    for (uint64_t i = 0; i < this->particles.size(); i++) {
        f[i] = particles[i].coulombForce(this->particles);
    }

#pragma omp parallel for
    for (uint64_t i = 0; i < this->particles.size(); i++) {
        particles[i].updatePosition(f[i], this->timeElapsed);
    }

    window->clear(sf::Color::White);
    this->vectorField.draw(window, this->particles);
    this->drawParticles();
    this->drawFPS();
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

void Field::drawFPS() {
    std::stringstream ss;
    fps.update();
    ss << "FPS: " << fps.getFPS();
    sf::Text fpsText{ss.str(), *font, 10};
    fpsText.setPosition(WINDOW_WIDTH - 50, 10);
    fpsText.setFillColor(sf::Color::Black);
    window->draw(fpsText);
}
