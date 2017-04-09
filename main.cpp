#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "src/main/util/consts.h"
#include "src/main/util/enums.h"
#include "src/main/util/logger.h"

#include "src/main/runner/app_initializr.h"

/**
 * The 'Mineszwiper' game entry point.
 *
 * @author dderdak
 */
int main()
{
    MineszwiperAppInitializr().run();
    return 0;
}
