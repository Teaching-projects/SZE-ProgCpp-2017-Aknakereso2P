#include "initializr.h"

/**
 * Instantiates a new Mineszwiper test application initializer.
 */
MineszwiperTestAppInitializr::MineszwiperTestAppInitializr()
{
    Logger::getInstance()->logDebug("Tests are running...");
    run();
    Logger::getInstance()->logDebug("Tests finished");
}

/**
 * Run.
 */
void MineszwiperTestAppInitializr::run(void)
{
    FieldTest ft;
    MinefieldTest mft;
    PlayerTest pt;
}
