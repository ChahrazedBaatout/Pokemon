
#include "Assets.hpp"
#include <iostream>
Assets& Assets::instance(){ static Assets a; return a; }
bool Assets::loadFont(const std::string& id, const std::string& path){
    auto f = std::make_unique<sf::Font>();
    if(!f->loadFromFile(path)){ std::cerr<<"Warn: font not found "<<path<<"\n"; return false; }
    fonts[id] = std::move(f);
    return true;
}
sf::Font* Assets::getFont(const std::string& id){ auto it=fonts.find(id); return it==fonts.end()? nullptr : it->second.get(); }
