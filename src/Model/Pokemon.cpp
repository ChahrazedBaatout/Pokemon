#include "Pokemon.hpp"
#include <iostream>

Pokemon::Pokemon(int id, std::string name, int evolution, double maxHP, double currHP, double atk, double def)
    : id(id), name(name), evolution(evolution), maxHitPoint(maxHP), currHitPoint(currHP), attack(atk), defense(def) {}

Pokemon::Pokemon(const Pokemon &other)
    : id(other.id), name(other.name), evolution(other.evolution),
      maxHitPoint(other.maxHitPoint), currHitPoint(other.currHitPoint),
      attack(other.attack), defense(other.defense) {}

void Pokemon::attacking(Pokemon &target) const {
    double damage = attack - (target.getDefense() * 0.3);
    if (damage < 1) damage = 1;
    target.setCurrHitPoint(std::max(0.0, target.getCurrHitPoint() - damage));
}

void Pokemon::displayInfo() const {
    std::cout << "ID: " << id << "\nNom: " << name << "\nÉvolution: " << evolution
              << "\nHP maximum: " << maxHitPoint << "\nHP actuel: " << currHitPoint
              << "\nAttaque: " << attack << "\nDéfense: " << defense << "\n\n";
}

std::string Pokemon::toString() const {
    return name + " (HP: " + std::to_string((int)currHitPoint) +
           ", ATK: " + std::to_string((int)attack) +
           ", DEF: " + std::to_string((int)defense) + ")";
}
