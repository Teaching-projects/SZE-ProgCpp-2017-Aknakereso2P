/**
 * The Class PlayerTest.
 */
class PlayerTest
{
    public:
        void run(void);
};

/**
 * Runs the tests for Player entity.
 */
void PlayerTest::run(void)
{
    logger.logDebug("Running 'Player' entity tests");
    Player player;
    player.setNickName("testPlayer");
    logger.logDebug("'Player' entity is valid");
}
