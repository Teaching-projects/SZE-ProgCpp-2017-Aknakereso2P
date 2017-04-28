#include "field_test.h"

/**
 * Instantiates a new Field test.
 */
FieldTest::FieldTest()
{
    Logger::getInstance()->logDebug("Running 'Field' entity tests");
}

/**
 * Runs the tests for Field entity.
 */
void FieldTest::run(void)
{
    Field field;
    field.setId(1);
    field.setCoordinateX(2);
    field.setCoordinateY(3);
    field.countMineSignal();
    Logger::getInstance()->logDebug("'Field' entity is valid");
}
