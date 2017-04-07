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
        /**
         * Instantiates a new player.
         */
        Player()
        {
            firstName = CONST_PLAYER_ANONYMOUS_FIRSTNAME;
            lastName = CONST_PLAYER_ANONYMOUS_LASTNAME;
            nickName = CONST_PLAYER_ANONYMOUS_NICKNAME;
            minePoints = 0;
            hasTurn = false;
        }

        /**
         * Instantiates a new player with given nick name.
         *
         * @param nn the nick name
         */
        Player(std::string nn)
        {
            firstName = CONST_PLAYER_ANONYMOUS_FIRSTNAME;
            lastName = CONST_PLAYER_ANONYMOUS_LASTNAME;
            nickName = nn;
            minePoints = 0;
            hasTurn = false;
        }

        /**
         * Increase the mine point of the player by one.
         */
        void countMinePoints()
        {
            ++minePoints;
        }

        /**
         * Gets the first name.
         *
         * @return the first name
         */
        std::string getFirstName()
        {
            return firstName;
        }

        /**
         * Sets the first name.
         *
         * @param fName the new first name
         */
        void setFirstName( std::string fName )
        {
            firstName = fName;
        }

        /**
         * Gets the last name.
         *
         * @return the last name
         */
        std::string getLastName()
        {
            return lastName;
        }

        /**
         * Sets the last name.
         *
         * @param lName the new last name
         */
        void setLastName( std::string lName )
        {
            lastName = lName;
        }

        /**
         * Gets the nick name.
         *
         * @return the nick name
         */
        std::string getNickName()
        {
            return nickName;
        }

        /**
         * Sets the nick name.
         *
         * @param nName the new nick name
         */
        void setNickName( std::string nName )
        {
            nickName = nName;
        }

        /**
         * Gets the mine points.
         *
         * @return the mine points
         */
        int getMinePoints()
        {
            return minePoints;
        }

        /**
         * Sets the mine points.
         *
         * @param mp the new mine points
         */
        void setMinePoints( int mp )
        {
            minePoints = mp;
        }

        /**
         * Checks if is checks for turn.
         *
         * @return true, if is checks for turn
         */
        bool isHasTurn()
        {
            return hasTurn;
        }

        /**
         * Sets the checks for turn.
         *
         * @param ht the new checks for turn
         */
        void setHasTurn( bool ht )
        {
            hasTurn = ht;
        }

};
