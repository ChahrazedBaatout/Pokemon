#include "gui/WelcomePage/WelcomePage.hpp"
#include "gui/HomePage/HomePage.hpp"
#include "src/Test.hpp"
#include"include/Pokedex.hpp"
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");

    WelcomePage welcomePage;
    HomePage mainPage;
    Test test;
    test.runTests();
    // Initialiser le Pokedex (lecture CSV)
    Pokedex* dex = Pokedex::getInstance();

    // Afficher tout le contenu du pokedex
    dex->displayAllPokemons();

    // Tester la récupération d'un Pokémon par ID
    Pokemon* clone = dex->getClone(1);
    if (clone) {
        std::cout << "Clone récupéré : " << std::endl;
        clone->displayInfo();
        delete clone; // éviter fuite mémoire
    } else {
        std::cout << "Aucun Pokémon trouvé avec cet ID." << std::endl;
    }


    bool showWelcome = true;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (showWelcome) {
            welcomePage.update();
            window.draw(welcomePage);
            if (welcomePage.isTimeUp()) {
                showWelcome = false;
            }
        } else {
            mainPage.update();
            window.draw(mainPage);
        }

        window.display();
    }
    return 0;
}