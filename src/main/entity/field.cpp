#include "field.h"

/**
 * Instantiates a new field.
 */
Field::Field()
{
    id = -1;
    coordinateX = 0;
    coordinateY = 0;
    mineSignal = CONST_FIELD_EMPTY;
    visibled = false;
}

/**
 * Increase the mine signal of the field by 1.
 */
void Field::countMineSignal()
{
    ++mineSignal;
}

/**
 * Gets the id of the field.
 *
 * @return the id
 */
int Field::getId()
{
    return id;
}

/**
 * Sets the id of the field.
 *
 * @param i the new id
 */
void Field::setId( int i )
{
    id = i;
}

/**
 * Gets the x coordinate of the field.
 *
 * @return the coordinateX
 */
int Field::getCoordinateX()
{
    return coordinateX;
}

/**
 * Sets the x coordinate of the field.
 *
 * @param x the new x coordinate
 */
void Field::setCoordinateX( int x )
{
    coordinateX = x;
}

/**
 * Gets the y coordinate of the field.
 *
 * @return the coordinateY
 */
int Field::getCoordinateY()
{
    return coordinateY;
}

/**
 * Sets the y coordinate of the field.
 *
 * @param y the new y coordinate
 */
void Field::setCoordinateY( int y )
{
    coordinateY = y;
}

/**
 * Gets the mine signal of the field.
 *
 * @return the mineSignal
 */
int Field::getMineSignal()
{
    return mineSignal;
}

/**
 * Sets the mine signal of the field.
 *
 * @param ms the new mine signal
 */
void Field::setMineSignal( int ms )
{
    mineSignal = ms;
}

/**
 * Checks if this field is visibled or not.
 *
 * @return true, if this field is visibled
 */
bool Field::isVisibled()
{
    return visibled;
}

/**
 * Sets this field to visibled or not.
 *
 * @param v the new visibled
 */
void Field::setVisibled( bool v )
{
    visibled = v;
}

/**
 * Checks if this field is empty or not.
 *
 * @return true, if this field is empty
 */
bool Field::isEmpty()
{
    return mineSignal == 0;
}

/**
 * Checks if this field is undermined or not.
 *
 * @return true, if this field is undermined
 */
bool Field::isUndermined()
{
    return mineSignal == -1;
}
