#include <iostream>
#include "headers/entity/field.h"

using namespace std;

int main()
{
    Field f (1, 2, 3);

    cout << "field.id: " << f.getId() << endl;
    cout << "field.x: " << f.getCoordinateX() << endl;
    cout << "field.y: " << f.getCoordinateY() << endl;
    cout << "field.mineSignal: " << f.getMineSignal() << endl;
    f.countMineSignal();
    cout << "field.mineSignal: " << f.getMineSignal() << endl;

    return 0;
}
