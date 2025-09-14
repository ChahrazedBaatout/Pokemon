#ifndef TEST_HPP
#define TEST_HPP

#include "PokemonParty.hpp"
#include "PokemonAttack.hpp"
#include <vector>

class Test {
public:
    Test();
    void runTests();

private:
    PokemonParty party;
    PokemonAttack attack;
    void setupParty();
    void testAttackCreation();
    void testAddToAttackTeam();
    void testReintegration();
};

#endif
