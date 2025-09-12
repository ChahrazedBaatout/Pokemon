//
// Created by mahdihadjsassi on 12/09/2025.
//

#include "HomePage.hpp"

HomePage::HomePage() {
    font_.loadFromFile("../resources/font/arial.ttf");
    mainText_.setFont(font_);
    mainText_.setString("Page principale");
    mainText_.setCharacterSize(48);
    mainText_.setFillColor(sf::Color::Green);
    mainText_.setPosition(180, 250);
}

void HomePage::update() {
}

void HomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mainText_, states);
}
