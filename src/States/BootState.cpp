#include "BootState.hpp"
#include "MainMenuState.hpp"
#include "../Engine/Game.hpp"

void BootState::onEnter(Game& g) {
    g.getStates().replace(std::make_unique<MainMenuState>(), g);
}

void BootState::onExit(Game&) {}
void BootState::handleEvent(Game&, const sf::Event&) {}
void BootState::update(Game&, float) {}
void BootState::draw(Game&, sf::RenderTarget&) {}
