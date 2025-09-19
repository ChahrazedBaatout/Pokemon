#ifndef POKEMONVECTOR_HPP
#define POKEMONVECTOR_HPP

#include <vector>
#include "Pokemon.hpp"

class PokemonVector {
protected:
    std::vector<Pokemon> pokemons;

public:
    virtual ~PokemonVector() = default;

    Pokemon& getPokemonAt(int index);
    size_t getPokemonsCount() const;
    std::vector<Pokemon>& getPokemons();
    const std::vector<Pokemon>& getPokemons() const;

    void addPokemon(const Pokemon& pokemon);
    void removePokemon(int index);

    // ✅ Implémentation commune (pas de "=0")
    virtual void displayAllPokemons();
};

#endif
