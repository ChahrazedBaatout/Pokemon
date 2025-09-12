#include<iostream>
#include <string>
using namespace  std;

class Pokemon {
private:
    int id;
    string name;
    int evolution;
    double maxHitPoint;
    double currHitPoint;
    double attack;
    double defense;

public:
    Pokemon(int id, string name, int evolution, double maxHitPoint, double currHitPoint, double attack, double defense);
    Pokemon(const Pokemon& other);
    ~Pokemon();
    void attacking(Pokemon& target) const;
    void displayInfo();
    int getId() const;
    string getName() const;
    int getEvolution() const;
    double getMaxHitPoint() const;
    double getCurrHitPoint() const;
    double getAttack() const;
    double getDefense() const;
    void setName(const string& n);
    void setEvolution(int evo);
    void setMaxHitPoint(double maxhp);
    void setCurrHitPoint(double currhp);
    void setAttack(double atk);
    void setDefense(double def);
};

