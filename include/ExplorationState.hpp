#ifndef EXPLORATION_STATE_HPP
#define EXPLORATION_STATE_HPP

#include "State.hpp"

class Game;

class ExplorationState : public State {
private:
    Game& game;
    sf::Text exploreText;

public:
    ExplorationState(Game& g);
    void handleEvent(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif