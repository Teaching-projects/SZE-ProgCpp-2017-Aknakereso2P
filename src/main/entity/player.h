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
        std::string     firstName;
        std::string     lastName;
        std::string     nickName;
        int		        minePoints;
        bool	        hasTurn;

    public:
        Player();
        void countMinePoints(void);
        std::string getFirstName(void);
        void setFirstName(std::string fName);
        std::string getLastName(void);
        void setLastName(std::string lName);
        std::string getNickName(void);
        void setNickName(std::string nName);
        int getMinePoints(void);
        void setMinePoints(int mp);
        bool isHasTurn(void);
        void setHasTurn(bool ht);
};

#endif // PLAYER_H_INCLUDED
