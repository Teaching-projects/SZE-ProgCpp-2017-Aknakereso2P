/**
 * The Class MinefieldTest.
 */
class MinefieldTest
{
    public:
        void run(void);
};

/**
 * Runs the tests for Minefield entity.
 */
void MinefieldTest::run(void)
{
    logger.logDebug("Running 'Minefield' entity tests");
    Minefield mineField;
    mineField.create();
    mineField.undermine();
    mineField.update(0, 0);
    logger.logDebug("'Minefield' entity is valid");
}
