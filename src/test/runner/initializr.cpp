#include "initializr.h"

/**
 * Instantiates a new Mineszwiper test app initializer.
 */
MineszwiperTestAppInitializr::MineszwiperTestAppInitializr()
{
    Logger::getInstance()->logDebug("Tests are enabled");
}

/**
 * Run.
 */
void MineszwiperTestAppInitializr::run(void)
{
    Logger::getInstance()->logDebug("Tests running...");
    FieldTest ft;
    ft.run();
    MinefieldTest mft;
    mft.run();
    PlayerTest pt;
    pt.run();
    Logger::getInstance()->logDebug("Tests finished");
    Utilities::core_pauseScr();
}
