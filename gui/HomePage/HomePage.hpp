//
// Created by mahdihadjsassi on 12/09/2025.
//
#include <SFML/Graphics.hpp>

class HomePage : public sf::Drawable {
public:
    HomePage();

    void update();

private:
    sf::Text mainText_;
    sf::Font font_;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
