#include "../include/Pokemon.hpp"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;


Pokemon::Pokemon(int id, string name, int evolution, double maxHitPoint, double currHitPoint, double attack,
                 double defense):id(id),
      name(name),
      evolution(evolution),
      maxHitPoint(maxHitPoint),
      currHitPoint(currHitPoint),
      attack(attack),
      defense(defense) {
}

Pokemon::Pokemon(const Pokemon &otherPokemon)
    : id(otherPokemon.id),
      name(otherPokemon.name),
      evolution(otherPokemon.evolution),
      maxHitPoint(otherPokemon.maxHitPoint),
      currHitPoint(otherPokemon.currHitPoint),
      attack(otherPokemon.attack),
      defense(otherPokemon.defense) {
}

Pokemon::~Pokemon() {}
int Pokemon::getId() const { return id; }
string Pokemon::getName() const { return name; }
int Pokemon::getEvolution() const { return evolution; }
double Pokemon::getMaxHitPoint() const { return maxHitPoint; }
double Pokemon::getCurrHitPoint() const { return currHitPoint; }
double Pokemon::getAttack() const { return attack; }
double Pokemon::getDefense() const { return defense; }

void Pokemon::displayInfo() {
    cout << "ID: " << id << endl;
    cout << "Nom: " << name << endl;
    cout << "Évolution: " << evolution << endl;
    cout << "HP maximum: " << maxHitPoint << endl;
    cout << "HP actuel: " << currHitPoint << endl;
    cout << "Attaque: " << attack << endl;
    cout << "Défense: " << defense << endl;
    cout << endl;
}

void Pokemon::attacking(Pokemon &target) const {
    double damage = this->attack - target.defense;
    if (damage > 0) {
        target.currHitPoint -= damage;
        if (target.currHitPoint <= 0) {
            cout << target.name << " est decede. !" << endl;
        }
    }
}
string Pokemon::getImagePath() const {
    ostringstream oss;
    oss << "pokemon/" << id;
    if (evolution > 0) {
        oss << "." << setfill('0') << setw(2) << evolution << ".png";
    } else {
        oss << ".png";
    }
    return oss.str();
}
