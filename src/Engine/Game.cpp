#include "Game.hpp"
#include "../States/BootState.hpp"
#include <iostream>

Game::Game()
    : window(sf::VideoMode(1024, 640), "Pokemon Selector (SFML)") {

    window.setFramerateLimit(60);

    // Charger le pokedex (singleton)
    pokedex = Pokedex::getInstance();
    pokedex->displayAllPokemons();

    std::cout << "Pokedex taille: "
              << pokedex->getPokemonsCount()
              << " Pokémon loaded." << std::endl;
}

void Game::run() {
    states.push(std::make_unique<BootState>(), *this);

    sf::Clock clk;
    while (window.isOpen()) {
        sf::Event e;
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();

            if (states.top())
                states.top()->handleEvent(*this, e);
        }

        float dt = clk.restart().asSeconds();

        if (states.top())
            states.top()->update(*this, dt);

        window.clear(sf::Color(20, 22, 28));

        if (states.top())
            states.top()->draw(*this, window);

        window.display();
    }
}
