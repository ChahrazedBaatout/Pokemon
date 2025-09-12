#include "../include/Pokemon.hpp"
#include <iostream>
#include <string>
using namespace  std;


Pokemon::Pokemon(int id, string name, int evolution, double maxHitPoint, double currHitPoint, double attack, double defense)
    : id(id),
      name(name),
      evolution(evolution),
      maxHitPoint(maxHitPoint),
      currHitPoint(currHitPoint),
      attack(attack),
      defense(defense) {
}

Pokemon::Pokemon(const Pokemon& other)
    : id(other.id),
      name(other.name),
      evolution(other.evolution),
      maxHitPoint(other.maxHitPoint),
      currHitPoint(other.currHitPoint),
      attack(other.attack),
      defense(other.defense) {
    cout << "Constructeur de copie appelé" << endl;
    cout << endl;
}

Pokemon::~Pokemon() {
    cout << "Destructeur appelé: " << name << " détruit" << endl;
    cout << endl;
}

// Getters
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

void Pokemon::attacking(Pokemon& target) const{
    double damage = this->attack - target.defense ;
    if (damage < 0) damage = 0;

    target.currHitPoint -= damage;
    if (target.currHitPoint < 0) target.currHitPoint= 0;

    cout << this->name << " attaque " << target.name <<endl;


    if (target.currHitPoint== 0) {
        cout << target.name << " est decede. !" << endl;
    }
}