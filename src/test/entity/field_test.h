/**
 * Test for Field entity.
 */
void testField()
{
    std::cout << "Testing field entity" << std::endl;

    Field f (1, 2, 3);

    std::cout << "field.id: " << f.getId() << std::endl;
    std::cout << "field.x: " << f.getCoordinateX() << std::endl;
    std::cout << "field.y: " << f.getCoordinateY() << std::endl;
    std::cout << "field.mineSignal: " << f.getMineSignal() << std::endl;
    f.countMineSignal();
    std::cout << "field.mineSignal: " << f.getMineSignal() << std::endl;

    processEnd();
}
