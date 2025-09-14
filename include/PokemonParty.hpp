#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP
#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {
public:
    PokemonParty();
    void displayAllPokemons() override;
    void removePokemon(int index);
};

#endif