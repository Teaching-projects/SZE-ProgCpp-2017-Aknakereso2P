#include "../entity/field_test.h"
#include "../entity/minefield_test.h"
#include "../entity/player_test.h"

/**
 * The Class MineszwiperTestAppInitializr.
 */
class MineszwiperTestAppInitializr
{
    public:
        /**
         * Instantiates a new Mineszwiper test app initializer.
         */
        MineszwiperTestAppInitializr()
        {
            logger.logDebug("Tests are enabled");
        }

        /**
         * Run.
         */
        void run()
        {
            logger.logDebug("Tests running...");

            FieldTest ft = FieldTest();
            MinefieldTest mft = MinefieldTest();
            PlayerTest pt = PlayerTest();

            ft.testField();
            mft.testMinefield();
            pt.testPlayer();

            logger.logDebug("Tests finished");
        }

};
