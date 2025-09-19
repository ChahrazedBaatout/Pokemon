#ifndef POKEMONATTACK_HPP
#define POKEMONATTACK_HPP

#include "PokemonParty.hpp"

class PokemonAttack : public PokemonParty {
private:
    static const int MAX_SIZE = 6;

public:
    PokemonAttack() = default;

    void addToAttackTeam(const Pokemon& pokemon);
    void reintegrateToParty(PokemonParty& party);
};

#endif
