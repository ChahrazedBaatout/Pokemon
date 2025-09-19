#include "AttackTeamState.hpp"
#include "BattleState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"
#include <sstream>
#include <iostream>

void AttackTeamState::onEnter(Game& g) {
    auto font = Assets::instance().getFont("ui");
    if (font) {
        header.setFont(*font);
        header.setString("Votre equipe pour le combat (Appuyez sur ENTER pour commencer)");
        header.setCharacterSize(22);
        header.setPosition(20, 20);
    }

    auto& attackTeam = g.getAttackTeam().getPokemons();
    int y = 80;
    texts.clear();

    for (auto& p : attackTeam) {
        sf::Text t;
        if (font) t.setFont(*font);
        t.setCharacterSize(18);
        std::ostringstream oss;
        oss << p.getName() << " (HP: " << p.getMaxHitPoint()
            << ", ATK: " << p.getAttack()
            << ", DEF: " << p.getDefense() << ")";
        t.setString(oss.str());
        t.setPosition(40, y);
        y += 30;
        texts.push_back(t);
    }
}

void AttackTeamState::onExit(Game& g) {}

void AttackTeamState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed) {
        if (e.key.code == sf::Keyboard::Enter) {
            auto& attackTeam = g.getAttackTeam().getPokemons();

            if (attackTeam.empty()) {
                std::cerr << "Aucun Pokemon sélectionne !" << std::endl;
                return;
            }

            // Passer toute l'équipe au BattleState
            g.getStates().replace(std::make_unique<BattleState>(attackTeam), g);
        }
    }
}

void AttackTeamState::update(Game& g, float dt) {}

void AttackTeamState::draw(Game& g, sf::RenderTarget& target) {
    target.draw(header);
    for (auto& t : texts) {
        target.draw(t);
    }
}
