#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

class Game;

class State {
public:
    virtual ~State() = default;
    virtual void handleEvent(sf::Event& event) = 0;
    virtual void update() = 0;
    virtual void draw(sf::RenderWindow& window) = 0;
};

#endif