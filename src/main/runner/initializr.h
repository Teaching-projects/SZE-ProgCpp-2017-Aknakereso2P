#include "configs.h"

#include "../logic/core.h"

static Logger logger = Logger(CONF_GAME_ENV_LOG_LEVEL);

#include "../entity/field.h"
#include "../entity/minefield.h"
#include "../entity/player.h"

#include "../logic/game.h"

#include "../../test/runner/initializr.h"

/**
 * The Class MineszwiperAppInitializr.
 */
class MineszwiperAppInitializr
{
    public:
        MineszwiperAppInitializr();
        void run(void);
};

/**
 * Instantiates a new Mineszwiper game initializer.
 */
MineszwiperAppInitializr::MineszwiperAppInitializr()
{
    logger.logInfo("Initializing...");
    if( core_isDevEnvironment() )
    {
        MineszwiperTestAppInitializr tests;
        tests.run();
    }
    logger.logInfo("Initialization finished");
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
