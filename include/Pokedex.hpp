#include "PokemonVector.hpp"
#include <string>
using namespace std;

class Pokedex : public PokemonVector {
private:
    static Pokedex *instance;
    string chemin = "pokedex.csv"; // I suggest this to be a constant or enviromental variable

    Pokedex();

public:
    static Pokedex *getInstance();
    // Since Pokedex inherits from PokemonVector, it should override the virtual method : displayAllPokemons()
    void displayAllPokemons() override;
};
