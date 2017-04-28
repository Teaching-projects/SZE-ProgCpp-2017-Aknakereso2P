#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include "../util/consts.h"

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

    public:
        Field();
        Field(int i, int x, int y);
        void countMineSignal(void);
        int getId(void);
        void setId(int i);
        int getCoordinateX(void);
        void setCoordinateX(int x);
        int getCoordinateY(void);
        void setCoordinateY(int y);
        int getMineSignal(void);
        void setMineSignal(int ms);
        bool isVisibled(void);
        void setVisibled(bool v);
        bool isEmpty(void);
        bool isUndermined(void);
};

#endif // FIELD_H_INCLUDED
