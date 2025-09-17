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
        // Initialiser le Pokedex (lecture CSV)
        Pokedex* dex = Pokedex::getInstance();

        // Afficher tout le contenu du pokedex
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
                delete p; // Clean up clone after adding copy
                std::cout << "Added Pokémon #" << i << " to party." << std::endl;
            } else {
                std::cerr << "Failed to clone Pokémon #" << i << std::endl;
            }
        }
        std::cout << "Party size: " << party.getPokemonsCount() << std::endl;

        PokemonParty attack;

        // Texture cache for sprites
        std::map<int, sf::Texture> textures;
        auto loadTexture = [&](int id) -> sf::Texture& {
            if (textures.find(id) == textures.end()) {
                sf::Texture tex;
                std::string path = "pokemon/" + std::to_string(id) + ".png"; // Adjusted path
                if (!tex.loadFromFile(path)) {
                    std::cerr << "Failed to load texture: " << path << ", using fallback." << std::endl;
                    sf::Image img;
                    img.create(64, 64, sf::Color::Green);
                    tex.loadFromImage(img);
                }
                textures[id] = tex;
            }
            return textures[id];
        };

        // Initialize GUI pages
        WelcomePage welcomePage;
        HomePage mainPage;
        Test test;
        test.runTests();

        // No need for separate font loading; assume BasePage handles it
        // Verify font loading in WelcomePage/HomePage if needed

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

                // Handle Pokémon selection
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (mousePos.x < 400) {
                        int selectedPartyIndex = static_cast<int>(mousePos.y / 80);
                        if (selectedPartyIndex >= 0 && static_cast<size_t>(selectedPartyIndex) < party.getPokemonsCount()) {
                            Pokemon* p = party.getPokemonByIndex(selectedPartyIndex);
                            if (p && attack.getPokemonsCount() < 6) {
                                attack.addPokemon(*p);
                                party.removePokemon(selectedPartyIndex);
                                std::cout << "Moved Pokémon to attack slot." << std::endl;
                            }
                        }
                    } else {
                        int selectedAttackIndex = static_cast<int>(mousePos.y / 80);
                        if (selectedAttackIndex >= 0 && static_cast<size_t>(selectedAttackIndex) < attack.getPokemonsCount()) {
                            Pokemon* p = &attack.getPokemonAt(selectedAttackIndex);
                            if (p) {
                                party.addPokemon(*p);
                                attack.removePokemon(selectedAttackIndex);
                                std::cout << "Moved Pokémon back to party." << std::endl;
                            }
                        }
                    }
                }

                // Draw party
                for (size_t i = 0; i < party.getPokemonsCount(); ++i) {
                    Pokemon* p = party.getPokemonByIndex(static_cast<int>(i));
                    if (p) {
                        sf::Sprite sprite(loadTexture(p->getId()));
                        sprite.setPosition(50.f, 50.f + static_cast<float>(i * 80));
                        sprite.setScale(2.f, 2.f);
                        window.draw(sprite);
                    }
                }

                // Draw attack slots
                for (int i = 0; i < 6; ++i) {
                    sf::RectangleShape slot(sf::Vector2f(128.f, 64.f));
                    slot.setPosition(400.f, 50.f + static_cast<float>(i * 80));
                    slot.setFillColor(sf::Color::Transparent);
                    slot.setOutlineColor(sf::Color::White);
                    slot.setOutlineThickness(2.f);
                    window.draw(slot);
                    Pokemon* p = attack.getPokemonByIndex(i);
                    if (p) {
                        sf::Sprite sprite(loadTexture(p->getId()));
                        sprite.setPosition(410.f, 55.f + static_cast<float>(i * 80));
                        sprite.setScale(1.5f, 1.5f);
                        window.draw(sprite);
                    }
                }
            }

            window.display();
        }

        // Cleanup
       // Pokedex::destroyInstance(); // If implemented
    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale : " << e.what() << std::endl;
        std::cout << "Appuyez sur Entrée pour quitter..." << std::endl;
        std::cin.get();
        return 1;
    }
    return 0;
}