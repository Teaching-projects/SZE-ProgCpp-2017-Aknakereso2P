/**
 * Start.
 */
void startNewGame()
{
    clearScreen();
    printlnInfo("Game starting...");
    pauseScreen();
}

/**
 * End.
 */
void endGame()
{
    clearScreen();
    printlnInfo("Game ending...");
    pauseScreen();
}

/**
 * Exit.
 */
void exitGame()
{
    clearScreen();
    printlnInfo("Game exiting...");
    pauseScreen();
}

/**
 * Select menu item from user at the start screen.
 */
void selectMenuItem()
{
    printlnInfo("Please select a menu item, than press enter");
    print("CIN: ");

    int selectedMenuItem;
    std::cin >> selectedMenuItem;
    std::cin.clear();
    std::cin.ignore(512, '\n');
    switch(selectedMenuItem)
    {
        case 1:
            startNewGame();
            break;
        case 2:
            exitGame();
            break;
        default:
            printlnWarn("Wrong menu selected");
            selectMenuItem();
            break;
    }
}

/**
 * Shows the game title.
 */
void showTitle()
{
    for(int i=0; i<CONST_GAME_HEADER_WIDTH; i++)
    print("#");
    println();
    std::cout << "          " << CONST_GAME_NAME;
    println();
    for(int i=0; i<CONST_GAME_HEADER_WIDTH; i++)
    print("#");
}

/**
 * Shows the game menu.
 */
void showMenu()
{
    println("1. New game");
    println("2. Exit");
}

/**
 * Shows the start screen.
 */
void showStartScreen()
{
    showTitle();
    println();
    println();
    showMenu();
    println();
    println();
    selectMenuItem();
}
