#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <iostream>
#include <sstream>
#include <windows.h>

#include "src/main/util/consts.h"
#include "src/main/util/enums.h"
#include "src/main/util/logger.h"

#include "src/main/runner/initializr.h"

/**
 * The 'Mineszwiper' game entry point.
 *
 * @author dderdak
 */
int main()
{
    MineszwiperAppInitializr mineszwiper;
    mineszwiper.run();
    return 0;
}
