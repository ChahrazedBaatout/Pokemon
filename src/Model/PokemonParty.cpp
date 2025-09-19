#include "PokemonParty.hpp"
#include <iostream>

void PokemonParty::displayAllPokemons() {
    std::cout << "=== Pokémon Party ===\n";
    for (auto& p : getPokemons()) {
        p.displayInfo();
    }
    std::cout << "Total in party: " << getPokemonsCount() << std::endl;
}
PokemonParty::~PokemonParty() {} // vide

