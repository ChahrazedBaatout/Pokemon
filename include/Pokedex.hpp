#ifndef POKEDEX_HPP
#define POKEDEX_HPP
#include "PokemonVector.hpp"
#include <string>

class Pokedex : public PokemonVector {
private:
    static Pokedex* instance;
    Pokedex();
    void loadFromCSV(const string& filename);

public:
    static Pokedex* getInstance();
    void displayAllPokemons() override;
    Pokemon* getClone(int id) ;

};
#endif
