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

/**
 * Instantiates a new player.
 */
Player::Player()
{
    firstName = CONST_PLAYER_ANONYMOUS_FIRSTNAME;
    lastName = CONST_PLAYER_ANONYMOUS_LASTNAME;
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
 * Gets the first name.
 *
 * @return the first name
 */
std::string Player::getFirstName(void)
{
    return firstName;
}

/**
 * Sets the first name.
 *
 * @param fName the new first name
 */
void Player::setFirstName(std::string fName)
{
    firstName = fName;
}

/**
 * Gets the last name.
 *
 * @return the last name
 */
std::string Player::getLastName(void)
{
    return lastName;
}

/**
 * Sets the last name.
 *
 * @param lName the new last name
 */
void Player::setLastName(std::string lName)
{
    lastName = lName;
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
