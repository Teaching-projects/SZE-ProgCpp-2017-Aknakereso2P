/**
 * The Class Minefield.
 */
class Minefield
{
    private:
        static int      rows;
        static int      columns;
        static int      numOfMines;
        Field           mtx[CONF_GAME_MINEFIELD_ROWS][CONF_GAME_MINEFIELD_COLUMNS];

    public:
        void create(void);
        void undermine(void);
        void show(void);
        void update(int x, int y);
        bool fieldIsUndermined(int x, int y);

    private:
        int getFieldIdFromCoordinates(int x, int y);
        int getXCoordinateByFieldId(int id);
        int getYCoordinateByFieldId(int id);
        int getNextRow(FieldPlace fieldPlace, int x);
        int getNextColumn(FieldPlace fieldPlace, int y);
        bool checkCoordinates(int x, int y);
};

/**
 * Static initialization.
 */
int Minefield::rows = CONF_GAME_MINEFIELD_ROWS;
int Minefield::columns = CONF_GAME_MINEFIELD_COLUMNS;
int Minefield::numOfMines = CONF_GAME_MINEFIELD_NUM_OF_MINES;

/**
 * Creates the minefield matrix.
 */
void Minefield::create(void)
{
    logger.logDebug("Creating minefield matrix");
    println("Generating fields");
    for(int r=0; r<rows; r++)
    {
        for(int c=0; c<columns; c++)
        {
            // update fields
            int id = getFieldIdFromCoordinates(r, c);
            mtx[r][c].setId(id);
            mtx[r][c].setCoordinateX(getXCoordinateByFieldId(id));
            mtx[r][c].setCoordinateY(getYCoordinateByFieldId(id));
            // print informations about generation process
            if( (r+1)*(c+1) % ((int)((rows*columns)/10)) == 0 )
            {
                // if created the 10% of number of the generated fields
                print(".");
            }
            if( (r+1)*(c+1) == rows*columns )
            {
                // if created the 100% of number of the generated fields
                println(".");
            }
        }
    }
    logger.logDebug("Successfully created minefield matrix");
    logger.logDebug("Matrix size: [" + core_formatNumber(rows) + "][" + core_formatNumber(columns) + "]");
}

/**
 * Undermine the minefield matrix.
 */
void Minefield::undermine(void)
{
    logger.logDebug("Undermining minefield matrix");
    int numOfGeneratedMines = 0;
    println("Generating undermined fields");
    srand((unsigned int)time(0));
    std::set<int> indexOfGeneratedMines;
    while(numOfGeneratedMines < numOfMines)
    {
        int x = (rand()%(rows - 1)) + 1;
        int y = (rand()%(columns - 1)) + 1;
        int indexOfGeneratedMine = getFieldIdFromCoordinates(x, y);
        if(indexOfGeneratedMines.count(indexOfGeneratedMine)==0)
        {
            indexOfGeneratedMines.insert(indexOfGeneratedMine);
            mtx[x][y].setMineSignal(CONST_FIELD_UNDERMINED);
            numOfGeneratedMines++;
            // looking for mines around the actual field at x, y coordinate
            for(int fieldPlace=FP_OVER; fieldPlace!=FP_RIGHT_OVER; fieldPlace++)
            {
                FieldPlace p = static_cast<FieldPlace>(fieldPlace);
                int nextXCoor = getNextRow(p, x);
                int nextYCoor = getNextColumn(p, y);
                // valid next coordinates
                if(checkCoordinates(nextXCoor,nextYCoor))
                {
                    // NOT undermined fields
                    if( mtx[nextXCoor][nextYCoor].getMineSignal() >= 0 )
                    {
                        // and counts the mine signal.
                        mtx[nextXCoor][nextYCoor].countMineSignal();
                    }
                }
            }
            // print informations about undermining process
            if( numOfGeneratedMines % ((int)(numOfMines/10)) == 0 )
            {
                // if undermined the 10% of number of the mine numbers
                print(".");
            }
            if( numOfGeneratedMines == numOfMines )
            {
                // if undermined the 100% of number of the mine numbers
                println();
            }
        }
    }
    logger.logDebug("Successfully undermined minefield matrix");
    logger.logDebug("Number of undermined fields: " + core_formatNumber(numOfMines));
}

/**
 * Shows the minefield.
 *
 * @param minefield the minefieldMatrix
 */
void Minefield::show(void)
{
    println();
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_TAB);
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_TAB);
    print(CONST_MINEFIELD_HEADER_W);
    for(int i=0; i<columns; i++)
    {
        print(CONST_TAB);
        print(CONST_MINEFIELD_HEADER[i]);
    }
    print(CONST_TAB);
    println(CONST_MINEFIELD_HEADER_W);
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    for(int i=0; i<columns; i++)
    {
        print(CONST_MINEFIELD_HEADER_H);
        print(CONST_MINEFIELD_HEADER_H_OFFSET);
    }
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H);
    println(CONST_MINEFIELD_HEADER_H_OFFSET);
    for(int i=0; i<rows; i++)
    {
        print(CONST_TAB);
        if((i+1)<10)
        print(CONST_MINEFIELD_HEADER_W_OFFSET);
        print(core_formatNumber(i+1));
        print(CONST_TAB);
        print(CONST_MINEFIELD_HEADER_W);
        for(int j=0; j<columns; j++)
        {
            print(CONST_TAB);
            if( mtx[i][j].isVisibled() )
            {
                if( mtx[i][j].getMineSignal()==CONST_FIELD_EMPTY )
                print(CONST_MINEFIELD_EMPTY_FIELD);
                else if( mtx[i][j].getMineSignal()==CONST_FIELD_UNDERMINED )
                print(CONST_MINEFIELD_UNDERMINED_FIELD);
                else if( mtx[i][j].getMineSignal()>0 )
                print(core_formatNumber(mtx[i][j].getMineSignal()));
            }
            else
            print(CONST_MINEFIELD_INVISIBLE_FIELD);
        }
        print(CONST_TAB);
        print(CONST_MINEFIELD_HEADER_W);
        print(CONST_TAB);
        println(core_formatNumber(i+1));
    }
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    for(int i=0; i<columns; i++)
    {
        print(CONST_MINEFIELD_HEADER_H);
        print(CONST_MINEFIELD_HEADER_H_OFFSET);
    }
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H_OFFSET);
    print(CONST_MINEFIELD_HEADER_H);
    print(CONST_MINEFIELD_HEADER_H);
    println(CONST_MINEFIELD_HEADER_H_OFFSET);
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_TAB);
    print(CONST_MINEFIELD_HEADER_W_OFFSET);
    print(CONST_TAB);
    print(CONST_MINEFIELD_HEADER_W);
    for(int i=0; i<columns; i++)
    {
        print(CONST_TAB);
        print(CONST_MINEFIELD_HEADER[i]);
    }
    print(CONST_TAB);
    println(CONST_MINEFIELD_HEADER_W);
    println();
    println();
}

/**
 * Update Minefield after "clicking" on a field with refreshing the visibled fields.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 */
void Minefield::update(int x, int y)
{
    // if the clicked field is valid and not visibled
    if(checkCoordinates(x,y) && !mtx[x][y].isVisibled())
    {
        // set it visibled
        mtx[x][y].setVisibled( true );
        // and if it is an empty field
        if( mtx[x][y].isEmpty() )
        {
            // go through the other empty fields
            for(int fieldPlace=FP_OVER; fieldPlace!=FP_RIGHT_OVER; fieldPlace++)
            {
                FieldPlace p = static_cast<FieldPlace>(fieldPlace);
                int r = getNextRow(p, x);
                int c = getNextColumn(p, y);
                // and update the minefield recursively
                update(r, c);
            }
        }
    }
}

/**
 * Checks if the field is undermined at the given coordinates.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @return true, if the field is undermined at the given coordinates
 */
bool Minefield::fieldIsUndermined(int x, int y)
{
    return mtx[x][y].isUndermined();
}

/**
 * Gets the field id from coordinates.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @return the field id from coordinates
 */
int Minefield::getFieldIdFromCoordinates(int x, int y)
{
    return rows == columns ? rows * x + (y + 1) : columns * x + (y + 1);
}

/**
 * Gets the x coordinate by field id.
 *
 * @param id the field id
 * @return the x coordinate by field id
 */
int Minefield::getXCoordinateByFieldId(int id)
{
    return rows == columns ? (id - 1) / rows : (id - 1) / columns;
}

/**
 * Gets the y coordinate by field id.
 *
 * @param id the field id
 * @return the y coordinate by field id
 */
int Minefield::getYCoordinateByFieldId(int id)
{
    return rows == columns ? (id - 1) % rows : (id - 1) % columns;
}

/**
 * Return an X coordinate for next step.
 *
 * @param fieldPlace the old field place
 * @param x the x coordinate
 * @return the next row
 */
int Minefield::getNextRow(FieldPlace fieldPlace, int x)
{
    switch(fieldPlace)
    {
        case FP_LEFT_OVER:
            return x - 1;
        case FP_OVER:
            return x - 1;
        case FP_RIGHT_OVER:
            return x - 1;
        case FP_LEFT:
            return x;
        case FP_RIGHT:
            return x;
        case FP_LEFT_UNDER:
            return x + 1;
        case FP_UNDER:
            return x + 1;
        case FP_RIGHT_UNDER:
            return x + 1;
        default:
            return -1;
    }
}

/**
 * Return an Y coordinate for next step.
 *
 * @param fieldPlace the old field place
 * @param y the y coordinate
 * @return the next column
 */
int Minefield::getNextColumn(FieldPlace fieldPlace, int y)
{
    switch(fieldPlace)
    {
        case FP_LEFT_OVER:
            return y - 1;
        case FP_OVER:
            return y;
        case FP_RIGHT_OVER:
            return y + 1;
        case FP_LEFT:
            return y - 1;
        case FP_RIGHT:
            return y + 1;
        case FP_LEFT_UNDER:
            return y - 1;
        case FP_UNDER:
            return y;
        case FP_RIGHT_UNDER:
            return y + 1;
        default:
            return -1;
    }
}

/**
 * Checks if the given coordinates are valid.
 *
 * @param x the x coordinate
 * @param y the y coordinate
 * @return true, if the coordinates are valid
 */
bool Minefield::checkCoordinates(int x, int y)
{
    // x ? [0;rows] && y ? [0;columns]
    return x>=0 && x<=rows && y>=0 && y<=columns;
}
