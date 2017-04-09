/**
 * The Class PlayerTest.
 */
class PlayerTest
{
    private:
        Player player;

    public:
        /**
         * Instantiates a new player test.
         */
        PlayerTest()
        {
            player = Player("testPlayer");
        }

        /**
         * Test for Player entity.
         */
        void testPlayer()
        {
            logger.logDebug("Running 'Player' entity tests");
            logger.logDebug("'Player' entity is valid");
        }

};
