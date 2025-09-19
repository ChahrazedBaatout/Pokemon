#include "PokemonAttack.hpp"
#include <stdexcept>

void PokemonAttack::addToAttackTeam(const Pokemon& pokemon) {
    if (getPokemonsCount() >= MAX_SIZE) {
        throw std::runtime_error("L’équipe d’attaque ne peut contenir que 6 Pokémon max !");
    }
    addPokemon(pokemon);
}

void PokemonAttack::reintegrateToParty(PokemonParty& party) {
    for (const auto& p : pokemons) {
        party.addPokemon(p);
    }
    pokemons.clear();
}
