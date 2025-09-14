#ifndef POKEMONVECTOR_HPP
#define POKEMONVECTOR_HPP
#include <vector>
#include "Pokemon.hpp"
#include <fstream>
#include <iostream>

using namespace std;
using std::vector;

class PokemonVector {
private:
    vector<Pokemon> pokemons;

public:

    Pokemon& getPokemonAt(int index);
    size_t getPokemonsCount() const;
    vector<Pokemon>& getPokemons();
    void addPokemon(const Pokemon& pokemon);
    Pokemon* getPokemonByIndex(int index);
    Pokemon* getPokemonByName(string name);
    virtual void displayAllPokemons() = 0;
};
#endif
