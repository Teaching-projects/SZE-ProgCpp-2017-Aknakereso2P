/**
 * The Class Minefield.
 */
class Minefield
{
    private:
        Field   	mtx[CONST_MINEFIELD_ROWS][CONST_MINEFIELD_COLUMNS];

        /**
         * Checks if the given value is in the given values array.
         *
         * @param value the value for search
         * @param values the array
         * @return true, if the value is in the given values array
         */
        bool contains( int value, int values[] )
        {
            for( int i = 0; values[i]; i++ )
            {
                if( values[i] == value )
                {
                    return true;
                }
            }
            return false;
        }

    public:
        /**
         * Instantiates a new minefield matrix.
         */
        Minefield()
        {
            create();
            undermine();
        }

        /**
         * Creates the minefield matrix.
         */
        void create()
        {
            for( int r = 0; r < CONST_MINEFIELD_ROWS; r++ )
            {
                for( int c = 0; c < CONST_MINEFIELD_COLUMNS; c++ )
                {
                    int id = getFieldIdFromCoordinates( r, c, CONST_MINEFIELD_ROWS, CONST_MINEFIELD_COLUMNS );
                    int x = getXCoordinateByFieldId( id, CONST_MINEFIELD_ROWS, CONST_MINEFIELD_COLUMNS );
                    int y = getYCoordinateByFieldId( id, CONST_MINEFIELD_ROWS, CONST_MINEFIELD_COLUMNS );
                    mtx[r][c] = Field( id, x, y );
                }
            }
        }

        /**
         * Undermine the minefield matrix.
         */
        void undermine()
        {
            int indexOfGeneratedMines[CONST_MINEFIELD_NUM_OF_MINES];
            int numOfGeneratedMines = 0;
            srand(time(0));
            while( numOfGeneratedMines < CONST_MINEFIELD_NUM_OF_MINES )
            {
                int x = (int)( 1 + ( rand() % CONST_MINEFIELD_ROWS ) );
                int y = (int)( 1 + ( rand() % CONST_MINEFIELD_COLUMNS ) );
                int indexOfGeneratedMine = getFieldIdFromCoordinates( x, y, CONST_MINEFIELD_ROWS, CONST_MINEFIELD_COLUMNS );
                if( !contains( indexOfGeneratedMine, indexOfGeneratedMines ) )
                {
                    try
                    {
                        mtx[x][y].setMineSignal( -1 );
                        searchMines( x, y );
                        indexOfGeneratedMines[numOfGeneratedMines++] = indexOfGeneratedMine;
                    }
                    catch(...)
                    {
                        // index out of bound in the minefield matrix
                    }
                }
            }
        }

        /**
         * Looking for mines around the actual field at x, y coordinate and counts the mine signal.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         */
        void searchMines( int x, int y )
        {
            for ( int fieldPlace = FP_OVER; fieldPlace != FP_RIGHT_OVER; fieldPlace++ )
            {
                FieldPlace place = static_cast<FieldPlace>(fieldPlace);
                int newPlace[2];
                int* _places = getNextFieldCoords( place, x, y );
                newPlace[0] = _places[0];
                newPlace[1] = _places[1];
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
         * Return an integer array, what contains the new x-y coordinates.
         *
         * @param oldPlace the old place
         * @param x the x coordinate
         * @param y the y coordinate
         * @return the int[]
         */
        int* getNextFieldCoords( FieldPlace oldPlace, int x, int y )
        {
            int result[2];
            switch( oldPlace )
            {
                case FP_LEFT_OVER:
                    result[0] = x - 1;
                    result[1] = y - 1;
                    break;
                case FP_OVER:
                    result[0] = x - 1;
                    result[1] = y;
                    break;
                case FP_RIGHT_OVER:
                    result[0] = x - 1;
                    result[1] = y + 1;
                    break;
                case FP_LEFT:
                    result[0] = x;
                    result[1] = y - 1;
                    break;
                case FP_RIGHT:
                    result[0] = x;
                    result[1] = y + 1;
                    break;
                case FP_LEFT_UNDER:
                    result[0] = x + 1;
                    result[1] = y - 1;
                    break;
                case FP_UNDER:
                    result[0] = x + 1;
                    result[1] = y;
                    break;
                case FP_RIGHT_UNDER:
                    result[0] = x + 1;
                    result[1] = y + 1;
                    break;
            }
            return result;
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
            for( int i = 0; i < CONST_MINEFIELD_ROWS; i++ )
            {
                for( int j = 0; j < CONST_MINEFIELD_COLUMNS; j++ )
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
        bool isAllFieldVisibled()
        {
            int rows = 0;
            int cols = 0;
            int visibledFields = 0;
            for( rows = 0; rows < CONST_MINEFIELD_ROWS; rows++ )
            {
                for( cols = 0; cols < CONST_MINEFIELD_COLUMNS; cols++ )
                {
                    if( mtx[rows][cols].isVisibled() )
                    {
                        visibledFields++;
                    }
                }
            }
            return visibledFields == rows * cols;
        }

};
