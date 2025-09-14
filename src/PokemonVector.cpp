#include "../include/PokemonVector.hpp"

using namespace std;

void PokemonVector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);
}

Pokemon &PokemonVector::getPokemonAt(int index){
    if (index < 0 || index >= pokemons.size()) {
        throw out_of_range("Index out of range");
    }
    return pokemons[index];
}

size_t PokemonVector::getPokemonsCount() const {
    return pokemons.size();
}

 vector<Pokemon>& PokemonVector::getPokemons() {
    return pokemons;
}

Pokemon* PokemonVector::getPokemonByIndex(int index) {
    if (index < 0 || index >= pokemons.size()) {
        return nullptr;
    }
    return new Pokemon(pokemons[index]);
}

Pokemon* PokemonVector::getPokemonByName(string name) {
    for (const Pokemon& p : pokemons) {
        if (p.getName() == name) {
            return new Pokemon(p);
        }
    }
    return nullptr;
}