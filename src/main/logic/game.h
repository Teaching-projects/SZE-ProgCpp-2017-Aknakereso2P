bool endgame = false;

/**
 * Sleep thread until given milliseconds.
 *
 * @param ms the milliseconds
 */
void sleep(unsigned ms)
{
    Sleep(ms);
}

/**
 * Sleep thread until given seconds.
 *
 * @param s the seconds
 */
void sleepSecs(int s)
{
    sleep(s * 1000);
}

/**
 * End.
 */
void endGame(Player winner)
{
    clearScreen();
    printlnInfo("Game ended");
    printInfo("The winner is: ");
    print(winner.getNickName());
    pauseScreen();
    endgame = true;
}

/**
 * Start.
 */
void startNewGame()
{
    int x, y, turn;
    char col;
    std::string playerOneNickName, playerTwoNickName;

    clearScreen();
    printlnDebug("New game starting...");

    printlnDebug("Initializing players...");
    print("[CIN] Player 1 nickname: ");
    std::cin >> playerOneNickName;

    print("[CIN] Player 2 nickname: ");
    std::cin >> playerTwoNickName;

    printDebug("Initializing minefield");
    Minefield mineField = Minefield();
    pauseScreen();
    Player p1 = Player(playerOneNickName);
    Player p2 = Player(playerOneNickName);
    turn = 1;

    while(!endgame)
    {
        clearScreen();
        printInfo("Turn ");
        println(convertNumberToString(turn++));

        mineField.show();

        println();
        print("CIN [ROW]: ");
        std::cin >> x;
        print("CIN [COLUMN]: ");
        std::cin >> col;

        for(int i=0; i<CONST_MINEFIELD_COLUMNS; i++)
        {
            if(col == CONST_MINEFIELD_HEADER[i])
            {
                y = i;
                break;
            }
        }
        mineField.updateMinefield(x-1,y);
    }

    endGame(p1);
}

/**
 * Exit.
 */
void exitGame()
{
    clearScreen();
    printlnInfo("Game exiting...");
    endgame = true;
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
    clearScreen();
    showTitle();
    println();
    println();
    showMenu();
    println();
    println();
    selectMenuItem();
}
