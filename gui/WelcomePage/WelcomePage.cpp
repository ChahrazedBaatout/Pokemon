//
// Created by mahdihadjsassi on 12/09/2025.
//

#include "WelcomePage.hpp"

WelcomePage::WelcomePage() {
    font_.loadFromFile("../resources/font/arial.ttf");    text_.setFont(font_);
    text_.setString("POKEMON the Game!");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::White);
    text_.setPosition(200, 250);
}

bool WelcomePage::isTimeUp() const {
    return clock_.getElapsedTime().asSeconds() > 1.0f;
}

void WelcomePage::update() {
}

void WelcomePage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(text_, states);
}