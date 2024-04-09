#pragma once
#include <src/car.h>
#include <string>

using namespace std;

/// @brief грузовик - подтип автомобилей
class Lorry : public Car
{
protected:
    /// @brief грузоподъемность
    int carrying_;

public:
    /// @brief конструктор по умолчанию
    Lorry()
        : Car()
    {
    }

    /// @brief конструктор с параметрами
    /// @param name 
    /// @param cylinder 
    /// @param power 
    /// @param carrying 
    Lorry(const string &name, int cylinder,
          int power, int carrying)
        : Car(name, cylinder, power), carrying_(carrying)
    {
    }

    Lorry(const Lorry &new_lorry)
        : Car(new_lorry.name_,
              new_lorry.cylinder_,
              new_lorry.power_),
          carrying_(new_lorry.carrying_)
    {
    }

    /// @brief назначить грузоподъемность
    /// @param carrying 
    void setCarrying(int carrying);

    /// @brief получить значение грузоподъемности
    /// @return 
    int getCarrying() const;

    /// @brief деструктор
    ~Lorry()
    {
    }
};