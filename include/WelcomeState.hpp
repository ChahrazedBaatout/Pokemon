#ifndef WELCOME_STATE_HPP
#define WELCOME_STATE_HPP

#include "State.hpp"
#include <SFML/Graphics.hpp>

class WelcomeState : public GameState {
private:
    Game& game;
    sf::Text text;
    sf::Font font;

public:
    WelcomeState(Game& g);
    void handleEvent(sf::Event& event) override;
    void update() override;
    void draw(sf::RenderWindow& window) override;
};

#endif