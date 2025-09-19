cmake_minimum_required(VERSION 3.16)
project(pokemon_selector_sfml)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_SOURCE_DIR}/main.cpp"
)

add_executable(pokemon_selector ${SOURCES}
        main.cpp)

target_include_directories(pokemon_selector PRIVATE include src)

target_link_libraries(pokemon_selector PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
