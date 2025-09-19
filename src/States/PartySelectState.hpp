#ifndef PARTYSELECTSTATE_HPP
#define PARTYSELECTSTATE_HPP

#include "../Engine/IState.hpp"
#include "../include/Pokedex.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

// Liaison 1:1 entre une case affichée et SON Pokémon
struct PokemonSprite {
    Pokemon pokemon;            // copie du Pokémon
    sf::Sprite sprite;          // sprite affiché
    sf::RectangleShape box;     // cadre de la case (sélection)
};

class PartySelectState : public IState {
private:
    // UI
    sf::Text header;
    sf::Text counterText;
    sf::RectangleShape infoPanel;
    sf::Text infoText;

    // Bouton START
    sf::RectangleShape startButton;
    sf::Text startText;

    // Textures stockées en pointeurs -> ne se déplacent plus en mémoire
    std::vector<std::unique_ptr<sf::Texture>> textures;

    // Grille de sprites liés à leur Pokemon
    std::vector<PokemonSprite> pokemonSprites;

    // Équipe choisie
    std::vector<Pokemon> selected;

    // Pour affichage de l’info
    Pokemon* currentPokemon = nullptr;

    // utilitaire: essaie .png, .01.png, .02.png
    bool loadPokemonTexture(int id, sf::Texture& outTex) const;

public:
    PartySelectState();

    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
