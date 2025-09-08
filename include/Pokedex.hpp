#include "PokemonVector.hpp"
#include <fstream>
#include <sstream>
#include <string>

const string chemin = "pokedex.csv";

class Pokedex: public PokemonVector {
private:
    static Pokedex* instance;
    Pokedex();

    public:
     Pokemon* getPokemonByName(string name) ;
    Pokemon* getPokemonByIndex(int index);
    static Pokedex* getInstance();
};
