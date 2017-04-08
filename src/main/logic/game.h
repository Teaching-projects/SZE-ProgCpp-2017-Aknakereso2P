/**
 * Shows the game title.
 */
static void showTitle()
{
    for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
    print("#");
    println();
    std::cout << "          " << CONST_GAME_NAME;
    println();
    for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
    print("#");
}

/**
 * Shows the game menu.
 */
static void showMenu()
{
    println("1. New game");
    println("2. Exit");
}

