//
// Created by mahdihadjsassi on 12/09/2025.
//

#include <SFML/Graphics.hpp>

class WelcomePage : public sf::Drawable {
public:
    WelcomePage();
    bool isTimeUp() const;
    void update();
private:
    sf::Text text_;
    sf::Font font_;
    sf::Clock clock_;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};