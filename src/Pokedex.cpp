#include "../include/Pokedex.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <map>

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
    bool firstLine = true;
    map<int, int> evolutionCount; // Map to track evolution count per ID

    while (getline(file, line)) {
        if (firstLine) { // Skip header
            firstLine = false;
            continue;
        }

        stringstream temp(line);
        string token;
        int id, evolution;
        string name;
        double maxHP, attack, defense;

        getline(temp, token, ','); id = stoi(token);      // #
        getline(temp, name, ',');                         // Name

        getline(temp, token, ',');                        // Type 1 (ignore)
        getline(temp, token, ',');                        // Type 2 (ignore)
        getline(temp, token, ',');                        // Total (ignore)

        getline(temp, token, ','); maxHP = stod(token);   // HP
        getline(temp, token, ','); attack = stod(token);  // Attack
        getline(temp, token, ','); defense = stod(token); // Defense

        // Increment evolution count for this ID
        evolutionCount[id]++;
        int count = evolutionCount[id];

        // Set evolution to 0 if this is the first occurrence (count == 1), otherwise count - 1
        evolution = (count == 1) ? 0 : count - 1;

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