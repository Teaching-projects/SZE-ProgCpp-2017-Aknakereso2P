#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include <iostream>

#include "../util/consts.h"
#include "../util/utilities.h"
#include "../entity/field.h"
#include "../entity/minefield.h"
#include "../entity/player.h"

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
        int correctColumn(char column);
};

#endif // GAME_H_INCLUDED
