#ifndef GAMEOVERSTATE_HPP
#define GAMEOVERSTATE_HPP

#include "../src/Engine/IState.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class GameOverState : public IState {
private:
    sf::Text text;
    std::string message;

public:
    GameOverState(const std::string& msg) : message(msg) {}

    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
