#include "initializr.h"

/**
 * Instantiates a new Mineszwiper application initializer.
 */
MineszwiperAppInitializr::MineszwiperAppInitializr()
{
    Logger::getInstance()->logInfo("Initializing...");
    if(Utilities::core_isDevEnvironment())
    {
        Logger::getInstance()->logDebug("Tests are enabled");
        MineszwiperTestAppInitializr tests;
        Utilities::core_pauseScr();
    }
    Logger::getInstance()->logInfo("Initialization finished");
    run();
}

/**
 * Runs the application.
 */
void MineszwiperAppInitializr::run(void)
{
    MineszwiperGame game;
    while(!game.isEnd())
    {
        game.showStartScreen();
    }
    game.showExitScreen();
}
