#include <src/car.h>
#include "car.h"

void Car::setName(const string &name)
{
    name_ = name;
}

const string &Car::getName() const
{
    return name_;
}

void Car::setCylinder(int cylinder)
{
    cylinder_ = cylinder;
}

int Car::getCylinder() const
{
    return cylinder_;
}

void Car::setPower(int power)
{
    power_ = power;
}

int Car::getPower() const
{
    return power_;
}
