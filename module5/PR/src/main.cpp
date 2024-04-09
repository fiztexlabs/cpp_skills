#include <iostream>
#include <src/car.h>
#include <src/lorry.h>

int count(const Car &car)
{
    return car.count_;
}

int main()
{
    Car hyndai(
        "santa fe",
        4,
        199);

    std::cout << "car: " << hyndai.getName() << " has power " << hyndai.getPower() << " on " << hyndai.getCylinder() << " cylinders" << std::endl;

    Lorry belaz(
        "BelAZ",
        18,
        3500,
        180);

    // мы можем использовать функции getName getPower и getCylinder с объектом класса Lorry, т.к. Lorry является наследником класса Car,
    // для которого эти методы определены с ключевым словом public
    std::cout << "lorry: " << belaz.getName() << " has power " << belaz.getPower() << " on " << belaz.getCylinder() << " cylinders"
              << " and can carry " << belaz.getCarrying() << " tonnes" << std::endl;

    // тестируем count
    std::cout << "program show information about " << count(belaz) << " cars" << std::endl;

    return 0;
}