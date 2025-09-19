#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include <iostream>


class Pokemon {
private:
    int id;
    std::string name;
    int evolution;
    double maxHitPoint;
    double currHitPoint;
    double attack;
    double defense;

public:
    Pokemon() : id(0), name(""), evolution(0), maxHitPoint(0), currHitPoint(0), attack(0), defense(0) {}

    Pokemon(int id, std::string name, int evolution, double maxHP, double currHP, double atk, double def);

    Pokemon(const Pokemon &other);

    ~Pokemon() = default;

    void attacking(Pokemon &target) const;

    void displayInfo() const;

    int getId() const { return id; }
    std::string getName() const { return name; }
    int getEvolution() const { return evolution; }
    double getMaxHitPoint() const { return maxHitPoint; }
    double getCurrHitPoint() const { return currHitPoint; }
    double getAttack() const { return attack; }
    double getDefense() const { return defense; }

    void setName(const std::string &n) { name = n; }
    void setEvolution(int evo) { evolution = evo; }
    void setMaxHitPoint(double maxhp) { maxHitPoint = maxhp; }
    void setCurrHitPoint(double currhp) { currHitPoint = currhp; }
    void setAttack(double atk) { attack = atk; }
    void setDefense(double def) { defense = def; }

    std::string toString() const;
};

#endif
