#include "../entity/field_test.h"
#include "../entity/minefield_test.h"
#include "../entity/player_test.h"

/**
 * The Class MineszwiperTestAppInitializr.
 */
class MineszwiperTestAppInitializr
{
    public:
        MineszwiperTestAppInitializr();
        void run(void);
};

/**
 * Instantiates a new Mineszwiper test app initializer.
 */
MineszwiperTestAppInitializr::MineszwiperTestAppInitializr()
{
    logger.logDebug("Tests are enabled");
}

/**
 * Run.
 */
void MineszwiperTestAppInitializr::run(void)
{
    logger.logDebug("Tests running...");
    FieldTest ft;
    ft.run();
    MinefieldTest mft;
    mft.run();
    PlayerTest pt;
    pt.run();
    logger.logDebug("Tests finished");
}
