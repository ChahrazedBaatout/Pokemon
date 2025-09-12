#include "gui/WelcomePage/WelcomePage.hpp"
#include <SFML/Graphics.hpp>
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hello SFML");

    WelcomePage welcomePage;
    bool showWelcome = true;

    sf::Font font;
    font.loadFromFile("../resources/font/arial.ttf");
    sf::Text mainText("Page principale", font, 48);
    mainText.setFillColor(sf::Color::Green);
    mainText.setPosition(180, 250);

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
            window.draw(mainText);
        }

        window.display();
    }
    return 0;
}