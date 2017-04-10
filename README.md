# mineszwiper-cpp
---
C++ console application for SZE-ProgCpp-2017-Aknakereso2P project.

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
List of the required modules and dependencies.
## 1. Compiler
Need to be installed and configured to run the generated '.exe' files after the deployment process.

# Deployment
---
Creating the production ready project: build and compile in IDE.

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
Testing the application: run the application with set to true the CONST_GAME_TESTS_ENABLED in cofig file.

# Licence
---
Copyright (c) 2017 LDworks

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

@[MIT](https://opensource.org/licenses/MIT)
@[info](https://en.wikipedia.org/wiki/MIT_License)