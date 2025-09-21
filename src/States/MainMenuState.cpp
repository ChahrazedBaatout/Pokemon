#include "MainMenuState.hpp"
#include "PartySelectState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"

void MainMenuState::onEnter(Game& g) {
    // Charger la police s'il n'est pas déjà chargé
    if (!Assets::instance().getFont("ui")) {
        Assets::instance().loadFont("ui", "arial.ttf");
    }

    auto f = Assets::instance().getFont("ui");
    if (f) {
        title.setFont(*f);
        title.setString("Pokemon Selector");
        title.setCharacterSize(50);
        title.setFillColor(sf::Color::Yellow);

        // centrer le titre
        sf::FloatRect bounds = title.getLocalBounds();
        title.setOrigin(bounds.width / 2, bounds.height / 2);
        title.setPosition(g.getWindow().getSize().x / 2, g.getWindow().getSize().y / 2 - 50);

        subtitle.setFont(*f);
        subtitle.setString("Appuyez sur ENTREE pour commencer");
        subtitle.setCharacterSize(25);
        subtitle.setFillColor(sf::Color::White);

        // centrer le sous-titre
        sf::FloatRect sbounds = subtitle.getLocalBounds();
        subtitle.setOrigin(sbounds.width / 2, sbounds.height / 2);
        subtitle.setPosition(g.getWindow().getSize().x / 2, g.getWindow().getSize().y / 2 + 50);
    }

    background.setSize(sf::Vector2f(
        g.getWindow().getSize().x,
        g.getWindow().getSize().y
    ));
    background.setFillColor(sf::Color(30, 30, 80)); // bleu foncé
}

void MainMenuState::onExit(Game&) {}

void MainMenuState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Enter) {
        g.getStates().replace(std::make_unique<PartySelectState>(), g);
    }
}

void MainMenuState::update(Game&, float) {}

void MainMenuState::draw(Game&, sf::RenderTarget& t) {
    // dessiner le fond puis les textes
    t.draw(background);
    t.draw(title);
    t.draw(subtitle);
}
