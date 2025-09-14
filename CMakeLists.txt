cmake_minimum_required(VERSION 4.0)
project(demoTP1)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(demoTP1 main.cpp
        include/Pokemon.hpp
        include/PokemonVector.hpp
        src/Pokemon.cpp
        src/PokemonVector.cpp
        src/Pokedex.cpp
        include/Pokedex.hpp
        src/PokemonParty.cpp
        include/PokemonParty.hpp
        src/PokemonAttack.cpp
        include/PokemonAttack.hpp
        gui/WelcomePage/WelcomePage.cpp
        gui/WelcomePage/WelcomePage.hpp
        gui/HomePage/HomePage.cpp
        gui/HomePage/HomePage.hpp
        gui/BasePage.hpp
        gui/BasePage.cpp)

target_link_libraries(demoTP1
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)