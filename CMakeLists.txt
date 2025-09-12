cmake_minimum_required(VERSION 4.0)
project(demoTP1)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
add_executable(demoTP1 main.cpp
        include/Pokemon.hpp
        include/PokemonVector.hpp
        include/Pokemon.cpp
        include/PokemonVector.cpp
        include/Pokedex.cpp
        include/Pokedex.hpp
        include/PokemonParty.cpp
        include/PokemonParty.hpp
        include/PokemonAttack.cpp
        include/PokemonAttack.hpp
        gui/WelcomePage/WelcomePage.cpp
        gui/WelcomePage/WelcomePage.hpp)

target_link_libraries(demoTP1
        sfml-graphics
        sfml-window
        sfml-system
        sfml-audio
)