#ifndef MINEFIELD_H_INCLUDED
#define MINEFIELD_H_INCLUDED

#include <ctime>
#include <set>
#include <iostream>
#include <sstream>

#include "../runner/configs.h"
#include "../util/consts.h"
#include "../util/enums.h"
#include "../util/utilities.h"
#include "../util/logger.h"

#include "field.h"

/**
 * The Class Minefield.
 */
class Minefield
{
    private:
        Field    mtx[CONF_GAME_MINEFIELD_ROWS][CONF_GAME_MINEFIELD_COLUMNS];
        int      rows;
        int      columns;
        int      numOfMines;

    public:
        Minefield();
        void create(void);
        void undermine(void);
        void show(void);
        void show(bool forTest);
        void update(int x, int y);
        bool fieldIsUndermined(int x, int y);
        bool fieldIsFlagged(int x, int y);

    private:
        int getFieldIdFromCoordinates(int x, int y);
        int getXCoordinateByFieldId(int id);
        int getYCoordinateByFieldId(int id);
        int getNextRow(FieldPlace fieldPlace, int x);
        int getNextColumn(FieldPlace fieldPlace, int y);
        bool checkCoordinates(int x, int y);
};

#endif // MINEFIELD_H_INCLUDED
