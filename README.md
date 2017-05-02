# mineszwiper-cpp
---
C++ console application for SZE-ProgCpp-2017-Aknakereso2P project

# Prerequisites
---
* [Git](http://git-scm.com/downloads) - version control
* [Compiler](https://gcc.gnu.org/install/download.html) - GNU GCC Compiler for C++
* [CodeBlocks](http://www.codeblocks.org/downloads/26) - recommended IDE

# Importing the project
---
1. Check-out the master branch
    > git checkout origin master
2. Import the checked-out folder structure into your IDE as a general project

# Dependencies
---
List of the required modules and dependencies
## 1. Compiler
Need to be installed and configured to run the generated '.exe' files after the deployment process

# Deployment
---
Creating the production ready project: build and compile in IDE

* **obj** folder: is the place of the generated resources
* **bin** folder: is the place of the generated executables

# Play the game
The recommended console size is:
	WIDTH:	106
	HEIGHT:	 35
First you have to select the 'New game' menu than giving 2 player name, and after that you can play the Mineszwiper game.
First input is the row (1-16), second input is the column (A-P). In case of invalid input, must happen nothing. 
Only the valid inputs refreshes the minefield. The winner will be the firs player who collect the first 26 mine on the field.

# Tests
---
Testing the application: run the application with set to true the CONST_GAME_TESTS_ENABLED in cofig file