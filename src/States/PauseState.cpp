#include "PauseState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"

void PauseState::onEnter(Game&) {
    auto f = Assets::instance().getFont("ui");
    if (f) {
        text.setFont(*f);
    }
    text.setString("Paused - Press Escape to Resume");
    text.setCharacterSize(22);
    text.setPosition(200, 200);
}

void PauseState::onExit(Game&) {}

void PauseState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) {
        g.getStates().pop(g);
    }
}

void PauseState::update(Game&, float) {}
void PauseState::draw(Game&, sf::RenderTarget& t) {
    t.draw(text);
}
