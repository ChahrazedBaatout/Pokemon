#include "../include/ExplorationState.hpp"
#include "../include/PokemonSelectionState.hpp"
#include"../include/Game.hpp"

ExplorationState::ExplorationState(Game& g) : game(g) {
    exploreText.setString("Exploration - Press S to Select Pokémon");
    exploreText.setCharacterSize(30);
    exploreText.setFillColor(sf::Color::Yellow);
    exploreText.setPosition(100, 200);
}

void ExplorationState::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S) {
        game.setState(new PokemonSelectionState(game));
    }
}

void ExplorationState::update() {}
void ExplorationState::draw(sf::RenderWindow& window) { window.draw(exploreText); }