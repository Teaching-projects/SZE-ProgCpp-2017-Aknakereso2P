/**
 * The Class Minefield.
 */
class Minefield
{
    private:
        Field   	mtx[CONF_GAME_MINEFIELD_ROWS][CONF_GAME_MINEFIELD_COLUMNS];
        int         rows;
        int         columns;
        int         numOfMines;

    public:
        /**
         * Instantiates a new minefield matrix.
         */
        Minefield()
        {
            rows = CONF_GAME_MINEFIELD_ROWS;
            columns = CONF_GAME_MINEFIELD_COLUMNS;
            numOfMines = CONF_GAME_MINEFIELD_NUM_OF_MINES;
        }

        /**
         * Creates the minefield matrix.
         */
        void create()
        {
            int r, c, id, x, y;

            logger.logDebug("Creating minefield matrix");
            println("Generating fields");
            for( r = 0; r < rows; r++ )
            {
                for( c = 0; c < columns; c++ )
                {
                    id = getFieldIdFromCoordinates( r, c, rows, columns );
                    x = getXCoordinateByFieldId( id, rows, columns );
                    y = getYCoordinateByFieldId( id, rows, columns );
                    mtx[r][c] = Field( id, x, y );
                    if( (r+1)*(c+1) % ((int)((rows*columns)/10)) == 0 )
                    {
                        print(".");
                        core_sleep(100);
                    }
                    if( (r+1)*(c+1) == rows*columns )
                    {
                        println(".");
                        core_sleep(100);
                    }
                }
            }
            logger.logDebug("Successfully created minefield matrix");
            logger.logDebug("Matrix size: [" + core_formatNumber(r) + "][" + core_formatNumber(c) + "]");
        }

        /**
         * Undermine the minefield matrix.
         */
        void undermine()
        {
            int x, y, undermined;
            int indexOfGeneratedMines[numOfMines];
            int indexOfGeneratedMine, numOfGeneratedMines;

            logger.logDebug("Undermining minefield matrix");
            srand((unsigned int)time(0));
            undermined = -1;
            numOfGeneratedMines = 0;
            println("Generating undermined fields");
            while( numOfGeneratedMines < numOfMines )
            {
                x = (rand()%(rows - 1)) + 1;
                y = (rand()%(columns - 1)) + 1;
                indexOfGeneratedMine = getFieldIdFromCoordinates(x, y, rows, columns);
                if(!core_contains(indexOfGeneratedMine, indexOfGeneratedMines, numOfGeneratedMines))
                {
                    mtx[x][y].setMineSignal(undermined);
                    countMines(x,y);
                    indexOfGeneratedMines[numOfGeneratedMines++] = indexOfGeneratedMine;
                    if( numOfGeneratedMines % ((int)(numOfMines/10)) == 0 )
                    {
                        print(".");
                        core_sleep(250);
                    }
                    if( numOfGeneratedMines == numOfMines )
                    {
                        println();
                    }
                }
            }
            logger.logDebug("Successfully undermined minefield matrix");
            logger.logDebug("Number of undermined fields: " + core_formatNumber(numOfGeneratedMines));
        }

        /**
         * Looking for mines around the actual field at x, y coordinate and counts the mine signal.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         */
        void countMines( int x, int y )
        {
            for ( int fieldPlace = FP_OVER; fieldPlace != FP_RIGHT_OVER; fieldPlace++ )
            {
                FieldPlace place = static_cast<FieldPlace>(fieldPlace);
                int newPlace[2];
                newPlace[0] = getNextFieldXCoords( place, x, y );
                newPlace[1] = getNextFieldYCoords( place, x, y );
                try
                {
                    if( mtx[newPlace[0]][newPlace[1]].getMineSignal() >= 0 )
                    {
                        mtx[newPlace[0]][newPlace[1]].countMineSignal();
                    }
                }
                catch( ... )
                {
                    // index out of bound in the minefield matrix
                }
            }
        }

        /**
         * Shows the minefield.
         *
         * @param minefield the minefieldMatrix
         */
        void show()
        {
            println();
            print(" ");
            print(CONST_TAB);
            print(" ");
            print(CONST_TAB);
            print("|");
            for(int i=0; i<columns; i++)
            std::cout << CONST_TAB << CONST_MINEFIELD_HEADER[i];
            print(CONST_TAB);
            println("|");
            print(" ");
            print("-----");
            print("----");
            print("-");
            for(int i=0; i<columns; i++)
            print("-----");
            print("----");
            print("-");
            print("----");
            println("-----");
            for(int i=0; i<rows; i++)
            {
                print(CONST_TAB);
                if((i+1)<10)
                print(" ");
                print(core_formatNumber(i+1));
                print(CONST_TAB);
                print("|");
                for(int j=0; j<columns; j++)
                {
                    print(CONST_TAB);
                    if( mtx[i][j].isVisibled() )
                    {
                        if( mtx[i][j].getMineSignal()==0 )
                        print(" ");
                        else if( mtx[i][j].getMineSignal()==-1 )
                        print("*");
                        else if( mtx[i][j].getMineSignal()>0 )
                        print(core_formatNumber(mtx[i][j].getMineSignal()));
                    }
                    else
                    print("#");
                }
                print(CONST_TAB);
                print("|");
                print(CONST_TAB);
                println(core_formatNumber(i+1));
            }
            print(" ");
            print("-----");
            print("----");
            print("-");
            for(int i=0; i<columns; i++)
            print("-----");
            print("----");
            print("-");
            print("----");
            println("-----");
            print(" ");
            print(CONST_TAB);
            print(" ");
            print(CONST_TAB);
            print("|");
            for(int i=0; i<columns; i++)
            std::cout << CONST_TAB << CONST_MINEFIELD_HEADER[i];
            print(CONST_TAB);
            println("|");
            println();
        }

        /**
         * Update Minefield after "clicking" on a field with refreshing the visibled fields.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         */
        void updateMinefield( int x, int y )
        {
            try
            {
                if( !mtx[x][y].isVisibled() )
                {
                    // if the current field is not visible set it
                    mtx[x][y].setVisibled( true );
                    if( mtx[x][y].isEmpty() )
                    {
                        // if an empty field... go through the other empty fields
                        for ( int fieldPlace = FP_OVER; fieldPlace != FP_RIGHT_OVER; fieldPlace++ )
                        {
                            FieldPlace place = static_cast<FieldPlace>(fieldPlace);
                            int newPlace[2];
                            newPlace[0] = getNextFieldXCoords( place, x, y );
                            newPlace[1] = getNextFieldYCoords( place, x, y );
                            // update the minefield recursively
                            updateMinefield( newPlace[0], newPlace[1] );
                        }
                    }
                }
            }
            catch(...)
            {
                // index out of bound exception
            }
        }

        /**
         * Gets the field at x, y coordinates.
         *
         * @param x the x
         * @param y the y
         * @return the field
         */
        Field getField( int x, int y )
        {
            return mtx[x][y];
        }

        /**
         * Check the number of mines.
         *
         * @return the int
         */
        int checkNumberOfMines()
        {
            int numberOfMines = 0;
            for( int i = 0; i < rows; i++ )
            {
                for( int j = 0; j < columns; j++ )
                {
                    if( mtx[i][j].isUndermined() )
                    {
                        numberOfMines++;
                    }
                }
            }
            return numberOfMines;
        }

        /**
         * Checks if is all field visibled.
         *
         * @return true, if all field is visibled
         */
        bool checkAllFieldVisibled()
        {
            int rows = 0;
            int cols = 0;
            int visibledFields = 0;
            for( rows = 0; rows < rows; rows++ )
            {
                for( cols = 0; cols < columns; cols++ )
                {
                    if( mtx[rows][cols].isVisibled() )
                    {
                        visibledFields++;
                    }
                }
            }
            return visibledFields == rows * cols;
        }

    private:
        /**
         * Gets the field id from coordinates.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         * @param r the rows
         * @param c the columns
         * @return the field id from coordinates
         */
        int getFieldIdFromCoordinates( int x, int y, int r, int c )
        {
            return r == c ? r * x + (y + 1) : c * x + (y + 1);
        }

        /**
         * Gets the x coordinate by field id.
         *
         * @param id the field id
         * @param r the rows
         * @param c the columns
         * @return the x coordinate by field id
         */
        int getXCoordinateByFieldId( int id, int r, int c )
        {
            return r == c ? (id - 1) / r : (id - 1) / c;
        }

        /**
         * Gets the y coordinate by field id.
         *
         * @param id the field id
         * @param r the rows
         * @param c the cols
         * @return the y coordinate by field id
         */
        int getYCoordinateByFieldId( int id, int r, int c )
        {
            return r == c ? (id - 1) % r : (id - 1) % c;
        }

        /**
         * Return an X coordinate for next step.
         *
         * @param oldPlace the old place
         * @param x the x coordinate
         * @param y the y coordinate
         * @return the int[]
         */
        int getNextFieldXCoords( FieldPlace oldPlace, int x, int y )
        {
            switch( oldPlace )
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
                    break;
            }
            return 0;
        }

        /**
         * Return an Y coordinate for next step.
         *
         * @param oldPlace the old place
         * @param x the x coordinate
         * @param y the y coordinate
         * @return the int[]
         */
        int getNextFieldYCoords( FieldPlace oldPlace, int x, int y )
        {
            switch( oldPlace )
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
                    break;
            }
            return 0;
        }

};
