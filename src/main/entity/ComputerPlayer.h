#ifndef COMPUTER_PLAYER_H_INCLUDED
#define COMPUTER_PLAYER_H_INCLUDED

#include "player.h"

/**
 * The Class ComputerPlayer.
 */
class ComputerPlayer : public Player
{
public:
    ComputerPlayer();

    int GetColumn() override;

    int GetRow() override;
};

#endif // PLAYER_H_INCLUDED
