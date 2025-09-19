#ifndef POKEDEX_HPP
#define POKEDEX_HPP

#include "PokemonVector.hpp"
#include <string>

class Pokedex : public PokemonVector {
private:
    static Pokedex* instance;

    Pokedex(); // constructeur privé pour Singleton

public:
    static Pokedex* getInstance();
    void loadFromCSV(const std::string& filename);

    void displayAllPokemons() override; // implémentation obligatoire
};

#endif // POKEDEX_HPP
