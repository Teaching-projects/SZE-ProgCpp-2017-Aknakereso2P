/**
 * The Class MineszwiperGame.
 */
class MineszwiperGame
{
    private:
        bool endCurrentGame;
        bool exitGame;

    public:
        MineszwiperGame();
        void showStartScreen(void);
        void showExitScreen(void);
        bool isEndCurrentGame(void);
        void setEndCurrentGame(bool);
        bool isEnd(void);
        void setEnd(bool);

    private:
        void showTitle(void);
        void showTitle(std::string subTitle);
        void showMenu(void);
        void showSelectMenu(void);
        void startNewGame(void);
        bool checkNickName(std::string nickName);
        bool checkRow(int row);
        int correctRow(int row);
        bool checkColumn(int column);
        int correctColumn(int column);
};

/**
 * Instantiates a new Mineszwiper game.
 */
MineszwiperGame::MineszwiperGame(void)
{
    endCurrentGame = false;
    exitGame = false;
}

/**
 * Shows the start screen.
 */
void MineszwiperGame::showStartScreen(void)
{
    core_clearScr();
    showTitle();
    showMenu();
    showSelectMenu();
}

/**
 * Exiting console screen.
 */
void MineszwiperGame::showExitScreen(void)
{
    core_clearScr();
    showTitle();
    println();
    println("Program exiting...");
    println("Good bye!");
    core_sleepSecs(2);
}

/**
 * Checks if the current game is ended.
 *
 * @return true, if the current game is ended
 */
bool MineszwiperGame::isEndCurrentGame(void)
{
    return endCurrentGame;
}

/**
 * Sets the current game is ended.
 *
 * @param eg the new current end game
 */
void MineszwiperGame::setEndCurrentGame(bool ecg)
{
    endCurrentGame = ecg;
}

/**
 * Checks if the game is ended.
 *
 * @return true, if the game is ended
 */
bool MineszwiperGame::isEnd()
{
    return exitGame;
}

/**
 * Sets the game is ended.
 *
 * @param eg the new end game
 */
void MineszwiperGame::setEnd(bool eg)
{
    exitGame = eg;
}

/**
 * Shows the game title.
 */
void MineszwiperGame::showTitle()
{
    for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
    print(CONST_HEADER_H);
    println();
    for(int i=0; i<CONF_GAME_HEADER_WIDTH_OFFSET; i++)
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    println(CONST_GAME_NAME);
    for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
    print(CONST_HEADER_H);
    println();
}

/**
 * Shows the game menu.
 */
void MineszwiperGame::showMenu()
{
    println();
    println("1. New game");
    println("2. Exit");
    println();
}

/**
 * Select menu item from user at the start screen.
 */
void MineszwiperGame::showSelectMenu()
{
    print("Please select a menu: ");
    int selectedMenuItem;
    std::cin >> selectedMenuItem;
    std::cin.clear();
    std::cin.ignore(sizeof(int), '\n');
    switch(selectedMenuItem)
    {
        case 1:
            startNewGame();
            break;
        case 2:
            setEnd(true);
            break;
        default:
            println("Wrong menu selected!");
            showSelectMenu();
            break;
    }
}

/**
 * Starts a new game.
 */
void MineszwiperGame::startNewGame()
{
    setEndCurrentGame(false);
    setEnd(false);
    core_clearScr();
    showTitle();
    println("Starting new game with players...");
    println();

    // getting player one nickname
    std::string n1 ("");
    do
    {
        print("Player one nickname: ");
        std::cin >> n1;
        std::cin.clear();
        std::cin.ignore(sizeof(std::string), '\n');
    }
    while(!checkNickName(n1));
    Player p1;
    p1.setNickName(n1);
    // player one starts the game
    p1.setHasTurn(true);

    // getting player two nickname
    std::string n2 ("");
    do
    {
        print("Player two nickname: ");
        std::cin >> n2;
        std::cin.clear();
        std::cin.ignore(sizeof(std::string), '\n');
    }
    while(!checkNickName(n2));
    Player p2;
    p2.setNickName(n2);

    println();
    println("Game starting");
    // minefield
    Minefield mf;
    mf.create();
    mf.undermine();
    // game context    int turn = 0;
    int x, y;
    core_sleepSecs(2);
    while(!isEndCurrentGame())
    {
        // while the current game is in progress
        core_clearScr();
        showTitle();
        // turn informations
        println("Turn: " + core_formatNumber(++turn));
        print("Next player: ");
        if(p1.isHasTurn())
        {
            println(p1.getNickName());
        }
        else
        {
            println(p2.getNickName());
        }
        println(p1.getNickName() + ": " + core_formatNumber(p1.getMinePoints()));
        println(p2.getNickName() + ": " + core_formatNumber(p2.getMinePoints()));

        // shows the minefield
        mf.show();

        // getting row
        do
        {
            print("ROW: ");
            int row;
            std::cin >> row;
            std::cin.clear();
            std::cin.ignore(sizeof(int), '\n');
            x = correctRow(row);
        }
        while(!checkRow(x));

        // getting column
        do
        {
            print("COLUMN: ");
            int col;
            std::cin >> col;
            std::cin.clear();
            std::cin.ignore(sizeof(int), '\n');
            y = correctColumn(col);
        }
        while(!checkColumn(y));

        // update the "clicked" position
        mf.update(x, y);
        // checks if the "clicked" field was undermined
        if(mf.fieldIsUndermined(x, y))
        {
            // count the turn owner mine points
            if(p1.isHasTurn())
            {
                p1.countMinePoints();
            }
            else
            {
                p2.countMinePoints();
            }
        }
        else
        {
            // if it was not
            // the next player will be the other
            if(p1.isHasTurn())
            {
                p1.setHasTurn(false);
                p2.setHasTurn(true);
            }
            else
            {
                p1.setHasTurn(true);
                p2.setHasTurn(false);
            }
        }
        // checks if the players reached the winning mine points count
        //if(p1.getMinePoints()>=((int)(CONF_GAME_MINEFIELD_NUM_OF_MINES/2)+1))
        if(p1.getMinePoints()>=1)
        {
            setEndCurrentGame(true);
            // player one is the winner - ends the game
            core_clearScr();
            showTitle();
            println("Game ended!");
            print("The winner is: ");
            println(p1.getNickName());
            mf.show();
            core_pauseScr();
        }
        //else if(p2.getMinePoints()>=((int)(CONF_GAME_MINEFIELD_NUM_OF_MINES/2)+1))
        else if(p2.getMinePoints()>=1)
        {
            setEndCurrentGame(true);
            // player two is the winner - ends the game
            core_clearScr();
            showTitle();
            println("Game ended!");
            print("The winner is: ");
            println(p2.getNickName());
            mf.show();
            core_pauseScr();
        }
    }
}

/**
 * Corrects the row input.
 *
 * @param row the row
 * @return the corrected row
 */
int MineszwiperGame::correctRow(int row)
{
    return row - 1;
}

/**
 * Corrects the column input.
 *
 * @param column the column
 * @return the corrected column
 */
int MineszwiperGame::correctColumn(int column)
{
    return column - 1;
}

/**
 * Checks if the given nick name is valid.
 *
 * @param nickName the nick name
 * @return true, if the nickName is valid
 */
bool MineszwiperGame::checkNickName(std::string nickName)
{
    // TODO [dderdak] checkNickName
    return true;
}

/**
 * Checks if the given row is valid.
 *
 * @param row the row
 * @return true, if the row is valid
 */
bool MineszwiperGame::checkRow(int row)
{
    // TODO [dderdak] checkRow
    return true;
}

/**
 * Checks if the given column is valid.
 *
 * @param column the column
 * @return true, if the column is valid
 */
bool MineszwiperGame::checkColumn(int column)
{
    // TODO [dderdak] checkColumn    return true;
}
