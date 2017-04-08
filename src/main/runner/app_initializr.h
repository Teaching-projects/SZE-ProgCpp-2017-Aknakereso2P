#include "../logic/core.h"

#include "../entity/field.h"
#include "../entity/minefield.h"
#include "../entity/player.h"

#include "../logic/game.h"

/**
 * The Class MineszwiperAppInitializr.
 */
class MineszwiperAppInitializr
{
    private:
        bool endgame;

    public:
        MineszwiperAppInitializr()
        {
            endgame = false;
        }

        /**
         * Runs the application.
         */
        void run()
        {
            while(!endgame)
            {
                showStartScreen();
            }
            showExitScreen();
        }

    private:
        /**
         * Exiting console screen.
         */
        void showExitScreen()
        {
            println("Program exiting...");
            println("Please press any key to exit");

            pause();
        }

        /**
         * Shows the start screen.
         */
        void showStartScreen()
        {
            showTitle();
            showMenu();
            selectMenuItem();
        }

        /**
         * End.
         */
        void endGame(Player winner)
        {
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

            std::cin >> playerOneNickName;
            std::cin >> playerTwoNickName;

            Minefield mineField = Minefield();
            Player p1 = Player(playerOneNickName);
            Player p2 = Player(playerOneNickName);
            turn = 1;

            while(!endgame)
            {
                mineField.show();
                std::cin >> x;
                std::cin >> col;

                for(int i=0; i<CONF_GAME_MINEFIELD_COLUMNS; i++)
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
         * Select menu item from user at the start screen.
         */
        void selectMenuItem()
        {
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
                    endGame(Player());
                    break;
                default:
                    selectMenuItem();
                    break;
            }
        }

};
