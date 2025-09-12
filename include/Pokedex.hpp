#include "PokemonVector.hpp"
#include <string>
using namespace  std;

class Pokedex : public PokemonVector {
private:
    static Pokedex* instance;
    string chemin = "pokedex.csv";
    Pokedex();

public:
    static Pokedex* getInstance();

};
