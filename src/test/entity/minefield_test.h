/**
 * The Class MinefieldTest.
 */
class MinefieldTest
{
    private:
        Minefield mineField;

    public:
        /**
         * Instantiates a new minefield test.
         */
        MinefieldTest()
        {
            mineField = Minefield();
        }

        /**
         * Test for Minefield entity.
         */
        void testMinefield()
        {
            logger.logDebug("Running 'Minefield' entity tests");
            mineField.create();
            mineField.undermine();
            logger.logDebug("'Minefield' entity is valid");
        }

};
