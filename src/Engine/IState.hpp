#ifndef ISTATE_HPP
#define ISTATE_HPP

#include <SFML/Graphics.hpp>

class Game;

class IState {
public:
    virtual ~IState() = default;

    virtual void onEnter(Game& g) = 0;
    virtual void onExit(Game& g) = 0;
    virtual void handleEvent(Game& g, const sf::Event& e) = 0;
    virtual void update(Game& g, float dt) = 0;
    virtual void draw(Game& g, sf::RenderTarget& target) = 0;
};

#endif
