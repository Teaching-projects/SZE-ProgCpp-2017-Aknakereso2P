#include "player_test.h"

/**
 * Instantiates a new Player test.
 */
PlayerTest::PlayerTest()
{
    Logger::getInstance()->logDebug("Running 'Player' entity tests");
    run();
    Logger::getInstance()->logDebug("'Player' entity is valid");
}

/**
 * Runs the tests for Player entity.
 */
void PlayerTest::run(void)
{
    Player player;
    player.setNickName("testPlayer");
}
