#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Pokedex.hpp"
#include "PokemonParty.hpp"
#include "PokemonAttack.hpp"
#include "State.hpp"

class Game {
private:
    sf::RenderWindow window;
    Pokedex* pokedex;
    PokemonParty party;
    PokemonAttack attack;
    State* currentState;

public:
    Game();
    ~Game();
    void run();
    void setState(State* newState);
    sf::RenderWindow& getWindow();
    PokemonParty& getParty();
    PokemonAttack& getAttack();
    Pokedex* getPokedex();
};

#endif // GAME_HPP