#include "ComputerPlayer.h"
#include "../runner/configs.h"
#include <cstdlib>

/**
 * Instantiates a new player.
 */
ComputerPlayer::ComputerPlayer()
{
    nickName = CONST_COMPUTER_PLAYER_NICKNAME;
    minePoints = 0;
    hasTurn = false;
}

int ComputerPlayer::GetColumn()
{
    return 97 + (rand() % (int)(CONF_GAME_MINEFIELD_COLUMNS));
}

int ComputerPlayer::GetRow()
{
    return 1 + (rand() % (int)(CONF_GAME_MINEFIELD_ROWS));
}
