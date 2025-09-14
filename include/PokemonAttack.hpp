#include "PokemonParty.hpp"
#include <vector>

class PokemonAttack : public PokemonParty {
private:
    static const int MAX_SIZE = 6;

public:
    PokemonAttack();
    void addToAttackTeam(const Pokemon& pokemon); // New method to limit to 6
    void createFromParty(PokemonParty& party, const vector<int>& indices);
    void reintegrateToParty(PokemonParty& party);
};