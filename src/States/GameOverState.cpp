#include "GameOverState.hpp"
#include "MainMenuState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"

void GameOverState::onEnter(Game&) {
    auto f = Assets::instance().getFont("ui");
    if (f) {
        text.setFont(*f);
    }
    text.setString("Game Over - " + message + "\nPress Enter to return to Menu");
    text.setCharacterSize(22);
    text.setPosition(200, 200);
}

void GameOverState::onExit(Game&) {}

void GameOverState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        g.getStates().replace(std::make_unique<MainMenuState>(), g);
    }
}

void GameOverState::update(Game&, float) {}
void GameOverState::draw(Game&, sf::RenderTarget& t) {
    t.draw(text);
}
