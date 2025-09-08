#include "Pokemon.hpp"
#include <iostream>

// Constructeur
Pokemon::Pokemon(int id, std::string name, int evolution, double maxHitPoint, double currHitPoint, double attack, double defense)
    : id(id),
      name(name),
      evolution(evolution),
      maxHitPoint(maxHitPoint),
      currHitPoint(currHitPoint),
      attack(attack),
      defense(defense) {
}

// Constructeur de copie
Pokemon::Pokemon(const Pokemon& other)
    : id(other.id),
      name(other.name),
      evolution(other.evolution),
      maxHitPoint(other.maxHitPoint),
      currHitPoint(other.currHitPoint),
      attack(other.attack),
      defense(other.defense) {
    std::cout << "Constructeur de copie appelé" << std::endl;
    std::cout << std::endl;
}

// Destructeur
Pokemon::~Pokemon() {
    std::cout << "Destructeur appelé: " << name << " détruit" << std::endl;
    std::cout << std::endl;
}

// Getters
int Pokemon::getId() const { return id; }
std::string Pokemon::getName() const { return name; }
int Pokemon::getEvolution() const { return evolution; }
double Pokemon::getMaxHitPoint() const { return maxHitPoint; }
double Pokemon::getCurrHitPoint() const { return currHitPoint; }
double Pokemon::getAttack() const { return attack; }
double Pokemon::getDefense() const { return defense; }
void Pokemon::displayInfo() {
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nom: " << name << std::endl;
    std::cout << "Évolution: " << evolution << std::endl;
    std::cout << "HP maximum: " << maxHitPoint << std::endl;
    std::cout << "HP actuel: " << currHitPoint << std::endl;
    std::cout << "Attaque: " << attack << std::endl;
    std::cout << "Défense: " << defense << std::endl;
    std::cout << std::endl;
}

void Pokemon::launch_attack(Pokemon &attacked) {
    std::cout << name << " a attaqué " << attacked.name << "!" << std::endl;
    if (attack > attacked.defense) {
        double dommage = attack - attacked.defense;
        attacked.currHitPoint -= dommage;
        std::cout << attacked.name << " a perdu " << dommage << " hitpoints!" << std::endl;
        std::cout << std::endl;
        if (attacked.currHitPoint <= 0) {
            attacked.currHitPoint = 0;
            std::cout << attacked.name << " s'est décédé!" << std::endl;
            std::cout << std::endl;
        }
    } else {
        std::cout << "L'attaque de " << name << " n'a été pas assez forte!" << std::endl;
        std::cout << std::endl;
    }
}