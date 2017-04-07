#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <iostream>
#include <windows.h>

#include "src/main/configs/logger.h"
#include "src/main/configs/minefield.h"
#include "src/main/configs/game.h"

#include "src/main/util/constants.h"
#include "src/main/util/logger.h"

#include "src/main/entity/field.h"
#include "src/main/entity/minefield.h"
#include "src/main/entity/player.h"

#include "src/main/logic/game.h"

#include "src/main/runner/app_initializr.h"
#include "src/test/runner/test_app_initializr.h"

/**
 * The 'Mineszwiper' game entry point.
 *
 * @author dderdak
 */
int main()
{
    runTests();
    run();
    return 0;
}
