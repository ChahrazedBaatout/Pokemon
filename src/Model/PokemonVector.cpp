#include "../include/PokemonVector.hpp"
#include <iostream>

Pokemon& PokemonVector::getPokemonAt(int index) {
    return pokemons.at(index);
}

size_t PokemonVector::getPokemonsCount() const {
    return pokemons.size();
}

std::vector<Pokemon>& PokemonVector::getPokemons() {
    return pokemons;
}

const std::vector<Pokemon>& PokemonVector::getPokemons() const {
    return pokemons;
}

void PokemonVector::addPokemon(const Pokemon& pokemon) {
    pokemons.push_back(pokemon);
}

void PokemonVector::removePokemon(int index) {
    if (index >= 0 && index < (int)pokemons.size()) {
        pokemons.erase(pokemons.begin() + index);
    }
}

void PokemonVector::displayAllPokemons() {
    std::cout << "=== Pokemons ===\n";
    for (auto& p : pokemons) {
        p.displayInfo();
    }
    std::cout << "Total: " << pokemons.size() << std::endl;
}
