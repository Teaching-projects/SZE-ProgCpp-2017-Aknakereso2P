/**
 * The Class FieldTest.
 */
class FieldTest
{
    private:
        Field field;

    public:
        /**
         * Instantiates a new field test.
         */
        FieldTest()
        {
            field = Field(1, 2, 3);
        }

        /**
         * Test for Field entity.
         */
        void testField()
        {
            logger.logDebug("Running 'Field' entity tests");
            field.countMineSignal();
            logger.logDebug("'Field' entity is valid");
        }

};
