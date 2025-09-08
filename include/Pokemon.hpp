#include<iostream>
#include <string>

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
    Pokemon(int id, std::string name, int evolution, double maxHitPoint, double currHitPoint, double attack, double defense);
    Pokemon(const Pokemon& other);
    ~Pokemon();
    void launch_attack(Pokemon& attacked);
    void displayInfo();
    int getId() const;
    std::string getName() const;
    int getEvolution() const;
    double getMaxHitPoint() const;
    double getCurrHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    void setName(const std::string& n);
    void setEvolution(int evo);
    void setMaxHitPoint(double maxhp);
    void setCurrHitPoint(double currhp);
    void setAttack(double atk);
    void setDefense(double def);
};

