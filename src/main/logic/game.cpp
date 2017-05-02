#include "game.h"

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
    Utilities::core_clearScr();
    showTitle();
    showMenu();
    showSelectMenu();
}

/**
 * Exiting console screen.
 */
void MineszwiperGame::showExitScreen(void)
{
    Utilities::core_clearScr();
    showTitle();
    Utilities::println();
    Utilities::println("Program exiting...");
    Utilities::println("Good bye!");
    Utilities::println();
    Utilities::core_pauseScr();
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
 * @param ecg the new current end game
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
    Utilities::print(CONST_MINEFIELD_HEADER_H_OFFSET);
    Utilities::println();
    for(int i=0; i<CONF_GAME_HEADER_WIDTH_OFFSET; i++)
    Utilities::print(CONST_MINEFIELD_HEADER_W_OFFSET);
    Utilities::println(CONST_GAME_NAME);
    for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
    Utilities::print(CONST_MINEFIELD_HEADER_H_OFFSET);
    Utilities::println();
}

/**
 * Shows the game menu.
 */
void MineszwiperGame::showMenu()
{
    Utilities::println();
    Utilities::println("1. New game");
    Utilities::println("2. Exit");
    Utilities::println();
}

/**
 * Select menu item from user at the start screen.
 */
void MineszwiperGame::showSelectMenu()
{
    Utilities::print("Please select a menu: ");
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
            Utilities::println("Wrong menu selected!");
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
    Utilities::core_clearScr();
    showTitle();
    Utilities::println("Starting new game with players...");
    Utilities::println();

    // getting player one nickname
    std::string n1;
    do
    {
        Utilities::print("Player one nickname: ");
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
    std::string n2;
    do
    {
        Utilities::print("Player two nickname: ");
        std::cin >> n2;
        std::cin.clear();
        std::cin.ignore(sizeof(std::string), '\n');
    }
    while(!checkNickName(n2));
    Player p2;
    p2.setNickName(n2);

    Utilities::println();
    Utilities::println("Game starting");

    // create new minefield
    Minefield mf;

    // game context    int turn = 0;
    int x, y;
    while(!isEndCurrentGame())
    {
        // while the current game is in progress
        Utilities::core_clearScr();
        showTitle();
        // turn informations
        Utilities::print("Turn: ");
        Utilities::println(Utilities::core_formatNumber(turn+1));
        Utilities::print("Next player: ");
        if(p1.isHasTurn())
        {
            Utilities::println(p1.getNickName());
        }
        else
        {
            Utilities::println(p2.getNickName());
        }

        // player 1 informations
        Utilities::print(p1.getNickName());
        Utilities::print(": ");
        Utilities::print(Utilities::core_formatNumber(p1.getMinePoints()));
        Utilities::println();

        // player 2 informations
        Utilities::print(p2.getNickName());
        Utilities::print(": ");
        Utilities::print(Utilities::core_formatNumber(p2.getMinePoints()));
        Utilities::println();

        // shows the minefield
        mf.show();

        // getting row
        do
        {
            Utilities::print("ROW: ");
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
            Utilities::print("COLUMN: ");
            char col;
            std::cin >> col;
            std::cin.clear();
            std::cin.ignore(sizeof(char), '\n');
            y = correctColumn(col);
        }
        while(!checkColumn(y));

        if(!mf.fieldIsFlagged(x, y))
        {
            // update the "clicked" position
            mf.update(x, y);

            // checks if the "clicked" field was undermined
            if(mf.fieldIsUndermined(x, y))
            {
                // count the turn owner mine points
                if(p1.isHasTurn())
                {
                    // count player points
                    p1.countMinePoints();
                }
                else
                {
                    // count player points
                    p2.countMinePoints();
                }

            }
            // if it was not the next player will be the other player
            else if(p1.isHasTurn())
            {
                p1.setHasTurn(false);
                p2.setHasTurn(true);
            }
            else
            {
                p1.setHasTurn(true);
                p2.setHasTurn(false);
            }

            // checks if the players reached the winning mine points count
            if(p1.getMinePoints()>=((int)(CONF_GAME_MINEFIELD_NUM_OF_MINES/2)+1))
            {
                setEndCurrentGame(true);
                // player one is the winner - ends the game
                Utilities::core_clearScr();
                showTitle();
                Utilities::println("Game ended!");
                Utilities::print("The winner is: ");
                Utilities::println(p1.getNickName());
                mf.show();
                Utilities::core_pauseScr();
            }
            else if(p2.getMinePoints()>=((int)(CONF_GAME_MINEFIELD_NUM_OF_MINES/2)+1))
            {
                setEndCurrentGame(true);
                // player two is the winner - ends the game
                Utilities::core_clearScr();
                showTitle();
                Utilities::println("Game ended!");
                Utilities::print("The winner is: ");
                Utilities::println(p2.getNickName());
                mf.show();
                Utilities::core_pauseScr();
            }
            turn++;
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
int MineszwiperGame::correctColumn(char column)
{
    for(int i=0; i<CONF_GAME_MINEFIELD_COLUMNS; i++)
    {
        if(column==CONST_MINEFIELD_HEADER[i]
           || toupper(column) == CONST_MINEFIELD_HEADER[i])
        {
            return i;
        }
    }
    return -1;
}

/**
 * Checks if the given nick name is valid.
 *
 * @param nickName the nick name
 * @return true, if the nickName is valid
 */
bool MineszwiperGame::checkNickName(std::string nickName)
{
    if( nickName.empty() )
    {
        Utilities::println("Nickname can not be empty!");
        return false;
    }
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
    if( row < 0 && row > CONF_GAME_MINEFIELD_ROWS)
    {
        Utilities::println("Given ROW is out of range! Help [1;16]");
        return false;
    }
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
    if( column < 0 && column > CONF_GAME_MINEFIELD_COLUMNS)
    {
        Utilities::println("Given COLUMN is out of range! Help [A;P]");
        return false;
    }
    return true;
}
