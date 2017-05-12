#include "player.h"
#include "../util/utilities.h"

/**
 * Instantiates a new player.
 */
Player::Player()
{
    nickName = CONST_PLAYER_ANONYMOUS_NICKNAME;
    minePoints = 0;
    hasTurn = false;
}

/**
 * Increase the mine point of the player by one.
 */
void Player::countMinePoints(void)
{
    ++minePoints;
}

/**
 * Gets the nick name.
 *
 * @return the nick name
 */
std::string Player::getNickName(void)
{
    return nickName;
}

/**
 * Sets the nick name.
 *
 * @param nName the new nick name
 */
void Player::setNickName(std::string nName)
{
    nickName = nName;
}

/**
 * Gets the mine points.
 *
 * @return the mine points
 */
int Player::getMinePoints(void)
{
    return minePoints;
}

/**
 * Sets the mine points.
 *
 * @param mp the new mine points
 */
void Player::setMinePoints(int mp)
{
    minePoints = mp;
}

/**
 * Checks if is checks for turn.
 *
 * @return true, if is checks for turn
 */
bool Player::isHasTurn(void)
{
    return hasTurn;
}

/**
 * Sets the checks for turn.
 *
 * @param ht the new checks for turn
 */
void Player::setHasTurn(bool ht)
{
    hasTurn = ht;
}

int Player::GetColumn()
{
    Utilities::print("COLUMN: ");
    char col;
    std::cin >> col;
    std::cin.clear();
    std::cin.ignore(sizeof(char), '\n');

    return col;
}

int Player::GetRow()
{
    Utilities::print("ROW: ");
    int row;
    std::cin >> row;
    std::cin.clear();
    std::cin.ignore(sizeof(int), '\n');

    return row;
}
