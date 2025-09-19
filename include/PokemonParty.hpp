#ifndef POKEMONPARTY_HPP
#define POKEMONPARTY_HPP

#include "PokemonVector.hpp"

class PokemonParty : public PokemonVector {
public:
    PokemonParty() = default;


    void displayAllPokemons() override; // impl obligatoire
         ~PokemonParty() override;};

#endif // POKEMONPARTY_HPP
