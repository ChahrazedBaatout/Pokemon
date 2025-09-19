#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "StateStack.hpp"
#include "../include/Pokedex.hpp"
#include "../include/PokemonParty.hpp"
#include "../include/PokemonAttack.hpp"

class Game {
private:
    sf::RenderWindow window;
    StateStack states;

    Pokedex* pokedex;       // Singleton
    PokemonParty party;     // L’équipe du joueur
    PokemonAttack attackTeam; // L’équipe d’attaque sélectionnée

public:
    Game();
    void run();

    // Getters pour que les States y accèdent
    sf::RenderWindow& getWindow() { return window; }
    StateStack& getStates() { return states; }
    Pokedex& getPokedex() { return *pokedex; }
    PokemonParty& getParty() { return party; }
    PokemonAttack& getAttackTeam() { return attackTeam; }
};

#endif // GAME_HPP
