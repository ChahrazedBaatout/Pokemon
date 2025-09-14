#include "Test.hpp"
#include <iostream>

using namespace std;

Test::Test() {}

void Test::setupParty() {
    party.addPokemon(Pokemon(1, "Bulbasaur", 0, 45.0, 45.0, 49.0, 49.0));
    party.addPokemon(Pokemon(2, "Ivysaur", 1, 60.0, 60.0, 62.0, 63.0));
    party.addPokemon(Pokemon(3, "Venusaur", 2, 80.0, 80.0, 82.0, 83.0));
    cout << "Initial Party:" << endl;
    party.displayAllPokemons();
}

void Test::testAttackCreation() {
    vector<int> indices = {0, 1};
    attack.createFromParty(party, indices);
    cout << "Attack Team after creation:" << endl;
    attack.displayAllPokemons();
}

void Test::testAddToAttackTeam() {
    attack.addToAttackTeam(Pokemon(4, "Charmander", 0, 39.0, 39.0, 52.0, 43.0));
    cout << "Attack Team after adding Charmander:" << endl;
    attack.displayAllPokemons();

    try {
        attack.addToAttackTeam(Pokemon(5, "Charmeleon", 1, 58.0, 58.0, 64.0, 58.0));
        attack.addToAttackTeam(Pokemon(6, "Charizard", 2, 78.0, 78.0, 84.0, 78.0));
        attack.addToAttackTeam(Pokemon(7, "Squirtle", 0, 44.0, 44.0, 48.0, 65.0)); // Should throw
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << "Attack Team after limit test:" << endl;
    attack.displayAllPokemons();
}

void Test::testReintegration() {
    attack.reintegrateToParty(party);
    cout << "Party after reintegration:" << endl;
    party.displayAllPokemons();
}

void Test::runTests() {
    setupParty();
    testAttackCreation();
    testAddToAttackTeam();
    testReintegration();
}