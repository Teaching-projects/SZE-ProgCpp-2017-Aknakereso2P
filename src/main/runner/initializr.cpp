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
        MineszwiperAppInitializr tests;
        Utilities::core_pauseScr();
    }
    Logger::getInstance()->logInfo("Initialization finished");
    try
    {
        Logger::getInstance()->logInfo("Application starting...");
        run();
    }
    catch (...)
    {
        Logger::getInstance()->logError("Ooups!... Something went wrong :( ");
    }
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
