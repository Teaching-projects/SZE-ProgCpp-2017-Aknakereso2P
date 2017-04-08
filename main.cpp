#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "src/main/util/constants.h"
#include "src/main/configs/game.h"
#include "src/main/util/printer.h"
#include "src/main/util/logger.h"

#include "src/main/runner/app_initializr.h"
#include "src/test/runner/test_app_initializr.h"

/**
 * The 'Mineszwiper' game entry point.
 *
 * @author dderdak
 */
int main()
{
    MineszwiperTestAppInitializr().run();
    //run();
    return 0;
}
