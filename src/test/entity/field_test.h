/**
 * The Class FieldTest.
 */
class FieldTest
{
    public:
        void run(void);
};

/**
 * Runs the tests for Field entity.
 */
void FieldTest::run(void)
{
    logger.logDebug("Running 'Field' entity tests");
    Field field;
    field.setId(1);
    field.setCoordinateX(2);
    field.setCoordinateY(3);
    field.countMineSignal();
    logger.logDebug("'Field' entity is valid");
}
