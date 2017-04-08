#include "../entity/field_test.h"
#include "../entity/minefield_test.h"
#include "../entity/player_test.h"

#include "../util/logger_test.h"

/**
 * The Class MineszwiperTestAppInitializr.
 */
class MineszwiperTestAppInitializr
{
    public:
        /**
         * Run.
         */
        void run()
        {
            logger.logInfo("Initializing...");
            if( isDevEnvironment() )
            {
                logger.logDebug("Tests are enabled");
                logger.logDebug("Tests running...");

                testField();
                testMinefield();
                testPlayer();            }
            logger.logInfo("Initialization finished");

            pause();
            clearScr();
        }

};
