#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

#include "../util/consts.h"

/**
 * The Class Player.
 */
class Player
{
    private:
        std::string     nickName;
        int		        minePoints;
        bool	        hasTurn;

    public:
        Player();
        void countMinePoints(void);
        std::string getNickName(void);
        void setNickName(std::string nName);
        int getMinePoints(void);
        void setMinePoints(int mp);
        bool isHasTurn(void);
        void setHasTurn(bool ht);
};

#endif // PLAYER_H_INCLUDED
