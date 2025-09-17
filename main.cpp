#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "gui/HomePage/HomePage.hpp"
#include "gui/WelcomePage/WelcomePage.hpp"
#include "../include/Pokedex.hpp"
#include "../include/PokemonParty.hpp"
#include "src/Test.hpp"
#include <map>
#include <string>
#include <sstream>

int main() {
    try {

        Pokedex* dex = Pokedex::getInstance();
        dex->displayAllPokemons();
        std::cout << "Pokedex taille: " << dex->getPokemonsCount() << " Pokémon loaded." << std::endl;

        // Setup window
        sf::RenderWindow window(sf::VideoMode(800, 600), "Pokemon Selector");
        window.setFramerateLimit(60);

        // Initialize party with Pokémon 1-12
        PokemonParty party;
        for (int i = 1; i <= 12; ++i) {
            Pokemon* p = dex->getClone(i);
            if (p) {
                party.addPokemon(*p);
                delete p;
                std::cout << "Added Pokémon #" << i << " to party." << std::endl;
            } else {
                std::cerr << "Failed to clone Pokémon #" << i << std::endl;
            }
        }
        std::cout << "Party size: " << party.getPokemonsCount() << std::endl;

        PokemonParty attack;

        WelcomePage welcomePage;
        HomePage mainPage(party, attack, window);
        Test test;
        test.runTests();

        bool showWelcome = true;

        while (window.isOpen()) {
            sf::Event event{};
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            if (showWelcome) {
                welcomePage.update();
                window.draw(welcomePage);
                if (welcomePage.isTimeUp()) {
                    showWelcome = false;
                }
            } else {
                mainPage.update();
                window.draw(mainPage);
            }

            window.display();
        }


    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale : " << e.what() << std::endl;
        std::cout << "Appuyez sur Entrée pour quitter..." << std::endl;
        std::cin.get();
        return 1;
    }
    return 0;
}