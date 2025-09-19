#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "../src/Engine/IState.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public IState {
private:
    sf::Text title;

public:
    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& target) override;
};

#endif
