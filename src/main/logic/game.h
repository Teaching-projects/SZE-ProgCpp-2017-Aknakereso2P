/**
 * The Class MineszwiperGame.
 */
class MineszwiperGame
{
    private:
        bool endgame;

    public:
        /**
         * Instantiates a new Mineszwiper game.
         */
        MineszwiperGame()
        {
            endgame = false;
        }

        /**
         * Shows the start screen.
         */
        void showStartScreen()
        {
            core_clearScr();
            showTitle();
            showMenu();
            showSelectMenu();
        }

        /**
         * Exiting console screen.
         */
        void showExitScreen()
        {
            core_clearScr();
            showTitle();
            println("Program exiting...");
            println("Good bye!");
            core_sleepSecs(3);
        }

        /**
         * Checks if the game is ended.
         *
         * @return true, if the game is ended
         */
        bool isEnd()
        {
            return endgame;
        }

    private:
        /**
         * Shows the game title.
         */
        void showTitle()
        {
            for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
            print("-");
            println();
            std::cout << "          " << CONST_GAME_NAME;
            println();
            for(int i=0; i<CONF_GAME_HEADER_WIDTH; i++)
            print("-");
            println();
            println();
        }

        /**
         * Shows the game menu.
         */
        void showMenu()
        {
            println("1. New game");
            println("2. Exit");
            println();
        }

        /**
         * Select menu item from user at the start screen.
         */
        void showSelectMenu()
        {
            print("Please select a menu: ");
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
                    endGame();
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
        void startNewGame()
        {
            int x, y;
            char col;
            std::string playerOneNickName, playerTwoNickName;

            std::cin >> playerOneNickName;
            std::cin >> playerTwoNickName;

            Minefield mineField = Minefield();
            Player p1 = Player(playerOneNickName);
            Player p2 = Player(playerOneNickName);

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

            endGame();
        }

        /**
         * Ends game.
         */
        void endGame()
        {
            endgame = true;
        }

};
