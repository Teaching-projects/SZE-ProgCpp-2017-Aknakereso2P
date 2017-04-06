#include <stdio.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "src/main/constants.h"
#include "src/main/enumerations.h"

#include "src/main/entity/field.h"
#include "src/main/entity/minefield.h"
#include "src/main/entity/player.h"

#include "src/main/util/logger.h"
#include "src/main/util/game.h"

/**
 * The 'Mineszwiper' game entry point.
 *
 * @author dderdak
 */
int main()
{
    showStartScreen();
    exitScreen();
    return 0;
}
