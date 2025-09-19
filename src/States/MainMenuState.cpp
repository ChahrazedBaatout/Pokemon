#include "MainMenuState.hpp"
#include "PartySelectState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"

void MainMenuState::onEnter(Game&) {
    auto f = Assets::instance().getFont("ui");
    if (f) {
        title.setFont(*f);
    }
    title.setString("Pokemon Selector\nPress Enter to Start");
    title.setCharacterSize(28);
    title.setPosition(200, 200);
}

void MainMenuState::onExit(Game&) {}

void MainMenuState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        g.getStates().replace(std::make_unique<PartySelectState>(), g);
    }
}

void MainMenuState::update(Game&, float) {}

void MainMenuState::draw(Game&, sf::RenderTarget& t) {
    t.draw(title);
}
