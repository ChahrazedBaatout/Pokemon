#include "PartySelectState.hpp"
#include "../Engine/Assets.hpp"
#include "../Engine/Game.hpp"
#include "BattleState.hpp"

#include <filesystem>
#include <iostream>
#include <sstream>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;

static constexpr int COLS = 8;
static constexpr int CELL_W = 100;
static constexpr int CELL_H = 100;
static constexpr int GRID_X = 50;
static constexpr int GRID_Y = 100;

bool PartySelectState::loadPokemonTexture(int id, sf::Texture& outTex) const {
    const std::string base = "pokemon/" + std::to_string(id);
    const std::string variants[3] = { base + ".png", base + ".01.png", base + ".02.png" };

    for (const auto& f : variants) {
        if (outTex.loadFromFile(f)) return true;
    }
    return false;
}

// -----------------------------------------------------------

PartySelectState::PartySelectState() {
    if (!Assets::instance().getFont("ui")) {
        Assets::instance().loadFont("ui", "arial.ttf");
    }
    auto f = Assets::instance().getFont("ui");
    if (f) {
        header.setFont(*f);
        header.setCharacterSize(22);
        header.setFillColor(sf::Color::White);
        header.setPosition(20, 20);
        header.setString("Choisissez 6 Pokemons (clic) puis cliquez sur START");

        counterText.setFont(*f);
        counterText.setCharacterSize(20);
        counterText.setFillColor(sf::Color(255, 255, 100));
        counterText.setPosition(20, 50);

        infoText.setFont(*f);
        infoText.setCharacterSize(18);
        infoText.setFillColor(sf::Color::White);

        startText.setFont(*f);
        startText.setString("START");
        startText.setCharacterSize(24);
        startText.setFillColor(sf::Color::Black);
    }

    infoPanel.setSize({260.f, 130.f});
    infoPanel.setFillColor(sf::Color(0,0,0,180));
    infoPanel.setOutlineColor(sf::Color::White);
    infoPanel.setOutlineThickness(2);

    startButton.setSize({140.f, 56.f});
    startButton.setFillColor(sf::Color(100, 210, 120));
    startButton.setOutlineColor(sf::Color::White);
    startButton.setOutlineThickness(2);
}

// -----------------------------------------------------------

void PartySelectState::onEnter(Game& g) {


    auto* pokedex = Pokedex::getInstance();
    auto& pokemons = pokedex->getPokemons();

    pokemonSprites.clear();
    selected.clear();
    textures.clear();
    textures.reserve(pokemons.size());

    int x = GRID_X;
    int y = GRID_Y;
    int col = 0;

    for (const auto& p : pokemons) {
        auto tex = std::make_unique<sf::Texture>();

        if (!loadPokemonTexture(p.getId(), *tex)) {
            cerr << "Image introuvable pour ID=" << p.getId()
                 << " (" << p.getName() << ") [ .png/.01.png/.02.png ]" << endl;
            continue;
        }

        sf::Sprite spr;
        spr.setTexture(*tex);
        spr.setScale(0.7f, 0.7f);
        spr.setPosition((float)x + 10.f, (float)y + 10.f);

        // Case (cadre) cliquable
        sf::RectangleShape box({80.f, 80.f});
        box.setPosition((float)x, (float)y);
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineColor(sf::Color::White);
        box.setOutlineThickness(2.f);
        pokemonSprites.push_back(PokemonSprite{ p, spr, box });
        textures.push_back(std::move(tex));

        // Avance grille
        x += CELL_W;
        if (++col >= COLS) {
            col = 0;
            x = GRID_X;
            y += CELL_H;
        }
    }

    infoPanel.setPosition( (float)(GRID_X + COLS*CELL_W + 20), 100.f );
    infoText.setPosition(infoPanel.getPosition().x + 10.f, infoPanel.getPosition().y + 10.f);

    startButton.setPosition(infoPanel.getPosition().x + 30.f, infoPanel.getPosition().y + 170.f);
    startText.setPosition(startButton.getPosition().x + 28.f, startButton.getPosition().y + 12.f);

    // Log de cwd (utile si images blanches persistent)
    cout << "Working dir: " << std::filesystem::current_path() << endl;
}

// -----------------------------------------------------------

void PartySelectState::onExit(Game& g) {
    pokemonSprites.clear();
    textures.clear();
    selected.clear();
    currentPokemon = nullptr;
}

// -----------------------------------------------------------

void PartySelectState::handleEvent(Game& g, const sf::Event& e) {
    if (e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mouse( (float)e.mouseButton.x, (float)e.mouseButton.y );

        if (selected.size() == 6 && startButton.getGlobalBounds().contains(mouse)) {
            g.getStates().replace(std::make_unique<BattleState>(selected), g);
            return;
        }
        for (auto& ps : pokemonSprites) {
            if (ps.box.getGlobalBounds().contains(mouse)) {
                currentPokemon = &ps.pokemon;

                // Toggle sélection
                auto it = std::find_if(selected.begin(), selected.end(),
                                       [&](const Pokemon& pk){ return pk.getId() == ps.pokemon.getId(); });
                if (it != selected.end()) {
                    selected.erase(it); // désélection
                } else {
                    if (selected.size() < 6) selected.push_back(ps.pokemon);
                }
                break;
            }
        }
    }
}

// -----------------------------------------------------------

void PartySelectState::update(Game& g, float) {
    // Compteur X/6
    std::ostringstream oss;
    oss << "Pokémon choisis : " << selected.size() << "/6";
    counterText.setString(oss.str());

    // Panneau d'info
    if (currentPokemon) {
        std::ostringstream inf;
        inf << currentPokemon->getName() << "\n"
            << "ATK: " << currentPokemon->getAttack() << "\n"
            << "DEF: " << currentPokemon->getDefense() << "\n"
            << "HP:  " << currentPokemon->getMaxHitPoint();
        infoText.setString(inf.str());
    } else {
        infoText.setString("Cliquez un Pokémon\npour voir les infos.");
    }
}

// -----------------------------------------------------------

void PartySelectState::draw(Game& g, sf::RenderTarget& target) {
    target.draw(header);
    target.draw(counterText);

    // Grille
    for (auto& ps : pokemonSprites) {
        const bool chosen = std::any_of(selected.begin(), selected.end(),
                            [&](const Pokemon& pk){ return pk.getId() == ps.pokemon.getId(); });
        ps.box.setOutlineColor(chosen ? sf::Color(0,200,120) : sf::Color::White);

        target.draw(ps.box);
        target.draw(ps.sprite);
    }

    target.draw(infoPanel);
    target.draw(infoText);
    if (selected.size() == 6) {
        target.draw(startButton);
        target.draw(startText);
    }
}
