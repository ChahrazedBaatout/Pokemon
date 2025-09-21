#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "../Engine/IState.hpp"
#include <SFML/Graphics.hpp>

class MainMenuState : public IState {
private:
    sf::Text title;
    sf::Text subtitle;
    sf::RectangleShape background; // ajout pour fond coloré

public:
    void onEnter(Game& g) override;
    void onExit(Game& g) override;
    void handleEvent(Game& g, const sf::Event& e) override;
    void update(Game& g, float dt) override;
    void draw(Game& g, sf::RenderTarget& t) override;
};

#endif
