#ifndef BOOTSTATE_HPP
#define BOOTSTATE_HPP

#include "../src/Engine/IState.hpp"
#include <SFML/Graphics.hpp>

class BootState : public IState {
public:
    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
