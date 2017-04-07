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
                    mtx[x][y].setMineSignal( -1 );
                    indexOfGeneratedMines[numOfGeneratedMines++] = indexOfGeneratedMine;
                }
            }
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
         * Update Minefield after "clicking" on a field with refreshing the visibled fields.
         *
         * @param x the x coordinate
         * @param y the y coordinate
         */
        void updateMinefield( int x, int y )
        {
            Field actField = getField( x, y );
            if( !actField.isFlagged() )
            {
                if( !actField.isVisibled() )
                {
                    // if the current field is not visible set it
                    actField.setVisibled( true );
                    if( actField.isEmpty() )
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
        bool checkAllFieldVisibled()
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
