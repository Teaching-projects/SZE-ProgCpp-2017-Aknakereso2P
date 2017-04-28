#include "minefield_test.h"

/**
 * Instantiates a new Minefield test.
 */
MinefieldTest::MinefieldTest()
{
    Logger::getInstance()->logDebug("Running 'Minefield' entity tests");
    run();
    Logger::getInstance()->logDebug("'Minefield' entity is valid");
}

/**
 * Runs the tests for Minefield entity.
 */
void MinefieldTest::run(void)
{
    Minefield mineField;
    mineField.create();
    mineField.undermine();
    mineField.show(true);
}
