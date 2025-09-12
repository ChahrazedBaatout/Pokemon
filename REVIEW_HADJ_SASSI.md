# Code Review by HADJ SASSI Mahdi

## Overview
The first sight of the project shows a directory called include, and the c++ files, with the csv file.

I really appreciate the README.md file, that is in the source folder, so we can read the documentation.

### Comments
- You're missing .gitignore to avoid pushing unnecessary files like .vscode or cmake-build-debug.
- It would be better to fill the README.md file with more details about the project, at least the name of the project.
- The folder include the cpp and hpp files plus the csv file.
  - I would recommend to change the name of the folder to src or to another name different of include. Because
  include seems like it's a library folder.
  - The csv file is redundant in the include also in the parent folder. I recommend to put the csv folder in a specific folder
  named for example data or resources.
  - It's fine to have an approach that the hpp file are with their cpp file. But I would rather put the cpp file together
  and the hpp files together. or to put a folder named entity that contains folders with the names of the classes, in each 
  entity folder, put the hpp and cpp files of the class.
- I recommend to follow the clean code principles like :
  - remove all magic numbers
  - extract strings and values in enumerations
  - keep only the comments fot the specific and complex part of the code.

## Intervention
### Code Structure
- First of all before i start reading the code, I always refactor the code with jetbrains shortcut (ctrl+alt+L) to make the code more readable.
- I Add some comments to the code, when I have a remark or a suggestion in the code.

### Code Review
- In the PokemonVector class:
  - I really liked the structure of the class, and the way you used the vector to store the pokemons.
  - Everything is readable, and comprehensible.
- In the Pokedex class:
  - I really liked how you analysed the csv file, and extracted each column correspondant to your constructor.
  - You've overrided the displayAllPokemons from the PokemonVector, but only in the cpp file not in the description hpp.
- In the PokemonAttack class:
  - I really liked how you inherited form the PokemonParty not just from the PokemonVector which itself inherits from the PokemonVector.
  - This shows that you understood more the concept of the game.
  - And you see that the PokemonAttack is a reduced version of the PokemonParty.
  - Good job.

### Added Code:
Since you didn't started yet the graphical part, I'll make a first window that will welcome us to the game.

Also i 've done : 

- An abstract class named BasePage that contains the necessary to make gui page
- Welcome Page inherits BasePage that shows a welcome message for 1 seconds.
- Home Page inherits BasePage that shows a text to modify after

Also added a Arial font in resources folder.

I recommend to put the pokedex.csv in this folder resources.