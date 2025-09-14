#include "../include/Pokedex.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

Pokedex* Pokedex::instance = nullptr;

Pokedex::Pokedex() {
    loadFromCSV("pokedex.csv");
}

void Pokedex::loadFromCSV(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Failed to open CSV file: " + filename);
    }

    string line;
    while (getline(file, line)) {
        stringstream temp(line);
        string token;
        int id, evolution;
        string name;
        double maxHP, attack, defense;

        getline(temp, token, ','); id = stoi(token);
        getline(temp, name, ',');
        getline(temp, token, ','); evolution = stoi(token);
        getline(temp, token, ','); maxHP = stod(token);
        getline(temp, token, ','); attack = stod(token);
        getline(temp, token, ','); defense = stod(token);

        Pokemon p(id, name, evolution, maxHP, maxHP, attack, defense);
            addPokemon(p);

    }
    file.close();
}

Pokedex* Pokedex::getInstance() {
    if (instance == nullptr) {
        instance = new Pokedex();
    }
    return instance;
}

void Pokedex::displayAllPokemons() {
    cout << "=== Pokedex Entries ===\n";
    for (Pokemon& p : getPokemons()) {
        p.displayInfo();
    }
    cout << "Total Pokemons: " << getPokemonsCount() << endl;
}

Pokemon* Pokedex::getClone(int id)  {
    for ( Pokemon& p : getPokemons()) {
        if (p.getId() == id) {
            return new Pokemon(p);
        }
    }
    return nullptr;
}