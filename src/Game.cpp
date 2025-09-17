#include "Game.hpp"
#include "ExplorationState.hpp"
#include <ctime>

Game::Game() : window(sf::VideoMode(800, 600), "Pokemon Selector"), pokedex(Pokedex::getInstance()) {
    srand(static_cast<unsigned>(time(nullptr)));
    // Initialize party with some Pokémon (example)
    party.addPokemon(*pokedex->getClone(1)); // Bulbizarre
    party.addPokemon(*pokedex->getClone(4)); // Salamèche
    party.addPokemon(*pokedex->getClone(7)); // Carapuce
    currentState = new ExplorationState(*this);
}

Game::~Game() {
    delete currentState;
    // Note: Pokedex is a singleton, so its deletion is handled by getInstance() if needed
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            currentState->handleEvent(event);
        }
        currentState->update();
        window.clear();
        currentState->draw(window);
        window.display();
    }
}

void Game::setState(State* newState) {
    delete currentState;
    currentState = newState;
}

sf::RenderWindow& Game::getWindow() { return window; }
PokemonParty& Game::getParty() { return party; }
PokemonAttack& Game::getAttack() { return attack; }
Pokedex* Game::getPokedex() { return pokedex; }