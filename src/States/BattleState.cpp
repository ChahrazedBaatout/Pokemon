#include "BattleState.hpp"
#include "PauseState.hpp"
#include "GameOverState.hpp"
#include "../Engine/Game.hpp"
#include "../Engine/Assets.hpp"
#include <sstream>
#include <algorithm>
#include <iostream>

BattleState::BattleState(const std::vector<Pokemon>& team) {
    playerTeam = team;
    if (playerTeam.empty()) {
        playerTeam.push_back(Pokemon(25, "Pikachu", 0, 100, 100, 55, 40));
    }

    // Ennemi = 6 Mewtwo pour tester
    for (int i = 0; i < 6; i++) {
        enemyTeam.push_back(Pokemon(150, "Mewtwo", 0, 120, 120, 110, 90));
    }
}

void BattleState::onEnter(Game& g) {
    auto f = Assets::instance().getFont("ui");
    if (f) {
        title.setFont(*f);
        logText.setFont(*f);
    }
    title.setCharacterSize(22);
    title.setString("Battle — [Espace]: tour suivant, [Esc]: Pause");
    title.setPosition(20, 20);

    logText.setCharacterSize(18);
    logText.setPosition(20, 60);
    logText.setString("Votre equipe affronte l equipe ennemie !");
}

void BattleState::onExit(Game&) {}

Pokemon& BattleState::getCurrentPlayer() {
    return playerTeam[currentPlayerIndex];
}

Pokemon& BattleState::getCurrentEnemy() {
    return enemyTeam[currentEnemyIndex];
}

bool BattleState::isTeamAlive(const std::vector<Pokemon>& team) {
    for (const auto& p : team) {
        if (p.getCurrHitPoint() > 0) return true;
    }
    return false;
}

void BattleState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Escape) {
            g.getStates().push(std::make_unique<PauseState>(), g);
        }
        if (e.key.code == sf::Keyboard::Space && result == BattleResult::None) {
            doTurn(g);
        }
    }
}

void BattleState::doTurn(Game& g) {
    turn++;
    std::ostringstream oss;
    oss << "=== Tour " << turn << " ===\n";

    Pokemon& player = getCurrentPlayer();
    Pokemon& enemy = getCurrentEnemy();

    int dmg = std::max(1, (int)(player.getAttack() - enemy.getDefense() / 2.0));
    enemy.setCurrHitPoint(enemy.getCurrHitPoint() - dmg);
    oss << player.getName() << " inflige " << dmg << " à " << enemy.getName()
        << " (HP: " << std::max(0.0, enemy.getCurrHitPoint()) << ")\n";

    if (enemy.getCurrHitPoint() <= 0) {
        oss << enemy.getName() << " est K.O. !\n";
        currentEnemyIndex++;
        if (currentEnemyIndex >= (int)enemyTeam.size() || !isTeamAlive(enemyTeam)) {
            result = BattleResult::PlayerWin;
            oss << "🎉 Victoire de votre equipe !";
            logText.setString(oss.str());
            g.getStates().replace(std::make_unique<GameOverState>("Victoire !"), g);
            return;
        }
    }

    int dmg2 = std::max(1, (int)(enemy.getAttack() - player.getDefense() / 2.0));
    player.setCurrHitPoint(player.getCurrHitPoint() - dmg2);
    oss << enemy.getName() << " inflige " << dmg2 << " à " << player.getName()
        << " (HP: " << std::max(0.0, player.getCurrHitPoint()) << ")\n";

    if (player.getCurrHitPoint() <= 0) {
        oss << player.getName() << " est K.O. !\n";
        currentPlayerIndex++;
        if (currentPlayerIndex >= (int)playerTeam.size() || !isTeamAlive(playerTeam)) {
            result = BattleResult::EnemyWin;
            oss << "💀 Defaite...";
            logText.setString(oss.str());
            g.getStates().replace(std::make_unique<GameOverState>("Defaite..."), g);
            return;
        }
    }

    logText.setString(oss.str());
}

void BattleState::update(Game&, float) {}

void BattleState::draw(Game&, sf::RenderTarget& target) {
    target.draw(title);
    target.draw(logText);
}
