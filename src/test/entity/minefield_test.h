/**
 * Test for Minefield entity.
 */
void testMinefield()
{
    logger.logDebug("Running 'Minefield' entity tests");
    Minefield mf = Minefield();
    mf.create();
    // mf.undermine();
    logger.logDebug("'Minefield' entity is valid");
}
