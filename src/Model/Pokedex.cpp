#include "Pokedex.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex() {
    loadFromCSV("pokedex.csv");
}

Pokedex* Pokedex::getInstance() {
    if (!instance) {
        instance = new Pokedex();
    }
    return instance;
}

void Pokedex::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier CSV : " + filename);
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (firstLine) { // ignorer header
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string token;

        int id, evolution = 0;
        std::string name;
        double hp, attack, defense;

        std::getline(ss, token, ','); id = std::stoi(token);
        std::getline(ss, name, ',');
        std::getline(ss, token, ','); // type1
        std::getline(ss, token, ','); // type2
        std::getline(ss, token, ','); // total
        std::getline(ss, token, ','); hp = std::stod(token);
        std::getline(ss, token, ','); attack = std::stod(token);
        std::getline(ss, token, ','); defense = std::stod(token);

        Pokemon p(id, name, evolution, hp, hp, attack, defense);
        addPokemon(p);
    }

    file.close();
}

void Pokedex::displayAllPokemons() {
    std::cout << "=== Pokedex ===\n";
    for (auto& p : getPokemons()) {
        p.displayInfo();
    }
    std::cout << "Total: " << getPokemonsCount() << " pokemons.\n";
}
