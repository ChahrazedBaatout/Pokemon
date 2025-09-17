// gui/HomePage/HomePage.cpp
#include "HomePage.hpp"
#include "../include/Pokemon.hpp" // Include Pokemon for getId()
#include <iostream>

HomePage::HomePage(PokemonParty& partyRef, PokemonParty& attackRef, sf::RenderWindow& windowRef)
    : BasePage(), party(partyRef), attack(attackRef), window(windowRef) {
    text_.setString("Page principale");
    text_.setCharacterSize(48);
    text_.setFillColor(sf::Color::Green);
    text_.setPosition(180, 250);
    clock_.restart(); // Start the clock properly
}

void HomePage::update() {
    handleInput(); // Handle mouse input for Pokémon selection
}

bool HomePage::shouldHideText() const {
    return clock_.getElapsedTime().asSeconds() >= HIDE_TEXT_DURATION;
}

sf::Texture& HomePage::loadTexture(int id) {
    if (textures.find(id) == textures.end()) {
        sf::Texture texture;
        std::string path = "pokemon/" + std::to_string(id) + ".png";
        if (!texture.loadFromFile(path)) {
            std::cerr << "Failed to load texture: " << path << ", using fallback." << std::endl;
            sf::Image img;
            img.create(64, 64, sf::Color::Green);
            texture.loadFromImage(img);
        }
        textures[id] = texture;
    }
    return textures[id];
}

void HomePage::handleInput() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        const float CELL_SIZE = 80.f;
        const float GAP = 10.f;
        const float PARTY_START_X = 50.f;
        const float PARTY_START_Y = 50.f;
        const float ATTACK_START_X = 50.f; // Align attack grid below party
        const float ATTACK_START_Y = 400.f; // Position below party grid
        const int PARTY_COLS = static_cast<int>((window.getSize().x - 2 * PARTY_START_X) / (CELL_SIZE + GAP));
        const int ATTACK_COLS = 6; // Full row for attack selection

        // Check party grid
        if (mousePos.y < ATTACK_START_Y) {
            int col = static_cast<int>((mousePos.x - PARTY_START_X) / (CELL_SIZE + GAP));
            int row = static_cast<int>((mousePos.y - PARTY_START_Y) / (CELL_SIZE + GAP));
            int index = row * PARTY_COLS + col;
            if (index >= 0 && static_cast<size_t>(index) < party.getPokemonsCount()) {
                Pokemon* p = party.getPokemonByIndex(index);
                if (p && attack.getPokemonsCount() < 6) {
                    attack.addPokemon(*p);
                    party.removePokemon(index);
                    std::cout << "Moved Pokémon #" << p->getId() << " to attack slot." << std::endl;
                }
            }
        }
        // Check attack grid
        else if (mousePos.y >= ATTACK_START_Y && mousePos.y < ATTACK_START_Y + (CELL_SIZE + GAP)) {
            int col = static_cast<int>((mousePos.x - ATTACK_START_X) / (CELL_SIZE + GAP));
            if (col >= 0 && col < ATTACK_COLS && static_cast<size_t>(col) < attack.getPokemonsCount()) {
                Pokemon* p = attack.getPokemonByIndex(col);
                if (p) {
                    party.addPokemon(*p);
                    attack.removePokemon(col);
                    std::cout << "Moved Pokémon #" << p->getId() << " back to party." << std::endl;
                }
            }
        }
    }
}

// Grid rendering
void HomePage::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Only draw text if it shouldn't be hidden
    if (!shouldHideText()) {
        BasePage::draw(target, states);
    }

    const float CELL_SIZE = 80.f;
    const float GAP = 10.f;
    const float PARTY_START_X = 50.f;
    const float PARTY_START_Y = 50.f;
    const float ATTACK_START_X = 50.f; //
    const float ATTACK_START_Y = 400.f;
    const int PARTY_COLS = static_cast<int>((window.getSize().x - 2 * PARTY_START_X) / (CELL_SIZE + GAP));
    (party.getPokemonsCount() + PARTY_COLS - 1) / PARTY_COLS;
    constexpr int ATTACK_COLS = 6; // Full row for attack selection

    // Draw party grid across the entire window
    for (size_t i = 0; i < party.getPokemonsCount(); ++i) {
        int row = static_cast<int>(i / PARTY_COLS);
        int col = static_cast<int>(i % PARTY_COLS);
        sf::RectangleShape slot(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        slot.setPosition(PARTY_START_X + col * (CELL_SIZE + GAP), PARTY_START_Y + row * (CELL_SIZE + GAP));
        slot.setFillColor(sf::Color::Transparent);
        slot.setOutlineColor(sf::Color::White);
        slot.setOutlineThickness(2.f);
        target.draw(slot);

        Pokemon* p = party.getPokemonByIndex(static_cast<int>(i));
        if (p) {
            sf::Texture& texture = const_cast<HomePage*>(this)->loadTexture(p->getId());
            sf::Sprite sprite(texture);
            sprite.setOrigin(0, 0);
            sprite.setPosition(PARTY_START_X + col * (CELL_SIZE + GAP), PARTY_START_Y + row * (CELL_SIZE + GAP));
            float scale = CELL_SIZE / sprite.getLocalBounds().width;
            sprite.setScale(scale, scale);
            target.draw(sprite);
        }
    }

    // Draw attack grid as a single row
    for (int i = 0; i < 6; ++i) {
        sf::RectangleShape slot(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        slot.setPosition(ATTACK_START_X + i * (CELL_SIZE + GAP), ATTACK_START_Y);
        slot.setFillColor(sf::Color::Transparent);
        slot.setOutlineColor(sf::Color::White);
        slot.setOutlineThickness(2.f);
        target.draw(slot);

        if (static_cast<size_t>(i) < attack.getPokemonsCount()) {
            Pokemon* p = attack.getPokemonByIndex(i);
            if (p) {
                sf::Texture& texture = const_cast<HomePage*>(this)->loadTexture(p->getId());
                sf::Sprite sprite(texture);
                sprite.setOrigin(0, 0);
                sprite.setPosition(ATTACK_START_X + i * (CELL_SIZE + GAP), ATTACK_START_Y);
                float scale = CELL_SIZE / sprite.getLocalBounds().width;
                sprite.setScale(scale, scale);
                target.draw(sprite);
            }
        }
    }
}