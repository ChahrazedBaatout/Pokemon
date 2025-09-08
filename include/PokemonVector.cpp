#include <iostream>
#include "PokemonVector.hpp"


void PokemonVector::displayAllPokemons() {
    for (Pokemon &pokemon : pokemons) {
        pokemon.displayInfo();
        std::cout << "------------------------" << std::endl;
    }
}