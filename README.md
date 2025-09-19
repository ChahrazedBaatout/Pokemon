# Introduction à la Programmation Orientée Objet en C++

## 3ème année IS

*Document de travail*

---

# TP 1 : Pokemon Selector

Ce projet, réalisé dans le cadre du cours de l'introdiction au c++, vise à développer un sélecteur de Pokémons en C++ en utilisant le framework SFML pour une interface graphique, des principes de programmation orientée objet (héritage, polymorphisme, singleton), et le design pattern State pour gérer les états du jeu. Le code est organisé en dossiers `include/` (headers), `src/` (implémentations), et `resources/` (fichiers CSV et images), avec un fichier `CMakeLists.txt` pour la compilation.

## 1.1 Mise en place du Framework SFML

### Installation et Configuration
Pour installer SFML sur un système Linux (testé sous Ubuntu/Debian) :
```bash
$ sudo apt-get install libsfml-dev

