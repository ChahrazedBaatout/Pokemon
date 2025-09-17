// gui/HomePage/HomePage.hpp
#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include "../BasePage.hpp"
#include <SFML/Graphics.hpp>
#include "../include/PokemonParty.hpp" // Assuming PokemonParty is defined here

class HomePage : public BasePage {
public:
    HomePage(PokemonParty& partyRef, PokemonParty& attackRef, sf::RenderWindow& windowRef);
    void update() override;
    bool shouldHideText() const; // Check if text should be hidden
    void handleInput(); // Handle mouse input for selection
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

private:
    sf::Clock clock_;
    const float HIDE_TEXT_DURATION = 2.0f; // Hide text after 5 seconds
    PokemonParty& party;
    PokemonParty& attack;
    sf::RenderWindow& window;
    std::map<int, sf::Texture> textures; // Cache for textures
    sf::Texture& loadTexture(int id);    // Load texture with caching
};

#endif