#include "initializr.h"

/**
 * Instantiates a new Mineszwiper game initializer.
 */
MineszwiperAppInitializr::MineszwiperAppInitializr()
{
    Logger::getInstance()->logInfo("Initializing...");
    if(Utilities::core_isDevEnvironment())
    {
        MineszwiperTestAppInitializr tests;
        tests.run();
    }
    Logger::getInstance()->logInfo("Initialization finished");
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
