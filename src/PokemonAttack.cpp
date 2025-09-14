#include "../include/PokemonAttack.hpp"
#include <stdexcept>
#include <iostream>

using namespace std;

PokemonAttack::PokemonAttack() {}

void PokemonAttack::addToAttackTeam(const Pokemon& pokemon) {
    if (getPokemonsCount() >= MAX_SIZE) {
        throw runtime_error("PokemonAtt/ack limited to 6 Pokemons");
    }
    addPokemon(pokemon);
}

void PokemonAttack::createFromParty(PokemonParty& party, const vector<int>& indices) {
    this->getPokemons().clear();
    int selectedCount = 0;
    for (int idx : indices) {
        if (idx >= 0 && idx < party.getPokemonsCount() && selectedCount < MAX_SIZE) {
            const Pokemon& p = party.getPokemonAt(idx);
            addToAttackTeam(p);
            party.removePokemon(idx);
            selectedCount++;
        }
    }
}

void PokemonAttack::reintegrateToParty(PokemonParty& party) {
    for (const Pokemon& p : getPokemons()) {
        party.addPokemon(p);
    }
    getPokemons().clear();
}