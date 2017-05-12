#include "ComputerPlayer.h"

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
    return 97;
}

int ComputerPlayer::GetRow()
{
    return 1;
}
