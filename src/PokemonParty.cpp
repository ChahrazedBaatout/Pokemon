#include "../include/PokemonParty.hpp"
#include <iostream>

using namespace std;

PokemonParty::PokemonParty() {}

void PokemonParty::displayAllPokemons() {
    cout << "=== Pokemon Party ===\n";
    for (Pokemon& p : getPokemons()) {
        p.displayInfo();
    }
    cout << "Total Pokemons in Party: " << getPokemonsCount() << endl;
}
void PokemonParty::removePokemon(int index) {
    if (index < 0 || index >= getPokemons().size()) {
        throw out_of_range("Index out of range");
    }
    getPokemons().erase(getPokemons().begin() + index);
}