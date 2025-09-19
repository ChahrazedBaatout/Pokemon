
#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
class Assets{
public:
    static Assets& instance();
    bool loadFont(const std::string& id, const std::string& path);
    sf::Font* getFont(const std::string& id);
private:
    std::map<std::string, std::unique_ptr<sf::Font>> fonts;
};
