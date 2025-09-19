#ifndef ATTACKTEAMSTATE_HPP
#define ATTACKTEAMSTATE_HPP

#include "../Engine/IState.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class AttackTeamState : public IState {
private:
    sf::Text header;
    std::vector<sf::Text> texts;

public:
    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
