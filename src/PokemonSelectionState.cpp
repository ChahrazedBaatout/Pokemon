#include "../include/PokemonSelectionState.hpp"
#include "../include/ExplorationState.hpp"
#include "../include/Game.hpp"
#include <iostream>

PokemonSelectionState::PokemonSelectionState(Game& g) : game(g) {
    // Load font
    sf::Font font;
    font.loadFromFile("resources/font/arial.ttf");
    instructions.setFont(font);
    instructions.setString("Click to select up to 6 Pokémon. Use mouse wheel to scroll. Press Esc to back.");
    instructions.setCharacterSize(20);
    instructions.setFillColor(sf::Color::White);
    instructions.setPosition(10, 10);

    // Load all Pokémon sprites from Pokedex
    Pokedex* pokedex = game.getPokedex();
    const int gridWidth = 8;
    for (int i = 0; i < pokedex->getPokemonsCount() ; ++i) {
        Pokemon* p = &pokedex->getPokemonAt(i);
        sf::Texture tex;
        if (tex.loadFromFile(p->getImagePath())) {
            allPokemonTextures.push_back(tex);
            sf::Sprite spr(tex);
            spr.setPosition(50 + (i % gridWidth) * 100, 50 + (i / gridWidth) * 100);
            spr.setScale(0.3f, 0.3f);
            allPokemonSprites.push_back(spr);
        }
    }

    // Initialize scrollbar
    scrollBar.setSize(sf::Vector2f(20, 400));
    scrollBar.setFillColor(sf::Color(100, 100, 100));
    scrollBar.setPosition(750, 50);
}

void PokemonSelectionState::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
        game.setState(new ExplorationState(game));
    } else if (event.type == sf::Event::MouseWheelScrolled) {
        scrollOffset -= event.mouseWheelScroll.delta * 20.0f; // Adjust scroll speed
        if (scrollOffset < 0) scrollOffset = 0;
        const float maxOffset = (allPokemonSprites.size() / 8 + 1) * 100 - 500; // Window height - grid height
        if (scrollOffset > maxOffset) scrollOffset = maxOffset;
    } else if (event.type == sf::Event::MouseButtonPressed && selectedCount < 6) {
        sf::Vector2f mouse = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
        PokemonParty& attack = game.getAttack();
        for (size_t i = 0; i < allPokemonSprites.size(); ++i) {
            sf::Sprite& spr = allPokemonSprites[i];
            sf::FloatRect bounds = spr.getGlobalBounds();
            bounds.top += scrollOffset;
            if (bounds.contains(mouse)) {
                Pokemon* p = game.getPokedex()->getClone(game.getPokedex()->getPokemonAt(i).getId());
                if (p) {
                    attack.addPokemon(*p);
                    selectedTextures.push_back(allPokemonTextures[i]);
                    sf::Sprite selectedSpr(allPokemonTextures[i]);
                    selectedSpr.setPosition(50 + selectedCount * 100, 500); // Selected area
                    selectedSpr.setScale(0.3f, 0.3f);
                    selectedSprites.push_back(selectedSpr);
                    selectedCount++;
                    delete p; // Clean up clone
                }
                if (selectedCount == 6) {
                    instructions.setString("6 Pokémon selected! Press Esc to continue.");
                }
                return;
            }
        }
    }
}

void PokemonSelectionState::update() {
    // Update sprite positions with scroll offset
    const int gridWidth = 8;
    for (size_t i = 0; i < allPokemonSprites.size(); ++i) {
        allPokemonSprites[i].setPosition(50 + (i % gridWidth) * 100, 50 + (i / gridWidth) * 100 - scrollOffset);
    }
}

void PokemonSelectionState::draw(sf::RenderWindow& window) {
    window.draw(instructions);
    for (const auto& spr : allPokemonSprites) window.draw(spr);
    for (const auto& spr : selectedSprites) window.draw(spr);
    window.draw(scrollBar);
}