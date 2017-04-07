#include "../entity/field_test.h"
#include "../entity/minefield_test.h"
#include "../entity/player_test.h"

/**
 * Run tests.
 */
void runTests()
{
    printDebug("Initializing...");
    if( CONST_GAME_TESTS_ENABLED )
    {
        testPlayer();
        testField();
        testMinefield();
        clearScreen();
    }
    printDebug("Initialization finished!");
}
