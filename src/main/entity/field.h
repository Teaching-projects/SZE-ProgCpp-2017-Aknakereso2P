/**
 * The Class Field.
 */
class Field
{
    private:
        int		id;
        int		coordinateX;
        int		coordinateY;
        int		mineSignal;
        bool	visibled;
        bool	flagged;

    public:
        /**
         * Instantiates a new field with given coordinates and default properties.
         */
        Field()
        {
            id = -1;
            coordinateX = -1;
            coordinateY = -1;
            mineSignal = 0;
            visibled = false;
            flagged = false;
        }

        /**
         * Instantiates a new field with given coordinates and default properties.
         *
         * @param i the id of the field
         * @param x the x coordinate
         * @param y the y coordinate
         */
        Field( int i, int x, int y )
        {
            id = i;
            coordinateX = x;
            coordinateY = y;
            mineSignal = 0;
            visibled = false;
            flagged = false;
        }

        /**
         * Increase the mine signal of the field by 1.
         */
        void countMineSignal()
        {
            ++mineSignal;
        }

        /**
         * Gets the id of the field.
         *
         * @return the id
         */
        int getId()
        {
            return id;
        }

        /**
         * Sets the id of the field.
         *
         * @param i the new id
         */
        void setId( int i )
        {
            id = i;
        }

        /**
         * Gets the x coordinate of the field.
         *
         * @return the coordinateX
         */
        int getCoordinateX()
        {
            return coordinateX;
        }

        /**
         * Sets the x coordinate of the field.
         *
         * @param x the new x coordinate
         */
        void setCoordinateX( int x )
        {
            coordinateX = x;
        }

        /**
         * Gets the y coordinate of the field.
         *
         * @return the coordinateY
         */
        int getCoordinateY()
        {
            return coordinateY;
        }

        /**
         * Sets the y coordinate of the field.
         *
         * @param y the new y coordinate
         */
        void setCoordinateY( int y )
        {
            coordinateY = y;
        }

        /**
         * Gets the mine signal of the field.
         *
         * @return the mineSignal
         */
        int getMineSignal()
        {
            return mineSignal;
        }

        /**
         * Sets the mine signal of the field.
         *
         * @param ms the new mine signal
         */
        void setMineSignal( int ms )
        {
            mineSignal = ms;
        }

        /**
         * Checks if this field is visibled or not.
         *
         * @return true, if this field is visibled
         */
        bool isVisibled()
        {
            return visibled;
        }

        /**
         * Sets this field to visibled or not.
         *
         * @param v the new visibled
         */
        void setVisibled( bool v )
        {
            visibled = v;
        }

        /**
         * Checks if this field is flagged or not.
         *
         * @return true, if this field is flagged
         */
        bool isFlagged()
        {
            return flagged;
        }

        /**
         * Sets this field to flagged or not.
         *
         * @param f the new flagged
         */
        void setFlagged( bool f )
        {
            flagged = f;
        }

        /**
         * Checks if this field is empty or not.
         *
         * @return true, if this field is empty
         */
        bool isEmpty()
        {
            return mineSignal == 0;
        }

        /**
         * Checks if this field is undermined or not.
         *
         * @return true, if this field is undermined
         */
        bool isUndermined()
        {
            return mineSignal == -1;
        }

};
