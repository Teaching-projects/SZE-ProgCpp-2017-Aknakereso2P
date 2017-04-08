/**
 *
 */

/**
 * Test for Field entity.
 */
void testField()
{
    logger.logDebug("Running 'Field' entity tests");
    Field f (1, 2, 3);
    f.countMineSignal();
    logger.logDebug("'Field' entity is valid");
}
