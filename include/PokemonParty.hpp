#include "../include/PokemonVector.hpp"

class PokemonParty : public PokemonVector {
private:
    vector<Pokemon> my_pokemons;

public:
    int getPokemonsCount() const;

    void addPokemonToParty(const Pokemon pokemon);

    Pokemon *extractPokemonFromPartyByIndex(int index);

    Pokemon *extractPokemonFromPartyByName(string name);
    // you're inherting from PokemonVector, you should implement the pure virtual functions here
    void displayAllPokemons() override;
};
