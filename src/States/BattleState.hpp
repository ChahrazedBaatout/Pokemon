#ifndef BATTLESTATE_HPP
#define BATTLESTATE_HPP

#include "../Engine/IState.hpp"
#include "../include/Pokemon.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class BattleState : public IState {
private:
    std::vector<Pokemon> playerTeam;
    std::vector<Pokemon> enemyTeam;

    int currentPlayerIndex = 0;
    int currentEnemyIndex = 0;

    sf::Text title;
    sf::Text logText;

    int turn = 0;
    enum class BattleResult { None, PlayerWin, EnemyWin };
    BattleResult result = BattleResult::None;

    void doTurn(Game& g);

    Pokemon& getCurrentPlayer();
    Pokemon& getCurrentEnemy();
    bool isTeamAlive(const std::vector<Pokemon>& team);

public:
    BattleState(const std::vector<Pokemon>& team);

    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
