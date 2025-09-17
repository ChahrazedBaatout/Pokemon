#ifndef POKEMON_SELECTION_STATE_HPP
#define POKEMON_SELECTION_STATE_HPP

#include "State.hpp"
#include <vector>

class Game;

class PokemonSelectionState : public State {
private:
    Game& game;
    std::vector<sf::Sprite> allPokemonSprites;
    std::vector<sf::Texture> allPokemonTextures;
    std::vector<sf::Sprite> selectedSprites;
    std::vector<sf::Texture> selectedTextures;
    sf::Text instructions;
    sf::RectangleShape scrollBar;
    float scrollOffset = 0.0f;
    int selectedCount = 0;

public:
    PokemonSelectionState(Game& g);
    void handleEvent(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif