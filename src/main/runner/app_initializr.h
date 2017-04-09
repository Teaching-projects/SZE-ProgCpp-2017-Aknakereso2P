#include "app_configs.h"

Logger logger = Logger(CONF_GAME_ENV_LOG_LEVEL);

#include "../logic/core.h"

#include "../entity/field.h"
#include "../entity/minefield.h"
#include "../entity/player.h"
#include "../logic/game.h"

#include "../../test/runner/test_app_initializr.h"

/**
 * The Class MineszwiperAppInitializr.
 */
class MineszwiperAppInitializr
{
    private:
        MineszwiperGame game;

    public:
        /**
         * Instantiates a new Mineszwiper game initializer.
         */
        MineszwiperAppInitializr()
        {
            logger.logInfo("Initializing...");
            if( core_isDevEnvironment() )
            {
                MineszwiperTestAppInitializr().run();
            }
            game = MineszwiperGame();
            logger.logInfo("Initialization finished");
            core_sleepSecs(2);
        }

        /**
         * Runs the application.
         */
        void run()
        {
            while(!game.isEnd())
            {
                game.showStartScreen();
            }
            game.showExitScreen();
        }

};
